CMAKE_MINIMUM_REQUIRED(VERSION 3.9.3)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

SET(ProjectName linked-list)

PROJECT(${ProjectName})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W4")

SET(SourceFolder src)

ADD_EXECUTABLE(${ProjectName} ${SourceFolder}/main.cpp
    ${SourceFolder}/list.hpp)
