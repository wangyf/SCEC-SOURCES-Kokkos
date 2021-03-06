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

#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sys/time.h>
// Include Kokkos Headers
#include<Kokkos_Core.hpp>

#ifdef KOKKOS_ENABLE_CUDA
#include "CudaTimer.h"
using Timer = CudaTimer;
#else
#include "OpenMPTimer.h"
using Timer = OpenMPTimer;
#endif

int main(int argc, char* argv[]) {

  // Parameters
  int length = 10000000; // length of vectors
  int nrepeat = 10;     // number of integration invocations

  // Read command line arguments
  for(int i=0; i<argc; i++) {
           if( strcmp(argv[i], "-l") == 0) {
      length = atoi(argv[++i]);
    } else if( strcmp(argv[i], "-nrepeat") == 0) {
      nrepeat = atoi(argv[++i]);
    } else if( (strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "-help") == 0)) {
      printf("SAXPY Options:\n");
      printf("  -l <int>:         length of vectors (default: 10000000)\n");
      printf("  -nrepeat <int>:   number of integration invocations (default: 10)\n");
      printf("  -help (-h):       print this message\n");
    }
  }

  //Initialize Kokkos
  Kokkos::initialize(argc,argv);


  {
    // Allocate Views
    Kokkos::View<double*> x("X",length);
    Kokkos::View<double*> y("Y",length);
    double a = 2.0;
    
    // Initialize arrays
    Kokkos::parallel_for(length, KOKKOS_LAMBDA (const int& i) {
        x(i) = 1.0*i;
        y(i) = 3.0*i;
      });
    
    // Time saxpy computation
    struct timeval begin,end;
    
    
    Timer wall_clock;
    wall_clock.start();
    for(int k = 0; k < nrepeat; k++) {
      
      // Do saxpy
      Kokkos::parallel_for(length, KOKKOS_LAMBDA (const int& i) {
          x(i) = a*x(i) + y(i);
        });
      
    }
    wall_clock.stop();

    // Print results
    double time = wall_clock.elapsed();
    
    printf("#VectorLength Time(s) TimePerIterations(s) size(MB) BW(GB/s)\n");
    printf("%i %lf %e %lf %lf\n",length,time,time/nrepeat,1.0e-6*length*3*8,1.0e-9*length*3*nrepeat*8/time);
  }

  // Shutdown Kokkos
  Kokkos::finalize();
}
