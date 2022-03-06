cmake_minimum_required(VERSION 2.9)

Project(generic_factory)

option(Recursive "Include recursive factory and test." ON)

#file(GLOB src
#     "*.hpp"
#	 "*.h"
#     "*.cpp"
#)

set(src
	generic_factory.hpp 
    test_base.hpp
    test_sub_base.hpp
    test_sub_derived_1.h
    test_sub_derived_2.h
    test_derived_1.cpp
    test_derived_2.cpp
    test_sub_derived_1.cpp
    test_sub_derived_2.cpp
)

add_executable(test_generic_factory ${src} test.cpp)

if(Recursive)
    add_executable(test_recursive_factory ${src} recursive_factory.hpp test_recursive.cpp)
    target_compile_definitions(test_recursive_factory PUBLIC -DRECURSIVE)
endif(Recursive)
