# GlobalReAlloc function

## Description

Changes the size or attributes of a specified global memory object. The size can increase or decrease.

**Note** The global functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a global function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `hMem` [in]

A handle to the global memory object to be reallocated. This handle is returned by either the
[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) or
**GlobalReAlloc** function.

### `dwBytes` [in]

The new size of the memory block, in bytes. If *uFlags* specifies **GMEM_MODIFY**, this parameter is ignored.

### `uFlags` [in]

The reallocation options. If **GMEM_MODIFY** is specified, the function modifies the attributes of the memory object only (the *dwBytes* parameter is ignored.) Otherwise, the function reallocates the memory object.

You can optionally combine **GMEM_MODIFY** with the following value.

| Value | Meaning |
| --- | --- |
| **GMEM_MOVEABLE**<br><br>0x0002 | Allocates movable memory.<br><br>If the memory is a locked **GMEM_MOVEABLE** memory block or a **GMEM_FIXED** memory block and this flag is not specified, the memory can only be reallocated in place. |

If this parameter does not specify **GMEM_MODIFY**, you can use the following value.

| Value | Meaning |
| --- | --- |
| **GMEM_ZEROINIT**<br><br>0x0040 | Causes the additional memory contents to be initialized to zero if the memory object is growing in size. |

## Return value

If the function succeeds, the return value is a handle to the reallocated memory object.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If
**GlobalReAlloc** reallocates a movable object, the return value is a handle to the memory object. To convert the handle to a pointer, use the
[GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock) function.

If
**GlobalReAlloc** reallocates a fixed object, the value of the handle returned is the address of the first byte of the memory block. To access the memory, a process can simply cast the return value to a pointer.

If
**GlobalReAlloc** fails, the original memory is not freed, and the original handle and pointer are still valid.

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc)

[GlobalDiscard](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaldiscard)

[GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)