# MapViewOfFile2 function

## Description

Maps a view of a file or a pagefile-backed section into the address
space of the specified process.

## Parameters

### `FileMappingHandle` [in]

A **HANDLE** to a section that is to be mapped
into the address space of the specified process.

### `ProcessHandle` [in]

A **HANDLE** to a process into which the section
will be mapped. The handle must have the **PROCESS_VM_OPERATION** access mask.

### `Offset` [in]

The offset from the beginning of the section.
This must be 64k aligned.

### `BaseAddress` [in, optional]

The desired base address of the view.
The address is rounded down to the nearest 64k boundary.
If this parameter is **NULL**, the system picks the base
address.

### `ViewSize` [in]

The number of bytes to map. A value of zero (0)
specifies that the entire section is to be mapped.

### `AllocationType` [in]

The type of allocation. This parameter can be zero (0) or one of the following constant values:

* **MEM_RESERVE** - Maps a reserved view.
* **MEM_LARGE_PAGES** - Maps a large page view. This flag specifies that the view should be mapped using [large page support](https://learn.microsoft.com/windows/win32/memory/large-page-support). The size of the view must be a multiple of the size of a large page reported by the [GetLargePageMinimum](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-getlargepageminimum) function, and the file-mapping object must have been created using the **SEC_LARGE_PAGES** option. If you provide a non-null value for the *BaseAddress* parameter, then the value must be a multiple of **GetLargePageMinimum**.

### `PageProtection` [in]

The desired page protection.

For file-mapping objects created with the **SEC_IMAGE** attribute, the
*PageProtection* parameter has no effect, and should be set to any valid value such as
**PAGE_READONLY**.

## Return value

Returns the base address of the mapped view, if successful. Otherwise, returns **NULL** and extended error status is available
using [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is implemented as an inline function in the header and can't be found in any export library or DLL. It's the same as calling [MapViewOfFileNuma2](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffilenuma2) with the last parameter set to ``NUMA_NO_PREFERRED_NODE``.

## See also

[MapViewOfFile](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile)

[MapViewOfFileNuma2](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffilenuma2)