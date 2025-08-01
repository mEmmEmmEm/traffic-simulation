cmake_minimum_required(VERSION 3.10)
project(TrafficSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Собираем все .cpp из папки src/
file(GLOB SOURCES src/*.cpp)

add_executable(TrafficSimulator ${SOURCES})
