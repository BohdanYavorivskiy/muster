cmake_minimum_required(VERSION 3.16)
project(muster)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif ()


add_executable(
    muster

    main.cpp

    config.hpp
    tools.hpp
    model.hpp

    config.cpp
    tools.cpp
    model.cpp
    )

