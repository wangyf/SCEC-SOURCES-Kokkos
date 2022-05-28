### SCEC-SOURCES-Rena Wu, Yongfei Wang & Christine Goulet
This is a working directory for a SCEC SOURCES internship

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

---
Markdown basic syntax [link](https://www.markdownguide.org/basic-syntax/)
