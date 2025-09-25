# LocalSize function

## Description

Retrieves the current size of the specified local memory object, in bytes.

**Note** The local functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a local function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `hMem` [in]

A handle to the local memory object. This handle is returned by the
[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc),
[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc), or
[LocalHandle](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localhandle) function.

## Return value

If the function succeeds, the return value is the size of the specified local memory object, in bytes. If the specified handle is not valid or if the object has been discarded, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The size of a memory block may be larger than the size requested when the memory was allocated.

To verify that the specified object's memory block has not been discarded, call the
[LocalFlags](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localflags) function before calling
**LocalSize**.

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc)

[LocalFlags](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localflags)

[LocalHandle](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localhandle)

[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)