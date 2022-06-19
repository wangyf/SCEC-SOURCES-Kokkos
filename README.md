### SCEC-SOURCES-Rena Wu, Yongfei Wang & Christine Goulet
This is a working directory for a SCEC SOURCES internship
---

## Title
A Performance-portable Implementation of Earthquake Dynamic Rupture Simulation Targeting Upcoming Future High-Performance Computers

## Introduction
Earthquake dynamic rupture codes are computational tools that are used to understand the physical behavior of earthquakes, how earthquakes interact, on short time scales, with the earth that surrounds them, and make physically plausible predictions of seismic hazards. Advances in high-performance computing (HPC) enabled dynamic rupture simulations to run at an unprecedented scale and to capture an increasing level of resolution.

As HPC technology continues to advance, software porting challenges arise. The primary challenge is performance portability across diverse hardware platforms. Recent HPC landscape has seen a significant increase in the diversity of processors and accelerators. This is reflected in the design of upcoming exascale HPC systems, for example, the Frontier system at the Oak Ridge National Laboratory will use AMD EPYC CPUs and Radeon GPUs while the Aurora system at the Argonne National Laboratory will employ Intel Xeon CPUs and Xe GPUs. In this sense, computational application kernels that were originally developed with the native programming model for the respective hardware of a current system (e.g., CUDA on NVIDIA GPUs) may not be supported by next-generation HPCs and require a new programming model (e.g., HIP on AMD GPU and DPC++ on Intel GPUs).

To solve this issue, we propose to use the Kokkos framework and develop a performance-portable implementation of a dynamic rupture code (SORD)  that runs on the next-generation HPC systems regardless of manufacturer and native programming models. This new implementation is based on a single-source design and facilitates the future development and porting to new hardware. Kokkos (developed in the Sandia National Laboratory) implements a programming model in C++ for writing performance-portable applications targeting all major HPC platforms. Kokkos is designed to target complex node architectures with N-level memory hierarchies and multiple types of execution resources. It currently can use CUDA, HIP, DPC++/SYCL, HPX, OpenMP, and C++ threads as backend programming models with several other backends in development.

In this project, we propose to reorganize a computationally intensive kernel in the dynamic rupture code (SORD) that was originally written in Fortran. Message Passing Interface (MPI) is implemented in SORD for inter-node communication that will remain as it is. In contrast, the intra-node computations that model earthquakes and rupture propagations as the highest computational load will be optimized through Kokkos. The new Kokkos-enabled dynamic rupture code will be tested for the diverse backends of OpenMP, CUDA and HIP and its performance will be investigated on different platforms (e.g., Theta for OpenMP, ThetaGPU for CUDA and HIP for Polaris/Aurora). 

## Team
* Rena Wu (UCSD)
* Yongfei Wang (SCEC/USC)
* Christine Goulet (SCEC/USC)

## Working [slack](https://scecsources.slack.com)

## Tutorials
>* [Install Kokkos](/Kokkos-tutorial/notes/install_kokkos.md)
>* [What is the mandelbrot set?](https://mathworld.wolfram.com/MandelbrotSet.html)
>	* [Algorithm for Mandelbrot set](https://complex-analysis.com/content/mandelbrot_set.html#:~:text=The%20simplest%20algorithm%20for%20generating,is%20chosen%20for%20that%20pixel.)
>	* [Plotting algorithms for the Mandelbrot set](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set)
>	* [OpenACC for Mandelbrot set](/Kokkos-tutorial/learn-by-example/code/handson/3/mandelbrot_kokkos/doc/advanced-openacc-techniques.pdf)

## Working log
* [Entrance](https://docs.google.com/presentation/d/1HhAPIeLVFGljRR52KogsXN_SRYyyrFbmcD36ymoxWTg/edit?usp=sharing)

## Useful links
### Kokkos programming model
> -	[Kokkos Wiki](https://github.com/kokkos/kokkos/wiki/The-Kokkos-Programming-Guide)

### Kokkos online lectures:
> * [Module-1: Introduction, building and parallel dispatch](https://youtu.be/rUIcWtFU5qM)
> * [Module-2: Views and spaces](https://youtu.be/O-asHTtO7O4)
> * [Module-3: MultiDimensional Loops and Data Structures](https://youtu.be/nGyJS8u-6GY)

### Markdown:
> * [basic syntax](https://www.markdownguide.org/basic-syntax/)
> * [latex in markdown](https://ashki23.github.io/markdown-latex.html)
