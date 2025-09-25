# LocalLock function

## Description

Locks a local memory object and returns a pointer to the first byte of the object's memory block.

**Note** The local functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a local function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `hMem` [in]

A handle to the local memory object. This handle is returned by either the
[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) or
[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc) function.

## Return value

If the function succeeds, the return value is a pointer to the first byte of the memory block.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The internal data structures for each memory object include a lock count that is initially zero. For movable memory objects,
**LocalLock** increments the count by one, and the
[LocalUnlock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localunlock) function decrements the count by one. Each successful call that a process makes to
**LocalLock** for an object must be matched by a corresponding call to
**LocalUnlock**. Locked memory will not be moved or discarded unless the memory object is reallocated by using the
[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc) function. The memory block of a locked memory object remains locked in memory until its lock count is decremented to zero, at which time it can be moved or discarded.

Memory objects allocated with **LMEM_FIXED** always have a lock count of zero. For these objects, the value of the returned pointer is equal to the value of the specified handle.

If the specified memory block has been discarded or if the memory block has a zero-byte size, this function returns **NULL**.

Discarded objects always have a lock count of zero.

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc)

[LocalFlags](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localflags)

[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc)

[LocalUnlock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localunlock)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)