cmake_minimum_required(VERSION 3.0)
project(valsim)
file(
    GLOB_RECURSE
    source_file
    src/*
)

add_executable(
    valsim
    ${source_file}
)
