set(CMAKE_Fortran_COMPILER "/opt/local/bin/gfortran")
set(CMAKE_Fortran_COMPILER_ARG1 "")
set(CMAKE_Fortran_COMPILER_ID "GNU")
set(CMAKE_Fortran_COMPILER_VERSION "10.3.0")
set(CMAKE_Fortran_COMPILER_WRAPPER "")
set(CMAKE_Fortran_PLATFORM_ID "")
set(CMAKE_Fortran_SIMULATE_ID "")
set(CMAKE_Fortran_SIMULATE_VERSION "")


set(CMAKE_Fortran_COMPILER_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr")
set(CMAKE_COMPILER_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr")

set(CMAKE_AR "/opt/local/bin/ar")
set(CMAKE_Fortran_COMPILER_AR "CMAKE_Fortran_COMPILER_AR-NOTFOUND")
set(CMAKE_RANLIB "/opt/local/bin/ranlib")
set(CMAKE_Fortran_COMPILER_RANLIB "CMAKE_Fortran_COMPILER_RANLIB-NOTFOUND")
set(CMAKE_COMPILER_IS_GNUG77 1)
set(CMAKE_Fortran_COMPILER_LOADED 1)
set(CMAKE_Fortran_COMPILER_WORKS TRUE)
set(CMAKE_Fortran_ABI_COMPILED TRUE)
set(CMAKE_COMPILER_IS_MINGW )
set(CMAKE_COMPILER_IS_CYGWIN )
if(CMAKE_COMPILER_IS_CYGWIN)
  set(CYGWIN 1)
  set(UNIX 1)
endif()

set(CMAKE_Fortran_COMPILER_ENV_VAR "FC")

set(CMAKE_Fortran_COMPILER_SUPPORTS_F90 1)

if(CMAKE_COMPILER_IS_MINGW)
  set(MINGW 1)
endif()
set(CMAKE_Fortran_COMPILER_ID_RUN 1)
set(CMAKE_Fortran_SOURCE_FILE_EXTENSIONS f;F;fpp;FPP;f77;F77;f90;F90;for;For;FOR;f95;F95)
set(CMAKE_Fortran_IGNORE_EXTENSIONS h;H;o;O;obj;OBJ;def;DEF;rc;RC)
set(CMAKE_Fortran_LINKER_PREFERENCE 20)
if(UNIX)
  set(CMAKE_Fortran_OUTPUT_EXTENSION .o)
else()
  set(CMAKE_Fortran_OUTPUT_EXTENSION .obj)
endif()

# Save compiler ABI information.
set(CMAKE_Fortran_SIZEOF_DATA_PTR "8")
set(CMAKE_Fortran_COMPILER_ABI "")
set(CMAKE_Fortran_LIBRARY_ARCHITECTURE "")

if(CMAKE_Fortran_SIZEOF_DATA_PTR AND NOT CMAKE_SIZEOF_VOID_P)
  set(CMAKE_SIZEOF_VOID_P "${CMAKE_Fortran_SIZEOF_DATA_PTR}")
endif()

if(CMAKE_Fortran_COMPILER_ABI)
  set(CMAKE_INTERNAL_PLATFORM_ABI "${CMAKE_Fortran_COMPILER_ABI}")
endif()

if(CMAKE_Fortran_LIBRARY_ARCHITECTURE)
  set(CMAKE_LIBRARY_ARCHITECTURE "")
endif()


set(CMAKE_Fortran_SYSROOT_FLAG "-isysroot")
set(CMAKE_Fortran_OSX_DEPLOYMENT_TARGET_FLAG "-mmacosx-version-min=")

set(CMAKE_Fortran_IMPLICIT_INCLUDE_DIRECTORIES "/opt/local/lib/gcc10/gcc/x86_64-apple-darwin20/10.3.0/finclude;/Users/yongfeiwang/include;/opt/local/lib/gcc10/gcc/x86_64-apple-darwin20/10.3.0/include;/opt/local/lib/gcc10/gcc/x86_64-apple-darwin20/10.3.0/include-fixed;/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX11.3.sdk/usr/include")
set(CMAKE_Fortran_IMPLICIT_LINK_LIBRARIES "gfortran;gcc_ext.10.5;gcc;quadmath;m;gcc_ext.10.5;gcc")
set(CMAKE_Fortran_IMPLICIT_LINK_DIRECTORIES "/Users/yongfeiwang/lib;/opt/local/lib/gcc10/gcc/x86_64-apple-darwin20/10.3.0;/opt/local/lib/gcc10;/Users/yongfeiwang/software/kokkos-tutorials/Exercises/kokkos-fortran-interop;/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX11.3.sdk/usr/lib")
set(CMAKE_Fortran_IMPLICIT_LINK_FRAMEWORK_DIRECTORIES "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX11.3.sdk/System/Library/Frameworks")
