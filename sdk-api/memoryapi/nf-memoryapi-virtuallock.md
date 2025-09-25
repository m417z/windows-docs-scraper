# VirtualLock function

## Description

Locks the specified region of the process's virtual address space into physical memory, ensuring that subsequent access to the region will not incur a page fault.

## Parameters

### `lpAddress` [in]

A pointer to the base address of the region of pages to be locked.

### `dwSize` [in]

The size of the region to be locked, in bytes. The region of affected pages includes all pages that contain one or more bytes in the range from the *lpAddress* parameter to `(lpAddress+dwSize)`. This means that a 2-byte range straddling a page boundary causes both pages to be locked.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All pages in the specified region must be committed. Memory protected with **PAGE_NOACCESS** cannot be locked.

Locking pages into memory may degrade the performance of the system by reducing the available RAM and forcing the system to swap out other critical pages to the paging file. Each version of Windows has a limit on the maximum number of pages a process can lock. This limit is intentionally small to avoid severe performance degradation. Applications that need to lock larger numbers of pages must first call the
[SetProcessWorkingSetSize](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-setprocessworkingsetsize) function to increase their minimum and maximum working set sizes. The maximum number of pages that a process can lock is equal to the number of pages in its minimum working set minus a small overhead.

Pages that a process has locked remain in physical memory until the process unlocks them or terminates. These pages are guaranteed not to be written to the pagefile while they are locked.

To unlock a region of locked pages, use the
[VirtualUnlock](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualunlock) function. Locked pages are automatically unlocked when the process terminates.

This function is not like the
[GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock) or
[LocalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-locallock) function in that it does not increment a lock count and translate a handle into a pointer. There is no lock count for virtual pages, so multiple calls to the
[VirtualUnlock](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualunlock) function are never required to unlock a region of pages.

#### Examples

For an example, see
[Creating Guard Pages](https://learn.microsoft.com/windows/desktop/Memory/creating-guard-pages).

## See also

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[SetProcessWorkingSetSize](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-setprocessworkingsetsize)

[Virtual Memory Functions](https://learn.microsoft.com/windows/desktop/Memory/virtual-memory-functions)

[VirtualUnlock](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualunlock)