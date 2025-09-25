# RTL_SEGMENT_HEAP_MEMORY_SOURCE structure

The **RTL_SEGMENT_HEAP_MEMORY_SOURCE** structure specifies the segment heap memory source.

## Description

## Members

### `Flags`

The flags associated with the segment heap.

### `MemoryTypeMask`

Contains a mask of the [RTL_MEMORY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_rtl_memory_type) members.

### `NumaNode`

Specifies the number of the NUMA node the memory resides on.

### `PartitionHandle`

Handle to the specified partition.

### `Callbacks`

Pointer to a [**RTL_SEGMENT_HEAP_VA_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-rtl_segment_heap_va_callbacks) structure.

### `Reserved`

Reserved for future use.