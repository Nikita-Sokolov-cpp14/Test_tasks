cmake_minimum_required (VERSION 3.20)
project (Using_Curves)
include_directories (DLL)

add_executable (Using_Curves main.cpp)
add_subdirectory (DLL)

target_link_libraries(Using_Curves Curves_DLL)
