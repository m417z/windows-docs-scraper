# MapViewOfFileNuma2 function

## Description

Maps a view of a file or a pagefile-backed section into the address
space of the specified process.

## Parameters

### `FileMappingHandle` [in]

A **HANDLE** to a section that is to be mapped
into the address space of the specified process.

### `ProcessHandle` [in]

A **HANDLE** to a process into which the section
will be mapped.

### `Offset` [in]

The offset from the beginning of the section.
This must be 64k aligned.

### `BaseAddress` [in, optional]

The desired base address of the view.
The address is rounded down to the nearest 64k boundary.
If this parameter is **NULL**, the system picks the base
address.

### `ViewSize` [in]

The number of bytes to map. A value of zero
(0) specifies that the entire section is to be mapped.

### `AllocationType` [in]

The type of allocation. This parameter can be zero (0) or one of the following constant values:

* **MEM_RESERVE** - Maps a reserved view
* **MEM_LARGE_PAGES** - Maps a large page view

### `PageProtection` [in]

The desired page protection.

For file-mapping objects created with the **SEC_IMAGE** attribute, the
*PageProtection* parameter has no effect, and should be set to any valid value such as
**PAGE_READONLY**.

### `PreferredNode` [in]

The preferred NUMA node for this memory.

## Return value

Returns the base address of the mapped view, if successful. Otherwise, returns **NULL** and extended error status is available
using [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile)

[MapViewOfFileNuma](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffilenuma2)