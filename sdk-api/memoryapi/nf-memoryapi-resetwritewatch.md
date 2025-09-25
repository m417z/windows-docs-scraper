# ResetWriteWatch function

## Description

Resets the
write-tracking state for a region of virtual memory. Subsequent calls to the
[GetWriteWatch](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getwritewatch) function only report pages that are written to since the reset operation.

**64-bit Windows on Itanium-based systems:** Due to the difference in page sizes, **ResetWriteWatch**
is not supported for 32-bit applications.

## Parameters

### `lpBaseAddress` [in]

A pointer to the base address of the memory region for which to reset the write-tracking state.

This address
must be in a memory region that is allocated by the
[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) function with **MEM_WRITE_WATCH**.

### `dwRegionSize` [in]

The size of the memory region for which to reset the write-tracking information, in bytes.

## Return value

If the function succeeds, the return value is 0 (zero).

If the function fails, the return value is a nonzero value.

## Remarks

The **ResetWriteWatch** function can be useful to an
application such as a garbage collector. The application calls the
[GetWriteWatch](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getwritewatch) function to retrieve the list of written
pages, and then writes to those pages as part of its cleanup operation. Then the garbage collector calls
**ResetWriteWatch** to remove the write-tracking records
caused by the cleanup.

You can also reset the write-tracking state of a memory region by specifying **WRITE_WATCH_FLAG_RESET** when you
call [GetWriteWatch](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getwritewatch).

If you use **ResetWriteWatch**, you must ensure that
no threads write to the region during the interval between the
[GetWriteWatch](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getwritewatch) and
**ResetWriteWatch** calls. Otherwise, there may be written
pages that you not detect.

## See also

[GetWriteWatch](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getwritewatch)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)