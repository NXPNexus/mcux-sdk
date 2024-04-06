# Add set(CONFIG_USE_device_system_ca55 true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if((CONFIG_DEVICE_ID STREQUAL MIMX9596xxxxN) AND (MCUX_DEVICE STREQUAL MIMX9596_ca55))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/system_MIMX9596_ca55.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)

#include(device_CMSIS)

else()

message(SEND_ERROR "device_system_ca55 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
