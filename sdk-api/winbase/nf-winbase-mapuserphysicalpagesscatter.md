# MapUserPhysicalPagesScatter function

## Description

Maps previously allocated physical memory pages at a specified address in an
[Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions) (AWE) region.

**64-bit Windows on Itanium-based systems:** Due to the difference in page sizes,
**MapUserPhysicalPagesScatter** is not
supported for 32-bit applications.

## Parameters

### `VirtualAddresses` [in]

A pointer to an array of starting addresses of the regions of memory to remap.

Each entry in
*VirtualAddresses* must be within the address range that the
[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) function returns when the [Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions) (AWE) region is
allocated. The value in *NumberOfPages* indicates the size of the array. Entries can be from multiple Address Windowing Extensions (AWE) regions.

### `NumberOfPages` [in]

The size of the physical memory and virtual address space for which to establish translations, in pages.

The
array at *VirtualAddresses* specifies the virtual address range.

### `PageArray` [in]

A pointer to an array of values that indicates how each corresponding page in
*VirtualAddresses* should be treated.

A 0 (zero) indicates that the corresponding entry in
*VirtualAddresses* should be unmapped, and any nonzero value that it has should be mapped.

If this parameter is **NULL**, then every address in the *VirtualAddresses* array is
unmapped.

The value in *NumberOfPages* indicates the size of the array.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**, and the function does not map or unmap—partial or
otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The physical pages may be unmapped, but they are not freed. You must call
[FreeUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-freeuserphysicalpages) to free the physical
pages.

You can specify any number of physical memory pages, but the memory cannot extend outside the virtual
address space that is allocated by [VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc). Any
existing address maps are automatically overwritten with the new translations, and the old translations are
unmapped.

You cannot map physical memory pages outside the range that is specified in
[AllocateUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-allocateuserphysicalpages). You can map
multiple regions simultaneously, but they cannot overlap.

Physical pages can be located at any physical address, but do not make assumptions about the contiguity of the
physical pages.

In a multiprocessor environment, this function maintains hardware translation buffer coherence. On return
from this function, all threads on all processors are guaranteed to see the correct mapping.

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0500 or later. For more
information, see [Using the Windows
Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions)

[AllocateUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-allocateuserphysicalpages)

[FreeUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-freeuserphysicalpages)

[MapUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapuserphysicalpages)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)