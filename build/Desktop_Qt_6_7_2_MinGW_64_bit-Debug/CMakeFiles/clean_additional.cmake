# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Toil_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Toil_autogen.dir\\ParseCache.txt"
  "Toil_autogen"
  )
endif()
