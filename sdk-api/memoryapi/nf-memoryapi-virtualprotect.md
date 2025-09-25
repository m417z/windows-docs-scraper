# VirtualProtect function

## Description

Changes the protection on a region of committed pages in the virtual address space of the calling process.

To change the access protection of any process, use the [VirtualProtectEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualprotectex) function.

## Parameters

### `lpAddress` [in]

The address of the starting page of the region of pages whose access protection attributes are to be changed.

All pages in the specified region must be within the same reserved region allocated when calling the [VirtualAlloc](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc) or [VirtualAllocEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualallocex) function using **MEM_RESERVE**. The pages cannot span adjacent reserved regions that were allocated by separate calls to **VirtualAlloc** or **VirtualAllocEx** using **MEM_RESERVE**.

### `dwSize` [in]

The size of the region whose access protection attributes are to be changed, in bytes. The region of affected pages includes all pages containing one or more bytes in the range from the ***lpAddress*** parameter to `(lpAddress+dwSize)`. This means that a 2-byte range straddling a page boundary causes the protection attributes of both pages to be changed.

### `flNewProtect` [in]

The memory protection option. This parameter can be one of the [memory protection constants](https://learn.microsoft.com/windows/win32/Memory/memory-protection-constants).

For mapped views, this value must be compatible with the access protection specified when the view was mapped (see [MapViewOfFile](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile), [MapViewOfFileEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffileex), and [MapViewOfFileExNuma](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-mapviewoffileexnuma)).

### `lpflOldProtect` [out]

A pointer to a variable that receives the previous access protection value of the first page in the specified region of pages. If this parameter is **NULL** or does not point to a valid variable, the function fails.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You can set the access protection value on committed pages only. If the state of any page in the specified region is not committed, the function fails and returns without modifying the access protection of any pages in the specified region.

The **PAGE_GUARD** protection modifier establishes guard pages. Guard pages act as one-shot access alarms. For more information, see [Creating Guard Pages](https://learn.microsoft.com/windows/win32/Memory/creating-guard-pages).

It is best to avoid using **VirtualProtect** to change page protections on memory blocks allocated by [GlobalAlloc](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalalloc), [HeapAlloc](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapalloc), or [LocalAlloc](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-localalloc), because multiple memory blocks can exist on a single page. The heap manager assumes that all pages in the heap grant at least read and write access.

When protecting a region that will be executable, the calling program bears responsibility for ensuring cache coherency via an appropriate call to [FlushInstructionCache](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-flushinstructioncache) once the code has been set in place. Otherwise attempts to execute code out of the newly executable region may produce unpredictable results.

## See also

[Memory Management Functions](https://learn.microsoft.com/windows/win32/Memory/memory-management-functions)

[Memory Protection Constants](https://learn.microsoft.com/windows/win32/Memory/memory-protection-constants)

[Virtual Memory Functions](https://learn.microsoft.com/windows/win32/Memory/virtual-memory-functions)

[VirtualAlloc](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc)

[VirtualProtectEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualprotectex)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)