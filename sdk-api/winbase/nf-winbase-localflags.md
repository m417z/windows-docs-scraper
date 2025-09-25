# LocalFlags function

## Description

Retrieves information about the specified local memory object.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions). For more information, see Remarks.

## Parameters

### `hMem` [in]

A handle to the local memory object. This handle is returned by either the
[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) or
[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc) function.

## Return value

If the function succeeds, the return value specifies the allocation values and the lock count for the memory object.

If the function fails, the return value is **LMEM_INVALID_HANDLE**, indicating that the local handle is not valid. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The low-order byte of the low-order word of the return value contains the lock count of the object. To retrieve the lock count from the return value, use the **LMEM_LOCKCOUNT** mask with the bitwise AND (&) operator. The lock count of memory objects allocated with **LMEM_FIXED** is always zero.

The high-order byte of the low-order word of the return value indicates the allocation values of the memory object. It can be zero or **LMEM_DISCARDABLE**.

The local functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a local function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[GlobalFlags](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalflags)

[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc)

[LocalDiscard](https://learn.microsoft.com/windows/desktop/api/minwinbase/nf-minwinbase-localdiscard)

[LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock)

[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc)

[LocalUnlock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localunlock)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)