#Description: ENET Driver; user_visible: True
include_guard(GLOBAL)
message("driver_enet component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fsl_enet.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)

#OR Logic component
if(${MCUX_DEVICE} STREQUAL "MIMXRT1062")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1042")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1176_cm4")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1173_cm4")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1175_cm4")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1176_cm7")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1171_cm7")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1173_cm7")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1172_cm7")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1175_cm7")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1061")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1165_cm4")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1165_cm7")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8ML4")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1171_cm7")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1024")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8MM4")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8ML8")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX9352")
    include(driver_memory)
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1172_cm7")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MK64F12")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MK63F12")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MK24F12")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MK66F18")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MK65F18")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MK26F18")
    include(driver_common)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8QM6_cm4_core0")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8QM6_cm4_core1")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8QX6")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8UX6")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8UX5")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8QX2")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8QX3")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8QX5")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8QX4")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8DX4")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8DX2")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8QX1")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8DX3")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8DX6")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8DX5")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8DX1")
    include(driver_memory)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8ML8")
    include(driver_memory)
endif()

