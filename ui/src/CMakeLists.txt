set(UI_SRC
    ui.c
    ui_main_menu.c
    ui_rasp_select.c
    ui_rasp_tools.c
    ui_state.c
)

add_library(ui_lib ${UI_SRC})

target_include_directories(ui_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc
    ${PROJECT_SOURCE_DIR}/core/inc
)
