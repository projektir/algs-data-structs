CMAKE_MINIMUM_REQUIRED(VERSION 3.9.3)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

SET(ProjectName uncat)

PROJECT(${ProjectName})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W4")

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

SET(SourceFolder src)

ADD_EXECUTABLE(${ProjectName} ${SourceFolder}/main.cpp)
