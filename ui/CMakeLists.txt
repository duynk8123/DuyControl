add_subdirectory(src)

# include dir
target_include_directories(ui_lib PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${PROJECT_SOURCE_DIR}/core/inc
        )
