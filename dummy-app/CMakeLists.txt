cmake_minimum_required(VERSION 3.20.0)

get_filename_component(REPO_ROOT "${CMAKE_SOURCE_DIR}" DIRECTORY)

include(ztest_build_extensions)

zephyr_include_module("${REPO_ROOT}/blink-driver-module:blink-driver-module")
zephyr_include_module("${REPO_ROOT}/custom-ek-ra6m3-module:custom-ek-ra6m3-module")
zephyr_include_module("${REPO_ROOT}/math-lib-module:math-lib-module")

find_package(Zephyr COMPONENTS ztest_build_ext HINTS $ENV{ZEPHYR_BASE})

project(dummy-app)

target_sources(app PRIVATE main.c)