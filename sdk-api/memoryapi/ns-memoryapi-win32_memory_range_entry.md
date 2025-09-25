# WIN32_MEMORY_RANGE_ENTRY structure

## Description

Specifies a range of memory. This structure is used by the
[PrefetchVirtualMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-prefetchvirtualmemory) function.

## Members

### `VirtualAddress`

### `NumberOfBytes`

## Remarks

To compile an application that calls this function, define **_WIN32_WINNT** as
**_WIN32_WINNT_WIN8** or higher. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Memory Management Structures](https://learn.microsoft.com/windows/desktop/Memory/memory-management-structures)

[PrefetchVirtualMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-prefetchvirtualmemory)