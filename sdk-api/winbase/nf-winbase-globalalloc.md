# GlobalAlloc function

## Description

Allocates the specified number of bytes from the heap.

**Note** The global functions have greater overhead and provide fewer features than other memory management functions. New applications should use the
[heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a global function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `uFlags` [in]

The memory allocation attributes. If zero is specified, the default is **GMEM_FIXED**. This parameter can be one or more of the following values, except for the incompatible combinations that are specifically noted.

| Value | Meaning |
| --- | --- |
| **GHND**<br><br>0x0042 | Combines **GMEM_MOVEABLE** and **GMEM_ZEROINIT**. |
| **GMEM_FIXED**<br><br>0x0000 | Allocates fixed memory. The return value is a pointer. |
| **GMEM_MOVEABLE**<br><br>0x0002 | Allocates movable memory. Memory blocks are never moved in physical memory, but they can be moved within the default heap.<br><br>The return value is a handle to the memory object. To translate the handle into a pointer, use the [GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock) function.<br><br>This value cannot be combined with **GMEM_FIXED**. |
| **GMEM_ZEROINIT**<br><br>0x0040 | Initializes memory contents to zero. |
| **GPTR**<br><br>0x0040 | Combines **GMEM_FIXED** and **GMEM_ZEROINIT**. |

The following values are obsolete, but are provided for compatibility with 16-bit Windows. They are ignored.

**GMEM_DDESHARE**

**GMEM_DISCARDABLE**

**GMEM_LOWER**

**GMEM_NOCOMPACT**

**GMEM_NODISCARD**

**GMEM_NOT_BANKED**

**GMEM_NOTIFY**

**GMEM_SHARE**

### `dwBytes` [in]

The number of bytes to allocate. If this parameter is zero and the *uFlags* parameter specifies **GMEM_MOVEABLE**, the function returns a handle to a memory object that is marked as discarded.

## Return value

If the function succeeds, the return value is a handle to the newly allocated memory object.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Windows memory management does not provide a separate local heap and global heap. Therefore, the **GlobalAlloc** and [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) functions are essentially the same.

The movable-memory flags **GHND** and **GMEM_MOVABLE** add unnecessary overhead and require locking to be used safely. They should be avoided unless documentation specifically states that they should be used.

New applications should use the
[heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) to allocate and manage memory unless the documentation specifically states that a global function should be used. For example, the global functions are still used with Dynamic Data Exchange (DDE), the clipboard functions, and OLE data objects.

If the **GlobalAlloc** function succeeds, it allocates at least the amount of memory requested. If the actual amount allocated is greater than the amount requested, the process can use the entire amount. To determine the actual number of bytes allocated, use the
[GlobalSize](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalsize) function.

If the heap does not contain sufficient free space to satisfy the request,
**GlobalAlloc** returns **NULL**. Because **NULL** is used to indicate an error, virtual address zero is never allocated. It is, therefore, easy to detect the use of a **NULL** pointer.

Memory allocated with this function is guaranteed to be aligned on an 8-byte boundary. To execute dynamically generated code, use the [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) function to allocate memory and the [VirtualProtect](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualprotect) function to grant **PAGE_EXECUTE** access.

To free the memory, use the
[GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree) function. It is not safe to free memory allocated with **GlobalAlloc** using [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

#### Examples

The following code shows a simple use of **GlobalAlloc** and [GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree).

```cpp
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

void _cdecl main()
{
    PSECURITY_DESCRIPTOR pSD;

    pSD = (PSECURITY_DESCRIPTOR) GlobalAlloc(
           GMEM_FIXED,
           sizeof(PSECURITY_DESCRIPTOR));

    // Handle error condition
    if( pSD == NULL )
    {
       _tprintf(TEXT("GlobalAlloc failed (%d)\n"), GetLastError());
       return;
    }

    //see how much memory was allocated
    _tprintf(TEXT("GlobalAlloc allocated %d bytes\n"), GlobalSize(pSD));

    // Use the memory allocated

    // Free the memory when finished with it
    GlobalFree(pSD);
}

```

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[GlobalDiscard](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaldiscard)

[GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree)

[GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock)

[GlobalSize](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalsize)

[Heap Functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)