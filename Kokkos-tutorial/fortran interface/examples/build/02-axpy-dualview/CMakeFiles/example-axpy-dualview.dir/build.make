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
include 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/compiler_depend.make

# Include the progress variables for this target.
include 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/progress.make

# Include the compile flags for this target's objects.
include 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/flags.make

02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.o: 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/flags.make
02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.o: ../02-axpy-dualview/axpy-dualview-cxx.cc
02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.o: 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.o"
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/02-axpy-dualview && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.o -MF CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.o.d -o CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.o -c /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/02-axpy-dualview/axpy-dualview-cxx.cc

02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.i"
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/02-axpy-dualview && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/02-axpy-dualview/axpy-dualview-cxx.cc > CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.i

02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.s"
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/02-axpy-dualview && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/02-axpy-dualview/axpy-dualview-cxx.cc -o CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.s

# Object files for target example-axpy-dualview
example__axpy__dualview_OBJECTS = \
"CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.o"

# External object files for target example-axpy-dualview
example__axpy__dualview_EXTERNAL_OBJECTS =

02-axpy-dualview/example-axpy-dualview: 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/axpy-dualview-cxx.o
02-axpy-dualview/example-axpy-dualview: 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/build.make
02-axpy-dualview/example-axpy-dualview: 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example-axpy-dualview"
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/02-axpy-dualview && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example-axpy-dualview.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/build: 02-axpy-dualview/example-axpy-dualview
.PHONY : 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/build

02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/clean:
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/02-axpy-dualview && $(CMAKE_COMMAND) -P CMakeFiles/example-axpy-dualview.dir/cmake_clean.cmake
.PHONY : 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/clean

02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/depend:
	cd /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/02-axpy-dualview /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/02-axpy-dualview /Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop/examples/build/02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 02-axpy-dualview/CMakeFiles/example-axpy-dualview.dir/depend

