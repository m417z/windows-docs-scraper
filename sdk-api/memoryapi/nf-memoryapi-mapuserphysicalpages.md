# MapUserPhysicalPages function

## Description

Maps
previously allocated physical memory pages at a specified address in an
[Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions) (AWE) region.

To perform batch mapping and unmapping of multiple regions, use the
[MapUserPhysicalPagesScatter](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-mapuserphysicalpagesscatter) function.

**64-bit Windows on Itanium-based systems:** Due to the difference in page sizes,
**MapUserPhysicalPages** is not supported for 32-bit
applications.

## Parameters

### `VirtualAddress` [in]

A pointer to the starting address of the region of memory to remap.

The value of
*lpAddress* must be within the address range that the
[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) function returns when the [Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions) (AWE) region is
allocated.

### `NumberOfPages` [in]

The size of the physical memory and virtual address space for which to establish translations, in pages.

The
virtual address range is contiguous starting at *lpAddress*. The physical frames are
specified by the *UserPfnArray*.

The total number of pages cannot extend from the
starting address beyond the end of the range that is specified in
[AllocateUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-allocateuserphysicalpages).

### `PageArray` [in]

A pointer to an array of physical page frame numbers.

These frames are mapped by the argument
*lpAddress* on return from this function. The size of the memory that is allocated should be
at least the *NumberOfPages* times the size of the data type
**ULONG_PTR**.

Do not attempt to modify this buffer. It contains operating system data, and corruption could be
catastrophic. The information in the buffer is not useful to an application.

If this parameter is **NULL**, the specified address range is unmapped. Also, the specified physical pages are not
freed, and you must call [FreeUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-freeuserphysicalpages) to
free them.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE** and no mapping is done—partial or otherwise.
To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The physical pages are unmapped but they are not freed. You must call
[FreeUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-freeuserphysicalpages) to free the
physical pages.

Any number of physical memory pages can be specified, but the memory must not extend outside the virtual
address space that [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) allocates. Any
existing address maps are automatically overwritten with the new translations, and the old translations are
unmapped.

You cannot map physical memory pages outside the range that is specified in
[AllocateUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-allocateuserphysicalpages). You
can map multiple regions simultaneously, but they cannot overlap.

Physical pages can be located at any physical address, but do not make assumptions about the contiguity of the
physical pages.

To unmap the current address range, specify **NULL** as the physical memory page array parameter. Any
currently mapped pages are unmapped, but are not freed. You must call
[FreeUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-freeuserphysicalpages) to free the
physical pages.

In a multiprocessor environment, this function maintains hardware translation buffer coherence. On return
from this function, all threads on all processors are guaranteed to see the correct mapping.

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0500 or later. For more
information, see [Using the Windows
Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

For an example, see [AWE Example](https://learn.microsoft.com/windows/desktop/Memory/awe-example).

## See also

[Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions)

[AllocateUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-allocateuserphysicalpages)

[FreeUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-freeuserphysicalpages)

[MapUserPhysicalPagesScatter](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-mapuserphysicalpagesscatter)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)