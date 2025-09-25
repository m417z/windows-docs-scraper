# GlobalFlags function

## Description

Retrieves information about the specified global memory object.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions). For more information, see Remarks.

## Parameters

### `hMem` [in]

A handle to the global memory object. This handle is returned by either the
[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) or
[GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) function.

## Return value

If the function succeeds, the return value specifies the allocation values and the lock count for the memory object.

If the function fails, the return value is **GMEM_INVALID_HANDLE**, indicating that the global handle is not valid. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The low-order byte of the low-order word of the return value contains the lock count of the object. To retrieve the lock count from the return value, use the **GMEM_LOCKCOUNT** mask with the bitwise AND (&) operator. The lock count of memory objects allocated with **GMEM_FIXED** is always zero.

The high-order byte of the low-order word of the return value indicates the allocation values of the memory object. It can be zero or **GMEM_DISCARDED**.

The global functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a global function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc)

[GlobalDiscard](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaldiscard)

[GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)