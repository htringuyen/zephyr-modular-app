cmake_minimum_required(VERSION 3.20.0)

include(ztest_build_extensions)

zephyr_include_module(:self)

find_package(Zephyr COMPONENTS ztest_build_ext HINTS $ENV{ZEPHYR_BASE})

project(test_math_lib_module_internal)

target_sources(app PRIVATE main.c)