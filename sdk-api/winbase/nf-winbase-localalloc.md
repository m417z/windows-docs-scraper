# LocalAlloc function

## Description

Allocates the specified number of bytes from the heap.

**Note** The local functions have greater overhead and provide fewer features than other memory management functions. New applications should use the
[heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a local function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `uFlags` [in]

The memory allocation attributes. The default is the **LMEM_FIXED** value. This parameter can be one or more of the following values, except for the incompatible combinations that are specifically noted.

| Value | Meaning |
| --- | --- |
| **LHND**<br><br>0x0042 | Combines **LMEM_MOVEABLE** and **LMEM_ZEROINIT**. |
| **LMEM_FIXED**<br><br>0x0000 | Allocates fixed memory. The return value is a pointer to the memory object. |
| **LMEM_MOVEABLE**<br><br>0x0002 | Allocates movable memory. Memory blocks are never moved in physical memory, but they can be moved within the default heap. <br><br>The return value is a handle to the memory object. To translate the handle to a pointer, use the [LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock) function.<br><br>This value cannot be combined with **LMEM_FIXED**. |
| **LMEM_ZEROINIT**<br><br>0x0040 | Initializes memory contents to zero. |
| **LPTR**<br><br>0x0040 | Combines **LMEM_FIXED** and **LMEM_ZEROINIT**. |
| **NONZEROLHND** | Same as **LMEM_MOVEABLE**. |
| **NONZEROLPTR** | Same as **LMEM_FIXED**. |

The following values are obsolete, but are provided for compatibility with 16-bit Windows. They are ignored.

**LMEM_DISCARDABLE**

**LMEM_NOCOMPACT**

**LMEM_NODISCARD**

### `uBytes` [in]

The number of bytes to allocate. If this parameter is zero and the *uFlags* parameter specifies **LMEM_MOVEABLE**, the function returns a handle to a memory object that is marked as discarded.

## Return value

If the function succeeds, the return value is a handle to the newly allocated memory object.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Windows memory management does not provide a separate local heap and global heap. Therefore, the **LocalAlloc** and [GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) functions are essentially the same.

The movable-memory flags **LHND**, **LMEM_MOVABLE**, and **NONZEROLHND** add unnecessary overhead and require locking to be used safely. They should be avoided unless documentation specifically states that they should be used.

New applications should use the
[heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless the documentation specifically states that a local function should be used. For example, some Windows functions allocate memory that must be freed with [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

If the heap does not contain sufficient free space to satisfy the request,
**LocalAlloc** returns **NULL**. Because **NULL** is used to indicate an error, virtual address zero is never allocated. It is, therefore, easy to detect the use of a **NULL** pointer.

If the **LocalAlloc** function succeeds, it allocates at least the amount requested. If the amount allocated is greater than the amount requested, the process can use the entire amount. To determine the actual number of bytes allocated, use the
[LocalSize](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localsize) function.

To free the memory, use the
[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function. It is not safe to free memory allocated with **LocalAlloc** using [GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree).

#### Examples

The following code shows a simple use of **LocalAlloc** and [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

```cpp
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

void _cdecl _tmain()
{
    LPTSTR pszBuf=NULL;

    pszBuf = (LPTSTR)LocalAlloc(
              LPTR,
              MAX_PATH*sizeof(TCHAR));

    // Handle error condition
    if( pszBuf == NULL )
    {
       _tprintf(TEXT("LocalAlloc failed (%d)\n"), GetLastError());
       return;
    }

    //see how much memory was allocated
    _tprintf(TEXT("LocalAlloc allocated %d bytes\n"), LocalSize(pszBuf));

    // Use the memory allocated

    // Free the memory when finished with it
    LocalFree(pszBuf);
}

```

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[Heap Functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock)

[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc)

[LocalSize](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localsize)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)