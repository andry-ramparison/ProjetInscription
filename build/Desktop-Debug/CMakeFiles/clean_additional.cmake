# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QtInscription_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QtInscription_autogen.dir/ParseCache.txt"
  "QtInscription_autogen"
  )
endif()
