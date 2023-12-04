cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(GOVE LANGUAGES CXX)

add_subdirectory( 3rdparty )
add_subdirectory( src )
add_subdirectory( test )







