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
CMAKE_SOURCE_DIR = /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build

# Include any dependencies generated for this target.
include 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/compiler_depend.make

# Include the progress variables for this target.
include 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/progress.make

# Include the compile flags for this target's objects.
include 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/flags.make

04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.o: 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/flags.make
04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.o: ../04-complex-ndarray/complex-ndarray-cxx.cc
04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.o: 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.o"
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/04-complex-ndarray && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.o -MF CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.o.d -o CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.o -c /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/04-complex-ndarray/complex-ndarray-cxx.cc

04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.i"
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/04-complex-ndarray && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/04-complex-ndarray/complex-ndarray-cxx.cc > CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.i

04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.s"
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/04-complex-ndarray && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/04-complex-ndarray/complex-ndarray-cxx.cc -o CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.s

# Object files for target example-complex-ndarray
example__complex__ndarray_OBJECTS = \
"CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.o"

# External object files for target example-complex-ndarray
example__complex__ndarray_EXTERNAL_OBJECTS =

04-complex-ndarray/example-complex-ndarray: 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/complex-ndarray-cxx.o
04-complex-ndarray/example-complex-ndarray: 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/build.make
04-complex-ndarray/example-complex-ndarray: 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example-complex-ndarray"
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/04-complex-ndarray && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example-complex-ndarray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/build: 04-complex-ndarray/example-complex-ndarray
.PHONY : 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/build

04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/clean:
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/04-complex-ndarray && $(CMAKE_COMMAND) -P CMakeFiles/example-complex-ndarray.dir/cmake_clean.cmake
.PHONY : 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/clean

04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/depend:
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/04-complex-ndarray /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/04-complex-ndarray /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 04-complex-ndarray/CMakeFiles/example-complex-ndarray.dir/depend

