cmake_minimum_required(VERSION 3.6)

project(rstd)

include_directories(include)

file (GLOB SOURCES "src/*.cc")

add_library(rstd STATIC ${SOURCES})