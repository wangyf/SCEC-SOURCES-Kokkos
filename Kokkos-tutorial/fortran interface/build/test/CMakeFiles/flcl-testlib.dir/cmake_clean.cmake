file(REMOVE_RECURSE
  "libflcl-testlib.a"
  "libflcl-testlib.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX Fortran)
  include(CMakeFiles/flcl-testlib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
