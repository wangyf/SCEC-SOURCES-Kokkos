# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/build

# Include any dependencies generated for this target.
include test/CMakeFiles/test_to_ndarray_r64_4d.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/test_to_ndarray_r64_4d.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_to_ndarray_r64_4d.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_to_ndarray_r64_4d.dir/flags.make

test/CMakeFiles/test_to_ndarray_r64_4d.dir/test_to_ndarray_r64_4d.f90.o: test/CMakeFiles/test_to_ndarray_r64_4d.dir/flags.make
test/CMakeFiles/test_to_ndarray_r64_4d.dir/test_to_ndarray_r64_4d.f90.o: ../test/test_to_ndarray_r64_4d.f90
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building Fortran object test/CMakeFiles/test_to_ndarray_r64_4d.dir/test_to_ndarray_r64_4d.f90.o"
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/build/test && /opt/local/bin/gfortran $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -c /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/test/test_to_ndarray_r64_4d.f90 -o CMakeFiles/test_to_ndarray_r64_4d.dir/test_to_ndarray_r64_4d.f90.o

test/CMakeFiles/test_to_ndarray_r64_4d.dir/test_to_ndarray_r64_4d.f90.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing Fortran source to CMakeFiles/test_to_ndarray_r64_4d.dir/test_to_ndarray_r64_4d.f90.i"
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/build/test && /opt/local/bin/gfortran $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -E /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/test/test_to_ndarray_r64_4d.f90 > CMakeFiles/test_to_ndarray_r64_4d.dir/test_to_ndarray_r64_4d.f90.i

test/CMakeFiles/test_to_ndarray_r64_4d.dir/test_to_ndarray_r64_4d.f90.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling Fortran source to assembly CMakeFiles/test_to_ndarray_r64_4d.dir/test_to_ndarray_r64_4d.f90.s"
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/build/test && /opt/local/bin/gfortran $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -S /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/test/test_to_ndarray_r64_4d.f90 -o CMakeFiles/test_to_ndarray_r64_4d.dir/test_to_ndarray_r64_4d.f90.s

# Object files for target test_to_ndarray_r64_4d
test_to_ndarray_r64_4d_OBJECTS = \
"CMakeFiles/test_to_ndarray_r64_4d.dir/test_to_ndarray_r64_4d.f90.o"

# External object files for target test_to_ndarray_r64_4d
test_to_ndarray_r64_4d_EXTERNAL_OBJECTS =

test/test_to_ndarray_r64_4d: test/CMakeFiles/test_to_ndarray_r64_4d.dir/test_to_ndarray_r64_4d.f90.o
test/test_to_ndarray_r64_4d: test/CMakeFiles/test_to_ndarray_r64_4d.dir/build.make
test/test_to_ndarray_r64_4d: libflcl.a
test/test_to_ndarray_r64_4d: test/libflcl-testlib.a
test/test_to_ndarray_r64_4d: libflcl.a
test/test_to_ndarray_r64_4d: /Users/yongfeiwang/software/kokkos/build/kokkos-install/lib/libkokkoscontainers.a
test/test_to_ndarray_r64_4d: /Users/yongfeiwang/software/kokkos/build/kokkos-install/lib/libkokkoscore.a
test/test_to_ndarray_r64_4d: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX11.3.sdk/usr/lib/libdl.tbd
test/test_to_ndarray_r64_4d: test/CMakeFiles/test_to_ndarray_r64_4d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking Fortran executable test_to_ndarray_r64_4d"
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_to_ndarray_r64_4d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_to_ndarray_r64_4d.dir/build: test/test_to_ndarray_r64_4d
.PHONY : test/CMakeFiles/test_to_ndarray_r64_4d.dir/build

test/CMakeFiles/test_to_ndarray_r64_4d.dir/clean:
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/build/test && $(CMAKE_COMMAND) -P CMakeFiles/test_to_ndarray_r64_4d.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_to_ndarray_r64_4d.dir/clean

test/CMakeFiles/test_to_ndarray_r64_4d.dir/depend:
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/test /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/build /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/build/test /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/build/test/CMakeFiles/test_to_ndarray_r64_4d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_to_ndarray_r64_4d.dir/depend

