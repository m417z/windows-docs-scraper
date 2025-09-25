# LocalHandle function

## Description

Retrieves the handle associated with the specified pointer to a local memory object.

**Note** The local functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a local function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `pMem` [in]

A pointer to the first byte of the local memory object. This pointer is returned by the
[LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock) function.

## Return value

If the function succeeds, the return value is a handle to the specified local memory object.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When the
[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) function allocates a local memory object with **LMEM_MOVEABLE**, it returns a handle to the object. The
[LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock) function converts this handle into a pointer to the object's memory block, and
**LocalHandle** converts the pointer back into a handle.

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc)

[LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)