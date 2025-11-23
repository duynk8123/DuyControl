# DuyControl/core/CMakeLists.txt
add_subdirectory(src)

# Make include directory available
target_include_directories(core_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
