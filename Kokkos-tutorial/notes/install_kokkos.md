## Install Kokkos tutorial

### Download and compile Kokkos library
``` bash
cd ${HOME}
git clone https://github.com/kokkos/kokkos.git
git clone https://github.com/kokkos/kokkos-tutorials.git

cd kokkos
mkdir build
cd build

cmake .. \
	-D CMAKE_CXX_COMPILER=g++\
	-D CMAKE_CXX_FLAGS=-fopenmp \
	-D CMAKE_INSTALL_PREFIX="${PWD}"/install \
	-D Kokkos_ENABLE_OPENMP=On \

make -j install

export CMAKE_PREFIX_PATH="${PWD}"/install:"${CMAKE_PREFIX_PATH}"
```

### Comile exercise

``` bash
cd kokkos-tutorials/Exercises/04/Solution
mkdir build
cd build
cmake ..
make

export OMP_PROC_BIND=spread
# OMP_PROC_BIND=true/false
export OMP_PLACES=threads
export OMP_NUM_THREADS=10
./04_Exercise
```