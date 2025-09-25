# GlobalUnlock function

## Description

Decrements the lock count associated with a memory object that was allocated with **GMEM_MOVEABLE**. This function has no effect on memory objects allocated with **GMEM_FIXED**.

**Note** The global functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a global function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `hMem` [in]

A handle to the global memory object. This handle is returned by either the
[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) or
[GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) function.

## Return value

If the memory object is still locked after decrementing the lock count, the return value is a nonzero value. If the memory object is unlocked after decrementing the lock count, the function returns zero and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **NO_ERROR**.

If the function fails, the return value is zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns a value other than **NO_ERROR**.

## Remarks

The internal data structures for each memory object include a lock count that is initially zero. For movable memory objects, the
[GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock) function increments the count by one, and
**GlobalUnlock** decrements the count by one. For each call that a process makes to
**GlobalLock** for an object, it must eventually call
**GlobalUnlock**. Locked memory will not be moved or discarded, unless the memory object is reallocated by using the
[GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) function. The memory block of a locked memory object remains locked until its lock count is decremented to zero, at which time it can be moved or discarded.

Memory objects allocated with **GMEM_FIXED** always have a lock count of zero. If the specified memory block is fixed memory, this function returns **TRUE**.

If the memory object is already unlocked,
**GlobalUnlock** returns **FALSE** and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) reports **ERROR_NOT_LOCKED**.

A process should not rely on the return value to determine the number of times it must subsequently call
**GlobalUnlock** for a memory object.

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc)

[GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock)

[GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)