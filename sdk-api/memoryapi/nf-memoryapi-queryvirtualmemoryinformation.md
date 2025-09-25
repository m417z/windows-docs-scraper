# QueryVirtualMemoryInformation function

## Description

The **QueryVirtualMemoryInformation** function returns information about a page or a set of pages within the virtual address space of the specified process.

## Parameters

### `Process` [in]

A handle for the process in whose context the pages to be queried reside.

### `VirtualAddress` [in]

The address of the region of pages to be queried. This value is rounded down to the next host-page-address boundary.

### `MemoryInformationClass` [in]

The memory information class about which to retrieve information. The only supported value is **MemoryRegionInfo**.

### `MemoryInformation` [out]

A pointer to a buffer that receives the specified information.

If the *MemoryInformationClass* parameter has a value of **MemoryRegionInfo**, this parameter must point to a [WIN32_MEMORY_REGION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/memoryapi/ns-memoryapi-win32_memory_region_information) structure.

### `MemoryInformationSize` [in]

Specifies the length in bytes of the memory information buffer.

### `ReturnSize` [out, optional]

An optional pointer which, if specified, receives the number of bytes placed in the memory information buffer.

## Return value

Returns **TRUE** on success. Returns **FALSE** for failure. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the *MemoryInformationClass* parameter has a value of **MemoryRegionInfo**, the *MemoryInformation* parameter must point to a [WIN32_MEMORY_REGION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/memoryapi/ns-memoryapi-win32_memory_region_information) structure. The *VirtualAddress* parameter must point to an address within a valid memory allocation. If the *VirtualAddress* parameter points to an unallocated memory region, the function fails.

## See also

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-memory_basic_information)

[WIN32_MEMORY_REGION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/memoryapi/ns-memoryapi-win32_memory_region_information)