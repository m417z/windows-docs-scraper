# PrefetchVirtualMemory function

## Description

Provides an efficient mechanism to bring into memory potentially discontiguous virtual address ranges
in a process address space.

## Parameters

### `hProcess` [in]

Handle to the process whose virtual address ranges are to be prefetched. Use the
[GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) function to use the current
process.

### `NumberOfEntries` [in]

Number of entries in the array pointed to by the *VirtualAddresses*
parameter.

### `VirtualAddresses` [in]

Pointer to an array of
[WIN32_MEMORY_RANGE_ENTRY](https://learn.microsoft.com/windows/desktop/api/memoryapi/ns-memoryapi-win32_memory_range_entry) structures which
each specify a virtual address range to be prefetched. The virtual address ranges may cover any part of the
process address space accessible by the target process.

### `Flags` [in]

Reserved. Must be 0.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **PrefetchVirtualMemory** function is
targeted at applications that know with reasonable confidence the set of addresses they will be accessing. If
it's likely that these addresses are no longer resident in memory (i.e. they have been paged out to disk),
calling the **PrefetchVirtualMemory** function on
those address ranges before access will reduce the overall latency because the API will efficiently bring in
those address ranges from disk using large, concurrent I/O requests where possible.

The **PrefetchVirtualMemory** function allows
applications to make efficient use of disk hardware by issuing large, concurrent I/Os where possible when the
application provides a list of process address ranges that are going to be accessed. Even for a single address
range (e.g. a file mapping), the
**PrefetchVirtualMemory** function can provide
performance improvements by issuing a single large I/O rather than the many smaller I/Os that would be issued via
page faulting.

The **PrefetchVirtualMemory** function is purely
a performance optimization: prefetching is not necessary for accessing the target address ranges. The prefetched
memory is not added to the target process' working set; it is cached in physical memory. When the prefetched
address ranges are accessed by the target process, they will be added to the working set.

Since the **PrefetchVirtualMemory** function can
never be necessary for correct operation of applications, it is treated as a strong hint by the system and is
subject to usual physical memory constraints where it can completely or partially fail under low-memory
conditions. It can also create memory pressure if called with large address ranges, so applications should only
prefetch address ranges they will actually use.

To compile an application that calls this function, define **_WIN32_WINNT** as
**_WIN32_WINNT_WIN8** or higher. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[WIN32_MEMORY_RANGE_ENTRY](https://learn.microsoft.com/windows/desktop/api/memoryapi/ns-memoryapi-win32_memory_range_entry)