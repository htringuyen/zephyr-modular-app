Zephyr application that is structured into multiple separate modules. A module can add other module as dependencies using a cmake extension provided by the tool https://github.com/htringuyen/zephyr-without-west.

Framework/library that is handled by zephyr-without-west tool under the hood:
- A fork of Zephyr with some customization for unit testing: https://github.com/htringuyen/zephyr
- A Zephyr module for loading modules and customize unit testing: https://github.com/htringuyen/ztest-build-ext
