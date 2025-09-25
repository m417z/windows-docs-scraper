# UnmapViewOfFile2 function

## Description

Unmaps a previously mapped view of a file or a
pagefile-backed section.

## Parameters

### `Process` [in]

A **HANDLE** to the process from which the section
will be unmapped.

### `BaseAddress` [in]

The base address of a previously mapped
view that is to be unmapped. This value must be
identical to the value returned by a previous call
to one of the functions in the
[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile) family.

### `UnmapFlags` [in]

This parameter can be zero (0) or one of the following values.

| Value | Meaning |
| --- | --- |
| **MEM_UNMAP_WITH_TRANSIENT_BOOST**<br><br>0x00000001 | Specifies that the priority of the pages being unmapped should be temporarily boosted (with automatic short term decay) because the caller expects that these pages will be accessed again shortly from another thread. For more information about memory priorities, see the [SetThreadInformation(ThreadMemoryPriority)](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadinformation) function. |
| **MEM_PRESERVE_PLACEHOLDER**<br><br>0x00000002 | Unmaps a mapped view back to a placeholder (after you've replaced a placeholder with a mapped view using [MapViewOfFile3](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile3) or **MapViewOfFile3FromApp**). |

## Return value

Returns **TRUE** if successful. Otherwise, returns **FALSE** and extended error status is available
using [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[MapViewOfFile2](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile2)

[UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile)

[UnmapViewOfFileEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffileex)