cmake_minimum_required(VERSION 3.16)
project(BookDataset LANGUAGES CXX)

set(SOURCES src/main.cpp src/Book.cpp src/DatasetReader.cpp)
set(INCLUDES src/Book.h src/DatasetReader.h)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)

add_executable(main ${SOURCES})
target_include_directories(main PRIVATE ${INCLUDES})

