/*
//@HEADER
// ************************************************************************
//
//                        Kokkos v. 2.0
//              Copyright (2014) Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact  H. Carter Edwards (hcedwar@sandia.gov)
//
// ************************************************************************
//@HEADER
*/

#include <Kokkos_Core.hpp>
#include <impl/Kokkos_Error.hpp>
#include <cctype>
#include <cstring>
#include <iostream>
#include <cstdlib>

//----------------------------------------------------------------------------

namespace Kokkos {
namespace Impl {
namespace {

bool is_unsigned_int(const char* str)
{
  const size_t len = strlen (str);
  for (size_t i = 0; i < len; ++i) {
    if (! isdigit (str[i])) {
      return false;
    }
  }
  return true;
}

void initialize_internal(const InitArguments& args)
{
// This is an experimental setting
// For KNL in Flat mode this variable should be set, so that
// memkind allocates high bandwidth memory correctly.
#ifdef KOKKOS_ENABLE_HBWSPACE
setenv("MEMKIND_HBW_NODES", "1", 0);
#endif

  // Protect declarations, to prevent "unused variable" warnings.
#if defined( KOKKOS_ENABLE_OPENMP ) || defined( KOKKOS_ENABLE_THREADS )
  const int num_threads = args.num_threads;
  const int use_numa = args.num_numa;
#endif // defined( KOKKOS_ENABLE_OPENMP ) || defined( KOKKOS_ENABLE_THREADS )
#if defined( KOKKOS_ENABLE_CUDA )
  const int use_gpu = args.device_id;
#endif // defined( KOKKOS_ENABLE_CUDA )

#if defined( KOKKOS_ENABLE_OPENMP )
  if( std::is_same< Kokkos::OpenMP , Kokkos::DefaultExecutionSpace >::value ||
      std::is_same< Kokkos::OpenMP , Kokkos::HostSpace::execution_space >::value ) {
    if(num_threads>0) {
      if(use_numa>0) {
        Kokkos::OpenMP::initialize(num_threads,use_numa);
      }
      else {
        Kokkos::OpenMP::initialize(num_threads);
      }
    } else {
      Kokkos::OpenMP::initialize();
    }
    //std::cout << "Kokkos::initialize() fyi: OpenMP enabled and initialized" << std::endl ;
  }
  else {
    //std::cout << "Kokkos::initialize() fyi: OpenMP enabled but not initialized" << std::endl ;
  }
#endif

#if defined( KOKKOS_ENABLE_THREADS )
  if( std::is_same< Kokkos::Threads , Kokkos::DefaultExecutionSpace >::value ||
      std::is_same< Kokkos::Threads , Kokkos::HostSpace::execution_space >::value ) {
    if(num_threads>0) {
      if(use_numa>0) {
        Kokkos::Threads::initialize(num_threads,use_numa);
      }
      else {
        Kokkos::Threads::initialize(num_threads);
      }
    } else {
      Kokkos::Threads::initialize();
    }
    //std::cout << "Kokkos::initialize() fyi: Pthread enabled and initialized" << std::endl ;
  }
  else {
    //std::cout << "Kokkos::initialize() fyi: Pthread enabled but not initialized" << std::endl ;
  }
#endif

#if defined( KOKKOS_ENABLE_SERIAL )
  // Prevent "unused variable" warning for 'args' input struct.  If
  // Serial::initialize() ever needs to take arguments from the input
  // struct, you may remove this line of code.
  (void) args;

  if( std::is_same< Kokkos::Serial , Kokkos::DefaultExecutionSpace >::value ||
      std::is_same< Kokkos::Serial , Kokkos::HostSpace::execution_space >::value ) {
    Kokkos::Serial::initialize();
  }
#endif

#if defined( KOKKOS_ENABLE_CUDA )
  if( std::is_same< Kokkos::Cuda , Kokkos::DefaultExecutionSpace >::value || 0 < use_gpu ) {
    if (use_gpu > -1) {
      Kokkos::Cuda::initialize( Kokkos::Cuda::SelectDevice( use_gpu ) );
    }
    else {
      Kokkos::Cuda::initialize();
    }
    //std::cout << "Kokkos::initialize() fyi: Cuda enabled and initialized" << std::endl ;
  }
#endif

#if defined(KOKKOS_ENABLE_PROFILING)
    Kokkos::Profiling::initialize();
#endif
}

void finalize_internal( const bool all_spaces = false )
{

#if defined(KOKKOS_ENABLE_PROFILING)
    Kokkos::Profiling::finalize();
#endif

#if defined( KOKKOS_ENABLE_CUDA )
  if( std::is_same< Kokkos::Cuda , Kokkos::DefaultExecutionSpace >::value || all_spaces ) {
    if(Kokkos::Cuda::is_initialized())
      Kokkos::Cuda::finalize();
  }
#endif

#if defined( KOKKOS_ENABLE_OPENMP )
  if( std::is_same< Kokkos::OpenMP , Kokkos::DefaultExecutionSpace >::value ||
      std::is_same< Kokkos::OpenMP , Kokkos::HostSpace::execution_space >::value ||
      all_spaces ) {
    if(Kokkos::OpenMP::is_initialized())
      Kokkos::OpenMP::finalize();
  }
#endif

#if defined( KOKKOS_ENABLE_THREADS )
  if( std::is_same< Kokkos::Threads , Kokkos::DefaultExecutionSpace >::value ||
      std::is_same< Kokkos::Threads , Kokkos::HostSpace::execution_space >::value ||
      all_spaces ) {
    if(Kokkos::Threads::is_initialized())
      Kokkos::Threads::finalize();
  }
#endif

#if defined( KOKKOS_ENABLE_SERIAL )
  if( std::is_same< Kokkos::Serial , Kokkos::DefaultExecutionSpace >::value ||
      std::is_same< Kokkos::Serial , Kokkos::HostSpace::execution_space >::value ||
      all_spaces ) {
    if(Kokkos::Serial::is_initialized())
      Kokkos::Serial::finalize();
  }
#endif
}

void fence_internal()
{

#if defined( KOKKOS_ENABLE_CUDA )
  if( std::is_same< Kokkos::Cuda , Kokkos::DefaultExecutionSpace >::value ) {
    Kokkos::Cuda::fence();
  }
#endif

#if defined( KOKKOS_ENABLE_OPENMP )
  if( std::is_same< Kokkos::OpenMP , Kokkos::DefaultExecutionSpace >::value ||
      std::is_same< Kokkos::OpenMP , Kokkos::HostSpace::execution_space >::value ) {
    Kokkos::OpenMP::fence();
  }
#endif

#if defined( KOKKOS_ENABLE_THREADS )
  if( std::is_same< Kokkos::Threads , Kokkos::DefaultExecutionSpace >::value ||
      std::is_same< Kokkos::Threads , Kokkos::HostSpace::execution_space >::value ) {
    Kokkos::Threads::fence();
  }
#endif

#if defined( KOKKOS_ENABLE_SERIAL )
  if( std::is_same< Kokkos::Serial , Kokkos::DefaultExecutionSpace >::value ||
      std::is_same< Kokkos::Serial , Kokkos::HostSpace::execution_space >::value ) {
    Kokkos::Serial::fence();
  }
#endif

}

} // namespace
} // namespace Impl
} // namespace Kokkos

