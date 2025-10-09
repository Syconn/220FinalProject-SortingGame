cmake_minimum_required(VERSION 4.0)
project(220FinalMyVersion)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(220FinalMyVersion
        src/main.cpp
        src/structures/ArrayManager.cpp
        src/Game.cpp
        src/elements/Hand.cpp
        src/elements/Card.cpp
)