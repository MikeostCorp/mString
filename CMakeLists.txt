cmake_minimum_required(VERSION 3.2)

project(myString)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB src/mString.cpp)

add_library(mString STATIC ${SOURCE_EXE})

add_executable(main ${SOURCE_LIB})

target_link_libraries(main mString)
