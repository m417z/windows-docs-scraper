# LocalReAlloc function

## Description

Changes the size or the attributes of a specified local memory object. The size can increase or decrease.

**Note** The local functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a local function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `hMem` [in]

A handle to the local memory object to be reallocated. This handle is returned by either the
[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) or
**LocalReAlloc** function.

### `uBytes` [in]

The new size of the memory block, in bytes. If *uFlags* specifies **LMEM_MODIFY**, this parameter is ignored.

### `uFlags` [in]

The reallocation options. If **LMEM_MODIFY** is specified, the function modifies the attributes of the memory object only (the *uBytes* parameter is ignored.) Otherwise, the function reallocates the memory object.

You can optionally combine **LMEM_MODIFY** with the following value.

| Value | Meaning |
| --- | --- |
| **LMEM_MOVEABLE**<br><br>0x0002 | Allocates fixed or movable memory. <br><br>If the memory is a locked **LMEM_MOVEABLE** memory block or a **LMEM_FIXED** memory block and this flag is not specified, the memory can only be reallocated in place. |

If this parameter does not specify **LMEM_MODIFY**, you can use the following value.

| Value | Meaning |
| --- | --- |
| **LMEM_ZEROINIT**<br><br>0x0040 | Causes the additional memory contents to be initialized to zero if the memory object is growing in size. |

## Return value

If the function succeeds, the return value is a handle to the reallocated memory object.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If
**LocalReAlloc** fails, the original memory is not freed, and the original handle and pointer are still valid.

If
**LocalReAlloc** reallocates a fixed object, the value of the handle returned is the address of the first byte of the memory block. To access the memory, a process can simply cast the return value to a pointer.

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)