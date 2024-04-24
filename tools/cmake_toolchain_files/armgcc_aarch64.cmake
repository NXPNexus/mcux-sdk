# TOOLCHAIN EXTENSION
IF(WIN32)
    SET(TOOLCHAIN_EXT ".exe")
ELSE()
    SET(TOOLCHAIN_EXT "")
ENDIF()

# EXECUTABLE EXTENSION
SET (CMAKE_EXECUTABLE_SUFFIX ".elf")

# TOOLCHAIN_DIR AND NANO LIBRARY
SET(TOOLCHAIN_DIR $ENV{ARMGCC_DIR})
STRING(REGEX REPLACE "\\\\" "/" TOOLCHAIN_DIR "${TOOLCHAIN_DIR}")

IF(NOT TOOLCHAIN_DIR)
    MESSAGE(FATAL_ERROR "***Please set ARMGCC_DIR in envionment variables***")
ENDIF()

MESSAGE(STATUS "TOOLCHAIN_DIR: " ${TOOLCHAIN_DIR})

# TARGET_TRIPLET
SET(TARGET_TRIPLET "aarch64-none-elf")

SET(TOOLCHAIN_BIN_DIR ${TOOLCHAIN_DIR}/bin)
SET(TOOLCHAIN_INC_DIR ${TOOLCHAIN_DIR}/${TARGET_TRIPLET}/include)
SET(TOOLCHAIN_LIB_DIR ${TOOLCHAIN_DIR}/${TARGET_TRIPLET}/lib)

SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_PROCESSOR arm)

SET(CMAKE_C_COMPILER ${TOOLCHAIN_BIN_DIR}/${TARGET_TRIPLET}-gcc${TOOLCHAIN_EXT})
SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_BIN_DIR}/${TARGET_TRIPLET}-g++${TOOLCHAIN_EXT})
SET(CMAKE_ASM_COMPILER ${TOOLCHAIN_BIN_DIR}/${TARGET_TRIPLET}-gcc${TOOLCHAIN_EXT})

set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)

SET(CMAKE_OBJCOPY ${TOOLCHAIN_BIN_DIR}/${TARGET_TRIPLET}-objcopy CACHE INTERNAL "objcopy tool")
SET(CMAKE_OBJDUMP ${TOOLCHAIN_BIN_DIR}/${TARGET_TRIPLET}-objdump CACHE INTERNAL "objdump tool")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -g" CACHE INTERNAL "c compiler flags debug")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g" CACHE INTERNAL "cxx compiler flags debug")
SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -g" CACHE INTERNAL "asm compiler flags debug")
SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG}" CACHE INTERNAL "linker flags debug")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 " CACHE INTERNAL "c compiler flags release")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 " CACHE INTERNAL "cxx compiler flags release")
SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE}" CACHE INTERNAL "asm compiler flags release")
SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE}" CACHE INTERNAL "linker flags release")

# Ignore warnings about rwx segments introduced in binutils 2.39
execute_process(COMMAND ${CMAKE_C_COMPILER} -print-prog-name=ld RESULT_VARIABLE RUN_C_RESULT OUTPUT_VARIABLE FULL_LD_PATH OUTPUT_STRIP_TRAILING_WHITESPACE)
if (${RUN_C_RESULT} EQUAL 0)
    execute_process(COMMAND ${FULL_LD_PATH} --help RESULT_VARIABLE RUN_LD_RESULT OUTPUT_VARIABLE LD_HELP_OUTPUT OUTPUT_STRIP_TRAILING_WHITESPACE)
    if (${RUN_LD_RESULT} EQUAL 0)
        string(FIND "${LD_HELP_OUTPUT}" "no-warn-rwx-segments" LD_RWX_WARNING_SUPPORTED)
        if (${LD_RWX_WARNING_SUPPORTED} GREATER -1)
            add_link_options("-Wl,--no-warn-rwx-segments")
        endif()
    endif()
endif()

SET(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_DIR}/${TARGET_TRIPLET} ${EXTRA_FIND_PATH})
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

MESSAGE(STATUS "BUILD_TYPE: " ${CMAKE_BUILD_TYPE})

include(${CMAKE_CURRENT_LIST_DIR}/mcux_config.cmake)

if(DEFINED LIBRARY_TYPE)
    if(DEFINED LANGUAGE)
        set_library(${LIBRARY_TYPE} ${LANGUAGE})
    endif()
    if(DEFINED DEBUG_CONSOLE)
        set_debug_console(${DEBUG_CONSOLE} ${LIBRARY_TYPE})
    endif()
endif()

if(DEFINED FPU_TYPE AND DEFINED FPU_ABI)
    set_floating_point(${FPU_TYPE} ${FPU_ABI})
endif()
