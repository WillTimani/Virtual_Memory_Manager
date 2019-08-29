
/* Configures program constants */

#pragma once

/* Address */
constexpr auto ADDRESS_SIZE = 16U; // Number of address bits
constexpr auto DISPLACEMENT_SIZE = 8U; // Number of address bits used for displacement/offset
constexpr auto PAGE_NUMBER_SIZE = (ADDRESS_SIZE - DISPLACEMENT_SIZE); // Number of address bits used for page number
constexpr auto FRAME_NUMBER_SIZE = (ADDRESS_SIZE - DISPLACEMENT_SIZE); // Number of address bits used for frame number

constexpr auto VM_SIZE = 256; // Amount of virtual memory
constexpr auto RAM_SIZE = 128; // Amount of physical memory

/* Page table */
constexpr auto PAGE_SIZE = 256; // Page size
constexpr auto PAGE_COUNT = (RAM_SIZE / PAGE_SIZE); // Number of pages

/* TLB */
constexpr auto TLB_SIZE = 16; // TLB entries

/* Frame */
constexpr auto FRAME_SIZE = 256; // Frame size
constexpr auto FRAME_COUNT = (RAM_SIZE / FRAME_SIZE); // Number of frames