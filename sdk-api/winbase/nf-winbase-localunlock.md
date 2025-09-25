# LocalUnlock function

## Description

Decrements the lock count associated with a memory object that was allocated with **LMEM_MOVEABLE**. This function has no effect on memory objects allocated with **LMEM_FIXED**.

**Note** The local functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a local function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `hMem` [in]

A handle to the local memory object. This handle is returned by either the
[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) or
[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc) function.

## Return value

If the memory object is still locked after decrementing the lock count, the return value is nonzero. If the memory object is unlocked after decrementing the lock count, the function returns zero and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **NO_ERROR**.

If the function fails, the return value is zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns a value other than **NO_ERROR**.

## Remarks

The internal data structures for each memory object include a lock count that is initially zero. For movable memory objects, the
[LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock) function increments the count by one, and
**LocalUnlock** decrements the count by one. For each call that a process makes to
**LocalLock** for an object, it must eventually call
**LocalUnlock**. Locked memory will not be moved or discarded unless the memory object is reallocated by using the
[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc) function. The memory block of a locked memory object remains locked until its lock count is decremented to zero, at which time it can be moved or discarded.

If the memory object is already unlocked,
**LocalUnlock** returns **FALSE** and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) reports **ERROR_NOT_LOCKED**. Memory objects allocated with **LMEM_FIXED** always have a lock count of zero and cause the **ERROR_NOT_LOCKED** error.

A process should not rely on the return value to determine the number of times it must subsequently call
**LocalUnlock** for the memory block.

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc)

[LocalFlags](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localflags)

[LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock)

[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)