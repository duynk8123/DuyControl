set(SERVICE_SRC
    i2c_service.c
)

add_library(service_lib ${SERVICE_SRC})

target_include_directories(service_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/core/inc
    ${PROJECT_SOURCE_DIR}/ui/inc
)
