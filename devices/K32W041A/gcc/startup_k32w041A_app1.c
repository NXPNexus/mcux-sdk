//*****************************************************************************
// K32W041A Microcontroller Startup code for use with LPCXpresso IDE
//
// Version : 141204
//*****************************************************************************
//
// Copyright 2014, NXP
// All rights reserved.
//
// SPDX-License-Identifier: BSD-3-Clause
//*****************************************************************************

#if defined(__cplusplus)
#ifdef __REDLIB__
#error Redlib does not support C++
#else
//*****************************************************************************
//
// The entry point for the C++ library startup
//
//*****************************************************************************
extern "C" {
extern void __libc_init_array(void);
}
#endif
#endif

#define WEAK __attribute__((weak))
#define ALIAS(f) __attribute__((weak, alias(#f)))

//*****************************************************************************
#if defined(__cplusplus)
extern "C" {
#endif

#define EMPTY_VALUE (void (*const)(void))0xffffffff

//*****************************************************************************
//
// Forward declaration of the default handlers. These are aliased.
// When the application defines a handler (with the same name), this will
// automatically take precedence over these weak definitions
//
//*****************************************************************************
void ResetISR(void);

WEAK void pvAPI_JumpTable(void);

//*****************************************************************************
//
// External declaration for the pointer to the App0 jump table
//
//*****************************************************************************
extern unsigned int *pu32App0JumpTable;

//*****************************************************************************
#if defined(__cplusplus)
} // extern "C"
#endif
//*****************************************************************************
//
// The vector table.
// This relies on the linker script to place at correct location in memory.
//
//*****************************************************************************
extern void (*const g_pfnVectors[])(void);
__attribute__((used, section(".isr_vector"))) void (*const g_pfnVectors[])(void) = {
    // Core Level - CM4
    EMPTY_VALUE,     // The initial stack pointer
    ResetISR,        // The reset handler
    EMPTY_VALUE,     // The NMI handler
    EMPTY_VALUE,     // The hard fault handler
    EMPTY_VALUE,     // The MPU fault handler
    EMPTY_VALUE,     // The bus fault handler
    EMPTY_VALUE,     // The usage fault handler
    0,               // Reserved: Post-build step (jn518x_image_tool.py)
    0,               // Reserved: Post-build step (jn518x_image_tool.py)
    0,               // Reserved: Post-build step (jn518x_image_tool.py)
    0,               // Reserved: Post-build step (jn518x_image_tool.py)
    EMPTY_VALUE,     // SVCall handler
    EMPTY_VALUE,     // Debug monitor handler
    pvAPI_JumpTable, // Reserved: Function look-up table
};                   /* End of g_pfnVectors */

//*****************************************************************************
// Functions to carry out the initialization of RW and BSS data sections. These
// are written as separate functions rather than being inlined within the
// ResetISR() function in order to cope with MCUs with multiple banks of
// memory.
//*****************************************************************************
__attribute__((section(".after_vectors"))) void data_init(unsigned int romstart, unsigned int start, unsigned int len)
{
    unsigned int *pulDest = (unsigned int *)start;
    unsigned int *pulSrc  = (unsigned int *)romstart;
    unsigned int loop;
    for (loop = 0; loop < len; loop = loop + 4)
        *pulDest++ = *pulSrc++;
}

__attribute__((section(".after_vectors"))) void bss_init(unsigned int start, unsigned int len)
{
    unsigned int *pulDest = (unsigned int *)start;
    unsigned int loop;
    for (loop = 0; loop < len; loop = loop + 4)
        *pulDest++ = 0;
}

//*****************************************************************************
// The following symbols are constructs generated by the linker, indicating
// the location of various points in the "Global Section Table". This table is
// created by the linker via the Code Red managed linker script mechanism. It
// contains the load address, execution address and length of each RW data
// section and the execution and length of each BSS (zero initialized) section.
//*****************************************************************************
extern unsigned int __data_section_table;
extern unsigned int __data_section_table_end;
extern unsigned int __bss_section_table;
extern unsigned int __bss_section_table_end;

//*****************************************************************************
// Reset entry point for your code.
// Sets up a simple runtime environment and initializes the C/C++
// library.
//*****************************************************************************

__attribute__((section(".after_vectors.reset"))) void ResetISR(void)
{
    //
    // Copy the data sections from flash to SRAM.
    //
    unsigned int LoadAddr, ExeAddr, SectionLen;
    unsigned int *SectionTableAddr;

    // Load base address of Global Section Table
    SectionTableAddr = &__data_section_table;

    // Copy the data sections from flash to SRAM.
    while (SectionTableAddr < &__data_section_table_end)
    {
        LoadAddr   = *SectionTableAddr++;
        ExeAddr    = *SectionTableAddr++;
        SectionLen = *SectionTableAddr++;
        data_init(LoadAddr, ExeAddr, SectionLen);
    }
    // At this point, SectionTableAddr = &__bss_section_table;
    // Zero fill the bss segment
    while (SectionTableAddr < &__bss_section_table_end)
    {
        ExeAddr    = *SectionTableAddr++;
        SectionLen = *SectionTableAddr++;
        bss_init(ExeAddr, SectionLen);
    }

    /* Set the jump table into App0 here, using the value in App0's header */
    pu32App0JumpTable = *(unsigned int **)(0x34);
}
