# VirtualProtectFromApp function

## Description

Changes the protection on a region of committed pages in the virtual address space of the calling
process.

## Parameters

### `Address` [in]

A pointer an address that describes the starting page of the region of pages whose access protection
attributes are to be changed.

All pages in the specified region must be within the same reserved region allocated when calling the
[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc), [VirtualAllocFromApp](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocfromapp), or
[VirtualAllocEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocex) function using
**MEM_RESERVE**. The pages cannot span adjacent reserved regions that were allocated by
separate calls to **VirtualAlloc**, **VirtualAllocFromApp**, or
**VirtualAllocEx** using
**MEM_RESERVE**.

### `Size` [in]

The size of the region whose access protection attributes are to be changed, in bytes. The region of
affected pages includes all pages containing one or more bytes in the range from the
*Address* parameter to
`(Address+Size)`. This means that a 2-byte range
straddling a page boundary causes the protection attributes of both pages to be changed.

### `NewProtection` [in]

The memory protection option. This parameter can be one of the
[memory protection constants](https://learn.microsoft.com/windows/desktop/Memory/memory-protection-constants).

For mapped views, this value must be compatible with the access protection specified when the view was
mapped (see [MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile),
[MapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffileex), and
[MapViewOfFileExNuma](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-mapviewoffileexnuma)).

The following constants generate an error:

* **PAGE_EXECUTE_READWRITE**
* **PAGE_EXECUTE_WRITECOPY**

The following constants are allowed only for apps that have the **codeGeneration** capability:

* **PAGE_EXECUTE**
* **PAGE_EXECUTE_READ**

### `OldProtection` [out]

A pointer to a variable that receives the previous access protection value of the first page in the
specified region of pages. If this parameter is **NULL** or does not point to a valid
variable, the function fails.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You can call **VirtualProtectFromApp** from Windows Store apps with just-in-time (JIT) capabilities to use JIT functionality. The app must include the **codeGeneration** capability in the app manifest file to use JIT capabilities.

You can set the access protection value on committed pages only. If the state of any page in the specified
region is not committed, the function fails and returns without modifying the access protection of any pages in the
specified region.

The **PAGE_GUARD** protection modifier establishes guard pages. Guard pages act as
one-shot access alarms. For more information, see
[Creating Guard Pages](https://learn.microsoft.com/windows/desktop/Memory/creating-guard-pages).

It is best to avoid using **VirtualProtectFromApp** to change
page protections on memory blocks allocated by [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc),
[HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc), or
[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc), because multiple memory blocks can exist on a
single page. The heap manager assumes that all pages in the heap grant at least read and write access.

**VirtualProtectFromApp** allows you to mark pages as executable, but does not allow you to set both write and execute permissions at the same time.

When protecting a region that will be executable, the calling program bears responsibility for ensuring cache
coherency via an appropriate call to
[FlushInstructionCache](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-flushinstructioncache) once the code has been set
in place. Otherwise attempts to execute code out of the newly executable region may produce unpredictable
results.

## See also

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[Virtual Memory Functions](https://learn.microsoft.com/windows/desktop/Memory/virtual-memory-functions)

[VirtualAllocFromApp](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocfromapp)

[VirtualProtect](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualprotect)

[VirtualProtectEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualprotectex)