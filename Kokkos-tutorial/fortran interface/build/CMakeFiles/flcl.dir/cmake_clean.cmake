file(REMOVE_RECURSE
  "libflcl.a"
  "libflcl.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX Fortran)
  include(CMakeFiles/flcl.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
