# FreeUserPhysicalPages function

## Description

Frees
physical memory pages that are allocated previously by using
[AllocateUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-allocateuserphysicalpages) or [AllocateUserPhysicalPagesNuma](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-allocateuserphysicalpagesnuma). If any of these
pages are currently mapped in the [Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions) (AWE) region, they are automatically unmapped by this call. This does not
affect the virtual address space that is occupied by a specified Address Windowing Extensions (AWE) region.

**64-bit Windows on Itanium-based systems:** Due to the difference in page sizes,
**FreeUserPhysicalPages** is not supported for
32-bit applications.

## Parameters

### `hProcess` [in]

The handle to a process.

The function frees memory within the virtual address space of this process.

### `NumberOfPages` [in, out]

The size of the physical memory to free, in pages.

On return, if the function fails, this parameter indicates
the number of pages that are freed.

### `PageArray` [in]

A pointer to an array of page frame numbers of the allocated memory to be freed.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. In this case, the *NumberOfPages*
parameter reflect how many pages have actually been released. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

In a multiprocessor environment, this function maintains coherence of the hardware translation buffer. When this function returns, all threads on all processors are guaranteed to see the correct mapping.

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0500 or later. For more
information, see [Using the Windows
Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

For an example, see [AWE Example](https://learn.microsoft.com/windows/desktop/Memory/awe-example).

## See also

[Address Windowing Extensions](https://learn.microsoft.com/windows/desktop/Memory/address-windowing-extensions)

[AllocateUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-allocateuserphysicalpages)

[AllocateUserPhysicalPagesNuma](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-allocateuserphysicalpagesnuma)

[MapUserPhysicalPages](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapuserphysicalpages)

[MapUserPhysicalPagesScatter](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-mapuserphysicalpagesscatter)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)