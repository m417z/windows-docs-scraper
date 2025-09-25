# GetWriteWatch function

## Description

Retrieves the addresses of
the pages that are written to in a region of virtual memory.

**64-bit Windows on Itanium-based systems:** Due to the difference in page sizes, **GetWriteWatch**
is not supported for 32-bit applications.

## Parameters

### `dwFlags` [in]

Indicates whether the function resets the write-tracking state.

To reset the write-tracking state, set this
parameter to **WRITE_WATCH_FLAG_RESET**. If this parameter is 0 (zero),
**GetWriteWatch** does not reset the write-tracking state.
For more information, see the Remarks section of this topic.

### `lpBaseAddress` [in]

The base address of the memory region for which to retrieve write-tracking information.

This address must be in
a memory region that is allocated by the [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)
function using **MEM_WRITE_WATCH**.

### `dwRegionSize` [in]

The size of the memory region for which to retrieve write-tracking information, in bytes.

### `lpAddresses` [out]

A pointer to a buffer that receives an array of page addresses in the memory region.

The addresses indicate
the pages that have been written to since the region has been allocated or the write-tracking state has been reset.

### `lpdwCount` [in, out]

On input, this variable indicates the size of the *lpAddresses* array, in array
elements.

On output, the variable receives the number of page addresses that are returned in the array.

### `lpdwGranularity` [out]

A pointer to a variable that receives the page size, in bytes.

## Return value

If the function succeeds, the return value is 0 (zero).

If the function fails, the return value is a nonzero value.

## Remarks

When you call the [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) function
to reserve or commit memory, you can specify **MEM_WRITE_WATCH**. This value causes the system to keep track of the
pages that are written to in the committed memory region. You can call the
**GetWriteWatch** function to retrieve the addresses of the
pages that have been written to since the region has been allocated or the write-tracking state has been reset.

To reset the write-tracking state, set the **WRITE_WATCH_FLAG_RESET** value in the
*dwFlags* parameter. Alternatively, you can call the
[ResetWriteWatch](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-resetwritewatch) function to reset the write-tracking
state. However, if you use **ResetWriteWatch**, you must
ensure that no threads write to the region during the interval between the
**GetWriteWatch** and
**ResetWriteWatch** calls. Otherwise, there may be written
pages that you do not detect.

The **GetWriteWatch** function can be useful to
profilers, debugging tools, or garbage collectors.

## See also

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[ResetWriteWatch](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-resetwritewatch)

[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)