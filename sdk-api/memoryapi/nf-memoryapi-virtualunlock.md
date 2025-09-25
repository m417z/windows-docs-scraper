# VirtualUnlock function

## Description

Unlocks a specified range of pages in the virtual address space of a process, enabling the system to swap the pages out to the paging file if necessary.

## Parameters

### `lpAddress` [in]

A pointer to the base address of the region of pages to be unlocked.

### `dwSize` [in]

The size of the region being unlocked, in bytes. The region of affected pages includes all pages containing one or more bytes in the range from the *lpAddress* parameter to `(lpAddress+dwSize)`. This means that a 2-byte range straddling a page boundary causes both pages to be unlocked.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For the function to succeed, the range specified need not match a range passed to a previous call to the
[VirtualLock](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtuallock) function, but all pages in the range must be locked. If any of the pages in the specified range are not locked, **VirtualUnlock** removes such pages from the working set, sets last error to **ERROR_NOT_LOCKED**, and returns **FALSE**.

Calling
**VirtualUnlock** on a range of memory that is not locked releases the pages from the process's working set.

## See also

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[Virtual Memory Functions](https://learn.microsoft.com/windows/desktop/Memory/virtual-memory-functions)

[VirtualLock](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtuallock)