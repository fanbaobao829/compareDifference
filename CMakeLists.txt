cmake_minimum_required(VERSION 3.20)
project(compareDifference)

set(CMAKE_CXX_STANDARD 14)

add_executable(compareDifference main.cpp fileReader.cpp fileReader.h fileCompare.cpp fileCompare.h fileWriter.cpp fileWriter.h errorLog.cpp errorLog.h)
