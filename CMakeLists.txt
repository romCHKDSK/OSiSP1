cmake_minimum_required(VERSION 3.0)

project(lr1 LANGUAGES C)

add_executable(lr1 main.c)

install(TARGETS lr1 RUNTIME DESTINATION bin)
