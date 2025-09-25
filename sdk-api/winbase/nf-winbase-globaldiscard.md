# GlobalDiscard macro

## Description

Discards the specified global memory block. The lock count of the memory object must be zero.

**Note** The global functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a global function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `h` [in]

A handle to the global memory object. This handle is returned by either the
[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) or
[GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) function.

## Remarks

Although
**GlobalDiscard** discards the object's memory block, the handle to the object remains valid. The process can subsequently pass the handle to the
[GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) function to allocate another global memory block identified by the same handle.

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc)

[GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)