//----------------------------------------------------------------------------

namespace Kokkos {

void initialize(int& narg, char* arg[])
{
    int num_threads = -1;
    int numa = -1;
    int device = -1;

    int kokkos_threads_found = 0;
    int kokkos_numa_found = 0;
    int kokkos_device_found = 0;
    int kokkos_ndevices_found = 0;

    int iarg = 0;

    while (iarg < narg) {
      if ((strncmp(arg[iarg],"--kokkos-threads",16) == 0) || (strncmp(arg[iarg],"--threads",9) == 0)) {
        //Find the number of threads (expecting --threads=XX)
        if (!((strncmp(arg[iarg],"--kokkos-threads=",17) == 0) || (strncmp(arg[iarg],"--threads=",10) == 0)))
          Impl::throw_runtime_exception("Error: expecting an '=INT' after command line argument '--threads/--kokkos-threads'. Raised by Kokkos::initialize(int narg, char* argc[]).");

        char* number =  strchr(arg[iarg],'=')+1;

        if(!Impl::is_unsigned_int(number) || (strlen(number)==0))
          Impl::throw_runtime_exception("Error: expecting an '=INT' after command line argument '--threads/--kokkos-threads'. Raised by Kokkos::initialize(int narg, char* argc[]).");

        if((strncmp(arg[iarg],"--kokkos-threads",16) == 0) || !kokkos_threads_found)
          num_threads = atoi(number);

        //Remove the --kokkos-threads argument from the list but leave --threads
        if(strncmp(arg[iarg],"--kokkos-threads",16) == 0) {
          for(int k=iarg;k<narg-1;k++) {
            arg[k] = arg[k+1];
          }
          kokkos_threads_found=1;
          narg--;
        } else {
          iarg++;
        }
      } else if ((strncmp(arg[iarg],"--kokkos-numa",13) == 0) || (strncmp(arg[iarg],"--numa",6) == 0)) {
        //Find the number of numa (expecting --numa=XX)
        if (!((strncmp(arg[iarg],"--kokkos-numa=",14) == 0) || (strncmp(arg[iarg],"--numa=",7) == 0)))
          Impl::throw_runtime_exception("Error: expecting an '=INT' after command line argument '--numa/--kokkos-numa'. Raised by Kokkos::initialize(int narg, char* argc[]).");

        char* number =  strchr(arg[iarg],'=')+1;

        if(!Impl::is_unsigned_int(number) || (strlen(number)==0))
          Impl::throw_runtime_exception("Error: expecting an '=INT' after command line argument '--numa/--kokkos-numa'. Raised by Kokkos::initialize(int narg, char* argc[]).");

        if((strncmp(arg[iarg],"--kokkos-numa",13) == 0) || !kokkos_numa_found)
          numa = atoi(number);

        //Remove the --kokkos-numa argument from the list but leave --numa
        if(strncmp(arg[iarg],"--kokkos-numa",13) == 0) {
          for(int k=iarg;k<narg-1;k++) {
            arg[k] = arg[k+1];
          }
          kokkos_numa_found=1;
          narg--;
        } else {
          iarg++;
        }
      } else if ((strncmp(arg[iarg],"--kokkos-device",15) == 0) || (strncmp(arg[iarg],"--device",8) == 0)) {
        //Find the number of device (expecting --device=XX)
        if (!((strncmp(arg[iarg],"--kokkos-device=",16) == 0) || (strncmp(arg[iarg],"--device=",9) == 0)))
          Impl::throw_runtime_exception("Error: expecting an '=INT' after command line argument '--device/--kokkos-device'. Raised by Kokkos::initialize(int narg, char* argc[]).");

        char* number =  strchr(arg[iarg],'=')+1;

        if(!Impl::is_unsigned_int(number) || (strlen(number)==0))
          Impl::throw_runtime_exception("Error: expecting an '=INT' after command line argument '--device/--kokkos-device'. Raised by Kokkos::initialize(int narg, char* argc[]).");

        if((strncmp(arg[iarg],"--kokkos-device",15) == 0) || !kokkos_device_found)
          device = atoi(number);

        //Remove the --kokkos-device argument from the list but leave --device
        if(strncmp(arg[iarg],"--kokkos-device",15) == 0) {
          for(int k=iarg;k<narg-1;k++) {
            arg[k] = arg[k+1];
          }
          kokkos_device_found=1;
          narg--;
        } else {
          iarg++;
        }
      } else if ((strncmp(arg[iarg],"--kokkos-ndevices",17) == 0) || (strncmp(arg[iarg],"--ndevices",10) == 0)) {

        //Find the number of device (expecting --device=XX)
        if (!((strncmp(arg[iarg],"--kokkos-ndevices=",18) == 0) || (strncmp(arg[iarg],"--ndevices=",11) == 0)))
          Impl::throw_runtime_exception("Error: expecting an '=INT[,INT]' after command line argument '--ndevices/--kokkos-ndevices'. Raised by Kokkos::initialize(int narg, char* argc[]).");

        int ndevices=-1;
        int skip_device = 9999;

        char* num1 = strchr(arg[iarg],'=')+1;
        char* num2 = strpbrk(num1,",");
        int num1_len = num2==NULL?strlen(num1):num2-num1;
        char* num1_only = new char[num1_len+1];
        strncpy(num1_only,num1,num1_len);
        num1_only[num1_len]=0;

        if(!Impl::is_unsigned_int(num1_only) || (strlen(num1_only)==0)) {
          Impl::throw_runtime_exception("Error: expecting an integer number after command line argument '--kokkos-ndevices'. Raised by Kokkos::initialize(int narg, char* argc[]).");
        }
        if((strncmp(arg[iarg],"--kokkos-ndevices",17) == 0) || !kokkos_ndevices_found)
          ndevices = atoi(num1_only);

        if( num2 != NULL ) {
          if(( !Impl::is_unsigned_int(num2+1) ) || (strlen(num2)==1) )
            Impl::throw_runtime_exception("Error: expecting an integer number after command line argument '--kokkos-ndevices=XX,'. Raised by Kokkos::initialize(int narg, char* argc[]).");

          if((strncmp(arg[iarg],"--kokkos-ndevices",17) == 0) || !kokkos_ndevices_found)
            skip_device = atoi(num2+1);
        }

        if((strncmp(arg[iarg],"--kokkos-ndevices",17) == 0) || !kokkos_ndevices_found) {
          char *str;
          //if ((str = getenv("SLURM_LOCALID"))) {
          //  int local_rank = atoi(str);
          //  device = local_rank % ndevices;
          //  if (device >= skip_device) device++;
          //}
          if ((str = getenv("MV2_COMM_WORLD_LOCAL_RANK"))) {
            int local_rank = atoi(str);
            device = local_rank % ndevices;
            if (device >= skip_device) device++;
          }
          if ((str = getenv("OMPI_COMM_WORLD_LOCAL_RANK"))) {
            int local_rank = atoi(str);
            device = local_rank % ndevices;
            if (device >= skip_device) device++;
          }
          if(device==-1) {
            device = 0;
            if (device >= skip_device) device++;
          }
        }

        //Remove the --kokkos-ndevices argument from the list but leave --ndevices
        if(strncmp(arg[iarg],"--kokkos-ndevices",17) == 0) {
          for(int k=iarg;k<narg-1;k++) {
            arg[k] = arg[k+1];
          }
          kokkos_ndevices_found=1;
          narg--;
        } else {
          iarg++;
        }
      } else if ((strcmp(arg[iarg],"--kokkos-help") == 0) || (strcmp(arg[iarg],"--help") == 0)) {
         std::cout << std::endl;
         std::cout << "--------------------------------------------------------------------------------" << std::endl;
         std::cout << "-------------Kokkos command line arguments--------------------------------------" << std::endl;
         std::cout << "--------------------------------------------------------------------------------" << std::endl;
         std::cout << "The following arguments exist also without prefix 'kokkos' (e.g. --help)." << std::endl;
         std::cout << "The prefixed arguments will be removed from the list by Kokkos::initialize()," << std::endl;
         std::cout << "the non-prefixed ones are not removed. Prefixed versions take precedence over " << std::endl;
         std::cout << "non prefixed ones, and the last occurence of an argument overwrites prior" << std::endl;
         std::cout << "settings." << std::endl;
         std::cout << std::endl;
         std::cout << "--kokkos-help               : print this message" << std::endl;
         std::cout << "--kokkos-threads=INT        : specify total number of threads or" << std::endl;
         std::cout << "                              number of threads per NUMA region if " << std::endl;
         std::cout << "                              used in conjunction with '--numa' option. " << std::endl;
         std::cout << "--kokkos-numa=INT           : specify number of NUMA regions used by process." << std::endl;
         std::cout << "--kokkos-device=INT         : specify device id to be used by Kokkos. " << std::endl;
         std::cout << "--kokkos-ndevices=INT[,INT] : used when running MPI jobs. Specify number of" << std::endl;
         std::cout << "                              devices per node to be used. Process to device" << std::endl;
         std::cout << "                              mapping happens by obtaining the local MPI rank" << std::endl;
         std::cout << "                              and assigning devices round-robin. The optional" << std::endl;
         std::cout << "                              second argument allows for an existing device" << std::endl;
         std::cout << "                              to be ignored. This is most useful on workstations" << std::endl;
         std::cout << "                              with multiple GPUs of which one is used to drive" << std::endl;
         std::cout << "                              screen output." << std::endl;
         std::cout << std::endl;
         std::cout << "--------------------------------------------------------------------------------" << std::endl;
         std::cout << std::endl;

         //Remove the --kokkos-help argument from the list but leave --ndevices
         if(strcmp(arg[iarg],"--kokkos-help") == 0) {
           for(int k=iarg;k<narg-1;k++) {
             arg[k] = arg[k+1];
           }
           narg--;
         } else {
           iarg++;
         }
      } else
      iarg++;
    }

    InitArguments arguments;
    arguments.num_threads = num_threads;
    arguments.num_numa = numa;
    arguments.device_id = device;
    Impl::initialize_internal(arguments);
}

void initialize(const InitArguments& arguments) {
  Impl::initialize_internal(arguments);
}

void finalize()
{
  Impl::finalize_internal();
}

void finalize_all()
{
  enum { all_spaces = true };
  Impl::finalize_internal( all_spaces );
}

void fence()
{
  Impl::fence_internal();
}

void print_configuration( std::ostream & out , const bool detail )
{
  std::ostringstream msg;

  msg << "Compiler:" << std::endl;
#ifdef KOKKOS_COMPILER_APPLECC
  msg << "  KOKKOS_COMPILER_APPLECC: " << KOKKOS_COMPILER_APPLECC << std::endl;
#endif
#ifdef KOKKOS_COMPILER_CLANG
  msg << "  KOKKOS_COMPILER_CLANG: " << KOKKOS_COMPILER_CLANG << std::endl;
#endif
#ifdef KOKKOS_COMPILER_CRAYC
  msg << "  KOKKOS_COMPILER_CRAYC: " << KOKKOS_COMPILER_CRAYC << std::endl;
#endif
#ifdef KOKKOS_COMPILER_GNU
  msg << "  KOKKOS_COMPILER_GNU: " << KOKKOS_COMPILER_GNU << std::endl;
#endif
#ifdef KOKKOS_COMPILER_IBM
  msg << "  KOKKOS_COMPILER_IBM: " << KOKKOS_COMPILER_IBM << std::endl;
#endif
#ifdef KOKKOS_COMPILER_INTEL
  msg << "  KOKKOS_COMPILER_INTEL: " << KOKKOS_COMPILER_INTEL << std::endl;
#endif
#ifdef KOKKOS_COMPILER_NVCC
  msg << "  KOKKOS_COMPILER_NVCC: " << KOKKOS_COMPILER_NVCC << std::endl;
#endif
#ifdef KOKKOS_COMPILER_PGI
  msg << "  KOKKOS_COMPILER_PGI: " << KOKKOS_COMPILER_PGI << std::endl;
#endif


  msg << "Architecture:" << std::endl;
#ifdef KOKKOS_ENABLE_ISA_KNC
  msg << "  KOKKOS_ENABLE_ISA_KNC: yes" << std::endl;
#else
  msg << "  KOKKOS_ENABLE_ISA_KNC: no" << std::endl;
#endif
#ifdef KOKKOS_ENABLE_ISA_POWERPCLE
  msg << "  KOKKOS_ENABLE_ISA_POWERPCLE: yes" << std::endl;
#else
  msg << "  KOKKOS_ENABLE_ISA_POWERPCLE: no" << std::endl;
#endif
#ifdef KOKKOS_ENABLE_ISA_X86_64
  msg << "  KOKKOS_ENABLE_ISA_X86_64: yes" << std::endl;
#else
  msg << "  KOKKOS_ENABLE_ISA_X86_64: no" << std::endl;
#endif


  msg << "Devices:" << std::endl;
  msg << "  KOKKOS_ENABLE_CUDA: ";
#ifdef KOKKOS_ENABLE_CUDA
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_OPENMP: ";
#ifdef KOKKOS_ENABLE_OPENMP
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_THREADS: ";
#ifdef KOKKOS_ENABLE_THREADS
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_QTHREADS: ";
#ifdef KOKKOS_ENABLE_QTHREADS
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_SERIAL: ";
#ifdef KOKKOS_ENABLE_SERIAL
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif


  msg << "Default Device:" << std::endl;
  msg << "  KOKKOS_ENABLE_DEFAULT_DEVICE_TYPE_CUDA: ";
#ifdef KOKKOS_ENABLE_DEFAULT_DEVICE_TYPE_CUDA
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_DEFAULT_DEVICE_TYPE_OPENMP: ";
#ifdef KOKKOS_ENABLE_DEFAULT_DEVICE_TYPE_OPENMP
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_DEFAULT_DEVICE_TYPE_THREADS: ";
#ifdef KOKKOS_ENABLE_DEFAULT_DEVICE_TYPE_THREADS
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_DEFAULT_DEVICE_TYPE_QTHREADS: ";
#ifdef KOKKOS_ENABLE_DEFAULT_DEVICE_TYPE_QTHREADS
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_DEFAULT_DEVICE_TYPE_SERIAL: ";
#ifdef KOKKOS_ENABLE_DEFAULT_DEVICE_TYPE_SERIAL
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif


  msg << "Atomics:" << std::endl;
  msg << "  KOKKOS_ENABLE_CUDA_ATOMICS: ";
#ifdef KOKKOS_ENABLE_CUDA_ATOMICS
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_GNU_ATOMICS: ";
#ifdef KOKKOS_ENABLE_GNU_ATOMICS
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_INTEL_ATOMICS: ";
#ifdef KOKKOS_ENABLE_INTEL_ATOMICS
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_OPENMP_ATOMICS: ";
#ifdef KOKKOS_ENABLE_OPENMP_ATOMICS
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_WINDOWS_ATOMICS: ";
#ifdef KOKKOS_ENABLE_WINDOWS_ATOMICS
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif


  msg << "Vectorization:" << std::endl;
  msg << "  KOKKOS_ENABLE_PRAGMA_IVDEP: ";
#ifdef KOKKOS_ENABLE_PRAGMA_IVDEP
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_PRAGMA_LOOPCOUNT: ";
#ifdef KOKKOS_ENABLE_PRAGMA_LOOPCOUNT
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_PRAGMA_SIMD: ";
#ifdef KOKKOS_ENABLE_PRAGMA_SIMD
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_PRAGMA_UNROLL: ";
#ifdef KOKKOS_ENABLE_PRAGMA_UNROLL
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_PRAGMA_VECTOR: ";
#ifdef KOKKOS_ENABLE_PRAGMA_VECTOR
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif

  msg << "Memory:" << std::endl;
  msg << "  KOKKOS_ENABLE_HBWSPACE: ";
#ifdef KOKKOS_ENABLE_HBWSPACE
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_INTEL_MM_ALLOC: ";
#ifdef KOKKOS_ENABLE_INTEL_MM_ALLOC
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_POSIX_MEMALIGN: ";
#ifdef KOKKOS_ENABLE_POSIX_MEMALIGN
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif


  msg << "Options:" << std::endl;
  msg << "  KOKKOS_ENABLE_ASM: ";
#ifdef KOKKOS_ENABLE_ASM
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_CXX1Z: ";
#ifdef KOKKOS_ENABLE_CXX1Z
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_DEBUG_BOUNDS_CHECK: ";
#ifdef KOKKOS_ENABLE_DEBUG_BOUNDS_CHECK
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_HWLOC: ";
#ifdef KOKKOS_ENABLE_HWLOC
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_LIBRT: ";
#ifdef KOKKOS_ENABLE_LIBRT
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_MPI: ";
#ifdef KOKKOS_ENABLE_MPI
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_PROFILING: ";
#ifdef KOKKOS_ENABLE_PROFILING
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif

#ifdef KOKKOS_ENABLE_CUDA
  msg << "Cuda Options:" << std::endl;
  msg << "  KOKKOS_ENABLE_CUDA_LAMBDA: ";
#ifdef KOKKOS_ENABLE_CUDA_LAMBDA
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_CUDA_LDG_INTRINSIC: ";
#ifdef KOKKOS_ENABLE_CUDA_LDG_INTRINSIC
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_CUDA_RELOCATABLE_DEVICE_CODE: ";
#ifdef KOKKOS_ENABLE_CUDA_RELOCATABLE_DEVICE_CODE
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_CUDA_UVM: ";
#ifdef KOKKOS_ENABLE_CUDA_UVM
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_CUSPARSE: ";
#ifdef KOKKOS_ENABLE_CUSPARSE
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif
  msg << "  KOKKOS_ENABLE_CXX11_DISPATCH_LAMBDA: ";
#ifdef KOKKOS_ENABLE_CXX11_DISPATCH_LAMBDA
  msg << "yes" << std::endl;
#else
  msg << "no" << std::endl;
#endif

#endif

  msg << "\nRuntime Configuration:" << std::endl;
#ifdef KOKKOS_ENABLE_CUDA
  Cuda::print_configuration(msg, detail);
#endif
#ifdef KOKKOS_ENABLE_OPENMP
  OpenMP::print_configuration(msg, detail);
#endif
#if defined( KOKKOS_ENABLE_THREADS )
  Threads::print_configuration(msg, detail);
#endif
#ifdef KOKKOS_ENABLE_QTHREADS
  Qthreads::print_configuration(msg, detail);
#endif
#ifdef KOKKOS_ENABLE_SERIAL
  Serial::print_configuration(msg, detail);
#endif

  out << msg.str() << std::endl;
}

} // namespace Kokkos

