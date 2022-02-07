#Description: LPI2C Edma Driver; user_visible: True
include_guard(GLOBAL)
message("driver_lpi2c_edma component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fsl_lpi2c_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)

#OR Logic component
if(${MCUX_DEVICE} STREQUAL "MKE18F16")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1166_cm4")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1166_cm7")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1052")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1064")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MKE15Z7")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1021")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1062")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "K32L3A60_cm0plus")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "K32L3A60_cm4")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1176_cm4")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1176_cm7")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MCIMX7U5")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1024")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1011")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "K32L2A41A")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMXRT1015")
    include(driver_edma)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8QM6_cm4_core0")
    include(driver_dma3)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8QM6_cm4_core1")
    include(driver_dma3)
endif()
if(${MCUX_DEVICE} STREQUAL "MIMX8QX6")
    include(driver_dma3)
endif()

include(driver_lpi2c)
