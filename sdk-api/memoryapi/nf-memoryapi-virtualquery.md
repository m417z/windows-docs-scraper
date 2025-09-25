# VirtualQuery function

## Description

Retrieves information about a range of pages in the virtual address space of the calling process.

To retrieve information about a range of pages in the address space of another process, use the [VirtualQueryEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualqueryex) function.

## Parameters

### `lpAddress` [in, optional]

A pointer to the base address of the region of pages to be queried. This value is rounded down to the next page boundary. To determine the size of a page on the host computer, use the [GetSystemInfo](https://learn.microsoft.com/windows/win32/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function.

If *lpAddress* specifies an address above the highest memory address accessible to the process, the function fails with **ERROR_INVALID_PARAMETER**.

### `lpBuffer` [out]

A pointer to a [MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-memory_basic_information) structure in which information about the specified page range is returned.

### `dwLength` [in]

The size of the buffer pointed to by the *lpBuffer* parameter, in bytes.

## Return value

The return value is the actual number of bytes returned in the information buffer.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error values include **ERROR_INVALID_PARAMETER**.

## Remarks

**VirtualQuery** provides information about a region of consecutive pages beginning at a specified address that share the following attributes:

- The state of all pages is the same (**MEM_COMMIT**, **MEM_RESERVE**, **MEM_FREE**, **MEM_PRIVATE**, **MEM_MAPPED**, or **MEM_IMAGE**).
- If the initial page is not free, all pages in the region are part of the same initial allocation of pages created by a single call to [VirtualAlloc](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc), [MapViewOfFile](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile), or one of the following extended versions of these functions: [VirtualAllocEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualallocex), [VirtualAllocExNuma](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualallocexnuma), [MapViewOfFileEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffileex), [MapViewOfFileExNuma](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-mapviewoffileexnuma).
- The access granted to all pages is the same (**PAGE_READONLY**, **PAGE_READWRITE**, **PAGE_NOACCESS**, **PAGE_WRITECOPY**, **PAGE_EXECUTE**, **PAGE_EXECUTE_READ**, **PAGE_EXECUTE_READWRITE**, **PAGE_EXECUTE_WRITECOPY**, **PAGE_GUARD**, or **PAGE_NOCACHE**).

The function determines the attributes of the first page in the region and then scans subsequent pages until it scans the entire range of pages or until it encounters a page with a non-matching set of attributes. The function returns the attributes and the size of the region of pages with matching attributes, in bytes. For example, if there is a 40 megabyte (MB) region of free memory, and **VirtualQuery** is called on a page that is 10 MB into the region, the function will obtain a state of **MEM_FREE** and a size of 30 MB.

If a shared copy-on-write page is modified, it becomes private to the process that modified the page. However, the **VirtualQuery** function will continue to report such pages as **MEM_MAPPED** (for data views) or **MEM_IMAGE** (for executable image views) rather than **MEM_PRIVATE**. To detect whether copy-on-write has occurred for a specific page, either access the page or lock it using the [VirtualLock](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtuallock) function to make sure the page is resident in memory, then use the [QueryWorkingSetEx](https://learn.microsoft.com/windows/win32/api/psapi/nf-psapi-queryworkingsetex) function to check the **Shared** bit in the extended working set information for the page. If the **Shared** bit is clear, the page is private.

This function reports on a region of pages in the memory of the calling process, and the [VirtualQueryEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualqueryex) function reports on a region of pages in the memory of a specified process.

## See also

[GetSystemInfo](https://learn.microsoft.com/windows/win32/api/sysinfoapi/nf-sysinfoapi-getsysteminfo)

[MEMORY_BASIC_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-memory_basic_information)

[MapViewOfFile](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile)

[Memory Management Functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[Virtual Memory Functions](https://learn.microsoft.com/windows/win32/Memory/virtual-memory-functions)

[VirtualQueryEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualqueryex)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)