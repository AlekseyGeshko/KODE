cmake_minimum_required(VERSION 3.25)
project(object_list_processing_application)

set(CMAKE_CXX_STANDARD 17)

add_executable(object_list_processing_application readData.cpp readData.h groupBy.h groupByType.cpp groupByType.h groupByDistance.cpp groupByDistance.h groupByName.cpp groupByName.h groupByTime.cpp groupByTime.h writeData.cpp writeData.h main.cpp)
