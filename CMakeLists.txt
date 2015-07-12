cmake_minimum_required(VERSION 2.8)
project(Vfortran)

add_definitions(-Wall)

set(SRCS src/main.c src/stack.c)

add_executable(vf ${SRCS})

add_executable(stack_test src/stack_test.c src/stack.c)