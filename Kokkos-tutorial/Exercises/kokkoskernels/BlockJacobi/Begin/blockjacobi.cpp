/// Kokkos headers
#include "Kokkos_Core.hpp"
#include "impl/Kokkos_Timer.hpp"
#include "Kokkos_Random.hpp"

/// KokkosKernels headers
#include "KokkosBatched_Util.hpp"

#include "Kokkos_ArithTraits.hpp"
#include "KokkosBatched_Util.hpp"
#include "KokkosBatched_Copy_Decl.hpp"
#include "KokkosBatched_Copy_Impl.hpp"
#include "KokkosBatched_SetIdentity_Decl.hpp"
#include "KokkosBatched_SetIdentity_Impl.hpp"
#include "KokkosBatched_Gemv_Decl.hpp"
#include "KokkosBatched_Gemv_Team_Impl.hpp"
#include "KokkosBatched_Trsm_Decl.hpp"
#include "KokkosBatched_Trsm_Team_Impl.hpp"
#include "KokkosBatched_LU_Decl.hpp"
#include "KokkosBatched_LU_Team_Impl.hpp"

/// cuda profile
#if defined(KOKKOS_ENABLE_CUDA)
#include "cuda_profiler_api.h"
#endif

using exec_space =  Kokkos::DefaultExecutionSpace;
using memory_space = typename exec_space::memory_space;
using host_space = Kokkos::DefaultHostExecutionSpace;

using value_type = double;
using policy_type = Kokkos::TeamPolicy<exec_space>;
using member_type = typename policy_type::member_type;

using namespace KokkosBatched;

template<typename ManyMatrixType,
	 typename ManyVectorType>
void applyBlockJacobi(const ManyMatrixType &A,
                      const ManyVectorType &x,
                      const ManyVectorType &b) {
  policy_type policy(A.extent(0), Kokkos::AUTO());
  Kokkos::parallel_for
    ("apply-block-jacobi",
     policy, KOKKOS_LAMBDA(const member_type &member) {
      const int i = member.league_rank();
      const value_type one(1), zero(0);
      auto AA = Kokkos::subview(A, i, Kokkos::ALL(), Kokkos::ALL());
      auto xx = Kokkos::subview(x, i, Kokkos::ALL());
      auto bb = Kokkos::subview(b, i, Kokkos::ALL());
      TeamGemv<member_type,
               Trans::NoTranspose,
               Algo::Level2::Unblocked>
        ::invoke(member, one, AA, bb, zero, xx);
    });
}

template<typename ManyMatrixType,
	 typename ManyVectorType>
value_type computeResidual(const ManyMatrixType &A,
			   const ManyVectorType &x,
			   const ManyVectorType &b,
			   const ManyVectorType &r) {
  /// compute residual
  value_type residual(0);
  {
    policy_type policy(A.extent(0), Kokkos::AUTO());	
    Kokkos::deep_copy(r, b);
    Kokkos::parallel_reduce
      ("compute-residual",
       policy, KOKKOS_LAMBDA(const member_type &member, value_type &update) {
	const int i = member.league_rank();
	const value_type one(1);
	auto AA = Kokkos::subview(A, i, Kokkos::ALL(), Kokkos::ALL());
	auto xx = Kokkos::subview(x, i, Kokkos::ALL());
	auto rr = Kokkos::subview(r, i, Kokkos::ALL());
	
	TeamGemv<member_type,
		 Trans::NoTranspose,
		 Algo::Level2::Unblocked>
	  ::invoke(member, -one, AA, xx, one, rr);

        value_type sum(0);
	Kokkos::parallel_reduce
	  (Kokkos::TeamThreadRange(member, rr.extent(0)),
	   [&](const int &k, value_type &lsum) {
            lsum += Kokkos::ArithTraits<value_type>::abs(rr(k));
          }, sum);
        Kokkos::single(Kokkos::PerTeam(member), [&]() {
            update += sum;
          });
      }, residual);
  }
  return residual;
}

