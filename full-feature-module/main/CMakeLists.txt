# Expose public headers placed in include dir
zephyr_include_directories(include)

# load packages enabled by setting kconfig, view packages.cmake for more details
include(packages.cmake)