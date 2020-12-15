cmake_minimum_required(VERSION 3.6)

project(rstd)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file (GLOB SOURCES "src/*.cc")

file (GLOB SUB_SOURCES "src/*/*.cc")

list (APPEND SOURCES ${SUB_SOURCES})

add_library(rstd SHARED ${SOURCES})