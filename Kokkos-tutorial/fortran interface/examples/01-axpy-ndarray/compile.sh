#!/bin/bash
#export KOKKOS_ROOT_DIR=/KOKKOS/DIR/HERE
export KOKKOS_ROOT_DIR=/Users/yongfeiwang/software/kokkos/build/kokkos-install
export flcl_ROOT_DIR=/Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/build/install
rm *.o *.mod *.x
gfortran -c -std=f2008 -I$flcl_ROOT_DIR/include axpy-ndarray-f.f90
g++ -c -fopenmp -I$flcl_ROOT_DIR/include -I$KOKKOS_ROOT_DIR/include axpy-ndarray-cxx.cc
gfortran -c -g -std=f2008 -I$flcl_ROOT_DIR/include axpy-ndarray-main.F90
gfortran -std=f2008 -o axpy-ndarray axpy-ndarray-f.o axpy-ndarray-cxx.o axpy-ndarray-main.o -L$flcl_ROOT_DIR/lib -lflcl -L$KOKKOS_ROOT_DIR/lib -lkokkoscore -lstdc++ -fopenmp