int main(int argc, char* argv[]) {
  Kokkos::initialize(argc, argv);
  {
#if defined(KOKKOS_ENABLE_CUDA)
    cudaProfilerStop();
#endif
    ///Kokkos::print_configuration(std::cout);

    Kokkos::Impl::Timer timer;

    ///
    /// input arguments parsing
    ///
    int N = 128*128; /// # of problems (batch size)
    int Blk = 5;     /// block dimension
    int Task = 0;    /// test both , 1 - task 1 only, 2 - task 2 only
    int TeamSize = 0;/// 0 - AUTO, otherwise 
    for (int i=1;i<argc;++i) {
      const std::string& token = argv[i];
      if (token == std::string("-N")) N = std::atoi(argv[++i]);
      if (token == std::string("-B")) Blk = std::atoi(argv[++i]);
      if (token == std::string("-Task")) Task = std::atoi(argv[++i]);
      if (token == std::string("-TeamSize")) TeamSize = std::atoi(argv[++i]);
    }
    printf(" :::: Testing (N = %d, Blk = %d, TeamSize = %d (0 is AUTO))\n", N, Blk, TeamSize);


    ///
    /// Problem container: rank-3 array
    ///
    /// A - multiple block matrices representing block diagonals
    /// T - temporal block matrices to store its LU factors
    /// x - solution vector
    /// b - right hand side vector
    ///
    Kokkos::View<value_type***,Kokkos::LayoutRight,exec_space> A("block diagonals", N, Blk, Blk);
    Kokkos::View<value_type***,Kokkos::LayoutRight,exec_space> T("temporal block diagonals", N, Blk, Blk);    
    Kokkos::View<value_type**,Kokkos::LayoutRight,exec_space> x("x", N, Blk);
    Kokkos::View<value_type**,Kokkos::LayoutRight,exec_space> b("b", N, Blk);

    /// copy of A to check residual
    Kokkos::View<value_type***,Kokkos::LayoutRight,exec_space> Acopy("Acopy",
								     A.extent(0),
								     A.extent(1),
								     A.extent(2));

    /// residual vector
    Kokkos::View<value_type**,Kokkos::LayoutRight,exec_space> r("r",
								b.extent(0), 
								b.extent(1));

    /// The block diagonal matrices are assumed to be extracted from a block sparse matrix.
    /// Here we set the blocks with random values
    Kokkos::Random_XorShift64_Pool<exec_space> random(13245);
    Kokkos::fill_random(A, random, value_type(1));
    Kokkos::fill_random(b, random, value_type(1));

    Kokkos::deep_copy(Acopy, A);

    ///
    /// Objective :
    ///    - Construct the inverse of A(i,:,:) for all i.
    ///    - Solve the equation using matrix vector multiplication. 
    
    /// Task 1. Use the so-called standard batch interface
    ///    parallel_for(factorize)
    ///    parallel_For(set identity matrix)
    ///    parallel_for(solve lower triangular)
    ///    parallel_for(solve upper triangular)
    ///    parallel_for(matrix vector multiplication)

    if (Task == 0 || Task == 1) {
      Kokkos::deep_copy(A, Acopy);
      
      /// construction of block jacobi using batched blas interface
      /// each parallel for is a batch function
      {
#if defined(KOKKOS_ENABLE_CUDA)
        cudaProfilerStart();
#endif
        policy_type policy(A.extent(0), Kokkos::AUTO());
        if (TeamSize != 0) 
          policy = policy_type(A.extent(0), TeamSize);
        timer.reset();
	Kokkos::parallel_for
	  ("task1.factorize",
	   policy, KOKKOS_LAMBDA(const member_type &member) {
	    const int i = member.league_rank();
	    auto AA = Kokkos::subview(A, i, Kokkos::ALL(), Kokkos::ALL());
	    TeamLU<member_type,Algo::Level3::Unblocked>::invoke(member,AA);
	  });
	Kokkos::deep_copy(T, A);
	Kokkos::parallel_for
	  ("task1.set-identity",
	   policy, KOKKOS_LAMBDA(const member_type &member) {
	    const int i = member.league_rank();
	    auto AA = Kokkos::subview(A, i, Kokkos::ALL(), Kokkos::ALL());	  
	    TeamSetIdentity<member_type>::invoke(member, AA);
	  });
	Kokkos::fence();      
	Kokkos::parallel_for
	  ("task1.solve-lower-triangular",
	   policy, KOKKOS_LAMBDA(const member_type &member) {
	    const int i = member.league_rank();
	    const value_type one(1);
	    auto AA = Kokkos::subview(A, i, Kokkos::ALL(), Kokkos::ALL());
	    auto TT = Kokkos::subview(T, i, Kokkos::ALL(), Kokkos::ALL());
	    TeamTrsm<member_type,
		     Side::Left,Uplo::Lower,Trans::NoTranspose,Diag::Unit,
		     Algo::Level3::Unblocked>
	      ::invoke(member, one, TT, AA);
	  });
	Kokkos::fence();      
	Kokkos::parallel_for
	  ("task1.solve-upper-triangular",
	   policy, KOKKOS_LAMBDA(const member_type &member) {
	    const int i = member.league_rank();
	    const value_type one(1);
	    auto AA = Kokkos::subview(A, i, Kokkos::ALL(), Kokkos::ALL());
	    auto TT = Kokkos::subview(T, i, Kokkos::ALL(), Kokkos::ALL());
	    TeamTrsm<member_type,
		     Side::Left,Uplo::Upper,Trans::NoTranspose,Diag::NonUnit,
		     Algo::Level3::Unblocked>
	      ::invoke(member, one, TT, AA);
	  });      
	Kokkos::fence();
	const double t = timer.seconds();
	printf("task 1: construction of jacobi time = %f , # of constructions per min = %.0f \n", t, 1.0/t*60);
#if defined(KOKKOS_ENABLE_CUDA) 
      cudaProfilerStop();
#endif      
      }
      
      /// apply block jacobi
      {
	timer.reset();
        applyBlockJacobi(A, x, b);
	const double t = timer.seconds();
	///printf("task 1: application of jacobi time = %f , # of applications per min = %.0f \n", t, 1.0/t*60);	
      }

      /// check residual
      {
	const double residual = computeResidual(Acopy, x, b, r);
	printf("task 1: residual = %f\n", residual);
      }
    }
    
    /// Task 2. Compose a new batch function using kokkos batched team-level interface
    ///    parallel_for(LU, set identity, solve lower/upper triangular)
    ///    parallel_for(matrix vector multiplication)

    if (Task == 0 || Task == 2) {
      Kokkos::deep_copy(A, Acopy);
      
      /// construction of block jacobi using batched blas interface
      /// each parallel for is a batch function
      {
#if defined(KOKKOS_ENABLE_CUDA)
      cudaProfilerStart();
#endif
	policy_type policy(A.extent(0), Kokkos::AUTO());	
        if (TeamSize != 0) 
          policy = policy_type(A.extent(0), TeamSize);
	timer.reset();
	Kokkos::parallel_for
	  ("task2.factorize-invert",
	   policy, KOKKOS_LAMBDA(const member_type &member) {
	    const value_type one(1);
	    const int i = member.league_rank();
	    auto AA = Kokkos::subview(A, i, Kokkos::ALL(), Kokkos::ALL());
	    auto TT = Kokkos::subview(T, i, Kokkos::ALL(), Kokkos::ALL());
	    
            /// EXERCISE: complete this functor
	  });
	Kokkos::fence();
	const double t = timer.seconds();
	printf("task 2: construction of jacobi time = %f , # of constructions per min = %.0f \n", t, 1.0/t*60);
#if defined(KOKKOS_ENABLE_CUDA) 
      cudaProfilerStop();
#endif      
      }
      
      /// apply block jacobi
      {
	timer.reset();
        applyBlockJacobi(A, x, b);
	const double t = timer.seconds();
	///printf("task 2: application of jacobi time = %f , # of applications per min = %.0f \n", t, 1.0/t*60);	
      }

      /// check residual
      {
	const double residual = computeResidual(Acopy, x, b, r);
	printf("task 2: residual = %f\n", residual);
      }
    }

  }
  Kokkos::finalize();

  return 0;
}


