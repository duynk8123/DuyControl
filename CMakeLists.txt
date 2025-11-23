cmake_minimum_required(VERSION 3.10)
project(DuyControl C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g -pthread")

# Add submodules
add_subdirectory(core)
add_subdirectory(ui)
add_subdirectory(service)

# Main executable
add_executable(dcontrol main.c)

# Link libraries
target_link_libraries(dcontrol
    core_lib
    ui_lib
    service_lib
    pthread
)
