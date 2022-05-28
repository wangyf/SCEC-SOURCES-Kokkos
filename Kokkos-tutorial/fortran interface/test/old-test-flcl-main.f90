! Copyright (c) 2019. Triad National Security, LLC. All rights reserved.
!
! This program was produced under U.S. Government contract 89233218CNA000001 for
! Los Alamos National Laboratory (LANL), which is operated by Triad National
! Security, LLC for the U.S. Department of Energy/National Nuclear Security
! Administration. All rights in the program are reserved by Triad National
! Security, LLC, and the U.S. Department of Energy/National Nuclear Security
! Administration. The Government is granted for itself and others acting on
! its behalf a nonexclusive, paid-up, irrevocable worldwide license in this
! material to reproduce, prepare derivative works, distribute copies to the
! public, perform publicly and display publicly, and to permit others to do so.
!
! This program is open source under the BSD-3 License.
!
! Redistribution and use in source and binary forms, with or without modification,
! are permitted provided that the following conditions are met:
!
! 1. Redistributions of source code must retain the above copyright
!   notice, this list of conditions and the following disclaimer.
! 2. Redistributions in binary form must reproduce the above copyright
!   notice, this list of conditions and the following disclaimer in the
!   documentation and/or other materials provided with the distribution.
! 3. Neither the name of the copyright holder nor the
!   names of its contributors may be used to endorse or promote products
!   derived from this software without specific prior written permission.
!
! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
! ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
! WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
! DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
! DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
! (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
! LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
! ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
! (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
! SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

program test_flcl_main
  use, intrinsic :: iso_c_binding
  use, intrinsic :: iso_fortran_env

  use :: flcl_mod
  use :: flcl_util_mod
  use :: flcl_tests_f_mod

  implicit none

  integer(c_size_t) :: ierr

  call kokkos_initialize()

  if ( kokkos_is_initialized() ) then
    
    call kokkos_print_configuration('flcl-test-', 'kokkos.out')

    ! test ndarray 1d specializations
    ierr = test_ndarray_l_1d()
    write(*,*)'ierr ',ierr

    ierr =  test_ndarray_i32_1d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_i64_1d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r32_1d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r64_1d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_c32_1d()
    write(*,*)'ierr ',ierr

    ierr =  test_ndarray_c64_1d()
    write(*,*)'ierr ',ierr

    ! test ndarray 2d specializations
    ierr =  test_ndarray_l_2d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_i32_2d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_i64_2d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r32_2d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r64_2d()
    write(*,*)'ierr ',ierr

    ierr =  test_ndarray_c32_2d()
    write(*,*)'ierr ',ierr

    ierr =  test_ndarray_c64_2d()
    write(*,*)'ierr ',ierr
    
    ! test ndarray 3d specializations
    ierr =  test_ndarray_l_3d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_i32_3d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_i64_3d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r32_3d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r64_3d()
    write(*,*)'ierr ',ierr
    
    ! test ndarray 4d specializations
    ierr =  test_ndarray_l_4d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_i32_4d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_i64_4d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r32_4d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r64_4d()
    write(*,*)'ierr ',ierr

    ! test ndarray 5d specializations
    ierr =  test_ndarray_l_5d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_i32_5d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_i64_5d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r32_5d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r64_5d()
    write(*,*)'ierr ',ierr

    ! test ndarray 6d specializations
    ierr =  test_ndarray_l_6d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_i32_6d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_i64_6d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r32_6d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r64_6d()
    write(*,*)'ierr ',ierr

    ! test ndarray 7d specializations
    ierr =  test_ndarray_l_7d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_i32_7d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_i64_7d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r32_7d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_ndarray_r64_7d()
    write(*,*)'ierr ',ierr

    ! test kokkos_allocate_view 1d specializations
    ierr =  test_kokkos_allocate_view_l_1d()
    write(*,*)'ierr ',ierr

    ierr =  test_kokkos_allocate_view_i32_1d()
    write(*,*)'ierr ',ierr

    ierr =  test_kokkos_allocate_view_i64_1d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_kokkos_allocate_view_r32_1d()
    write(*,*)'ierr ',ierr

    ierr =  test_kokkos_allocate_view_r64_1d()
    write(*,*)'ierr ',ierr

    ! test kokkos_allocate_view 2d specializations
    ierr =  test_kokkos_allocate_view_l_2d()
    write(*,*)'ierr ',ierr

    ierr =  test_kokkos_allocate_view_i32_2d()
    write(*,*)'ierr ',ierr

    ierr =  test_kokkos_allocate_view_i64_2d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_kokkos_allocate_view_r32_2d()
    write(*,*)'ierr ',ierr

    ierr =  test_kokkos_allocate_view_r64_2d()
    write(*,*)'ierr ',ierr

    ! test kokkos_allocate_view 3d specializations
    ierr =  test_kokkos_allocate_view_l_3d()
    write(*,*)'ierr ',ierr

    ierr =  test_kokkos_allocate_view_i32_3d()
    write(*,*)'ierr ',ierr

    ierr =  test_kokkos_allocate_view_i64_3d()
    write(*,*)'ierr ',ierr
    
    ierr =  test_kokkos_allocate_view_r32_3d()
    write(*,*)'ierr ',ierr

    ierr =  test_kokkos_allocate_view_r64_3d()
    write(*,*)'ierr ',ierr

    call kokkos_finalize()

  end if
  
end program test_flcl_main