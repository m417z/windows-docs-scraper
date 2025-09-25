# GlobalHandle function

## Description

Retrieves the handle associated with the specified pointer to a global memory block.

**Note** The global functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a global function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `pMem` [in]

A pointer to the first byte of the global memory block. This pointer is returned by the
[GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock) function.

## Return value

If the function succeeds, the return value is a handle to the specified global memory object.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When the
[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function allocates a memory object with **GMEM_MOVEABLE**, it returns a handle to the object. The
[GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock) function converts this handle into a pointer to the memory block, and
**GlobalHandle** converts the pointer back into a handle.

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc)

[GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)