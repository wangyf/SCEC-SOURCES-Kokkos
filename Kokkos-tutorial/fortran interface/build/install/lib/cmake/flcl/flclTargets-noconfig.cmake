#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "flcl::flcl" for configuration ""
set_property(TARGET flcl::flcl APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(flcl::flcl PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX;Fortran"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libflcl.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS flcl::flcl )
list(APPEND _IMPORT_CHECK_FILES_FOR_flcl::flcl "${_IMPORT_PREFIX}/lib/libflcl.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
