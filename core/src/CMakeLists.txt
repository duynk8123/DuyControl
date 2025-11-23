# DuyControl/core/src/CMakeLists.txt
set(CORE_SRC
    queue.c
    state.c
    system.c
)

add_library(core_lib ${CORE_SRC})

target_include_directories(core_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc
    ${PROJECT_SOURCE_DIR}/ui/inc
)
