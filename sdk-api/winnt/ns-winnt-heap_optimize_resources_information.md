# HEAP_OPTIMIZE_RESOURCES_INFORMATION structure

## Description

Specifies flags for a HeapOptimizeResources operation initiated with [HeapSetInformation](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapsetinformation).

## Members

### `Version`

### `Flags`

## Remarks

Mandatory parameter to the HeapOptimizeResources class.

The **HEAP_OPTIMIZE_RESOURCES_CURRENT_VERSION** constant is available to fill in the Version field of the **HEAP_OPTIMIZE_RESOURCES_INFORMATION** structure. The only legal value for this field is currently 1.

## See also

[Memory Management Structures](https://learn.microsoft.com/windows/desktop/Memory/memory-management-structures)

[PrefetchVirtualMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-prefetchvirtualmemory)