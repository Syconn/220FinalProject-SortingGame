cmake_minimum_required(VERSION 4.0)
project(220FinalMyVersion)

set(CMAKE_CXX_STANDARD 20)

add_executable(220FinalMyVersion main.cpp
        Sorter.h
        ArrayManager.cpp
        Game.cpp
        Game.h
        ArrayUtil.h)
