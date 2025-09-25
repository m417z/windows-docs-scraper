# GlobalFree function

## Description

Frees the specified global memory object and invalidates its handle.

**Note** The global functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a global function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `hMem` [in]

A handle to the global memory object. This handle is returned by either the
[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) or
[GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) function. It is not safe to free memory allocated with [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc).

## Return value

If the function succeeds, the return value is **NULL**.

If the function fails, the return value is equal to a handle to the global memory object. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the process examines or modifies the memory after it has been freed, heap corruption may occur or an access violation exception (EXCEPTION_ACCESS_VIOLATION) may be generated.

The
**GlobalFree** function will free a locked memory object. A locked memory object has a lock count greater than zero. The
[GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock) function locks a global memory object and increments the lock count by one. The
[GlobalUnlock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalunlock) function unlocks it and decrements the lock count by one. To get the lock count of a global memory object, use the
[GlobalFlags](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalflags) function.

If an application is running under a debug version of the system,
**GlobalFree** will issue a message that tells you that a locked object is being freed. If you are debugging the application,
**GlobalFree** will enter a breakpoint just before freeing a locked object. This allows you to verify the intended behavior, then continue execution.

#### Examples

For an example, see
[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc).

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc)

[GlobalFlags](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalflags)

[GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock)

[GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc)

[GlobalUnlock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalunlock)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)