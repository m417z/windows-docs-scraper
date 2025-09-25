# LocalFree function

## Description

Frees the specified local memory object and invalidates its handle.

**Note** The local functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a local function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `hMem` [in]

A handle to the local memory object. This handle is returned by either the
[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) or
[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc) function. It is not safe to free memory allocated with [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc).

## Return value

If the function succeeds, the return value is **NULL**.

If the function fails, the return value is equal to a handle to the local memory object. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the process tries to examine or modify the memory after it has been freed, heap corruption may occur or an access violation exception (EXCEPTION_ACCESS_VIOLATION) may be generated.

If the *hMem* parameter is **NULL**,
**LocalFree** ignores the parameter and returns **NULL**.

The
**LocalFree** function will free a locked memory object. A locked memory object has a lock count greater than zero. The
[LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock) function locks a local memory object and increments the lock count by one. The
[LocalUnlock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localunlock) function unlocks it and decrements the lock count by one. To get the lock count of a local memory object, use the
[LocalFlags](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localflags) function.

If an application is running under a debug version of the system,
**LocalFree** will issue a message that tells you that a locked object is being freed. If you are debugging the application,
**LocalFree** will enter a breakpoint just before freeing a locked object. This allows you to verify the intended behavior, then continue execution.

#### Examples

For an example, see
[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc).

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree)

[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc)

[LocalFlags](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localflags)

[LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock)

[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc)

[LocalUnlock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localunlock)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)