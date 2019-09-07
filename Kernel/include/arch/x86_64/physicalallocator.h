#pragma once

#include <paging.h>
#include <serial.h>
#include <string.h>
#include <mischdr.h>

// The size of a block in phyiscal memory
#define PHYSALLOC_BLOCK_SIZE 4096
// The amount of blocks in a byte
#define PHYSALLOC_BLOCKS_PER_BYTE 8

// The size of the memory bitmap in dwords
#define PHYSALLOC_BITMAP_SIZE_DWORDS 524488 // 64GB

extern void* kernel_end;

namespace Memory{

    // Initialize the physical page allocator
    void InitializePhysicalAllocator(memory_info_t* mem_info);

    // Finds the first free block in physical memory
    uint32_t GetFirstFreeMemoryBlock();

    // Marks a region in physical memory as being used
    void MarkMemoryRegionUsed(uint32_t base, size_t size);

    // Marks a region in physical memory as being free
    void MarkMemoryRegionFree(uint32_t base, size_t size) ;

    // Allocates a block of physical memory
    uint64_t AllocatePhysicalMemoryBlock();

    // Allocates a 2MB block of physical memory
    uint64_t AllocateLargePhysicalMemoryBlock();

    // Frees a block of physical memory
    void FreePhysicalMemoryBlock(uint32_t addr);

    // Used Blocks of Memory
    extern uint64_t usedPhysicalBlocks;
}