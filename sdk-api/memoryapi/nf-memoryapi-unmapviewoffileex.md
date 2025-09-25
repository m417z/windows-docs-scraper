# UnmapViewOfFileEx function

## Description

This is an extended version of [UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile) that takes an additional flags parameter.

## Parameters

### `BaseAddress` [in]

A pointer to the base address of the mapped view of a file that is to be unmapped. This value must be identical to the value returned by a previous call
to one of the functions in the
[MapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile) family.

### `UnmapFlags` [in]

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MEM_UNMAP_WITH_TRANSIENT_BOOST**<br><br>0x00000001 | Specifies that the priority of the pages being unmapped should be temporarily boosted (with automatic short term decay) because the caller expects that these pages will be accessed again shortly from another thread. For more information about memory priorities, see the [SetThreadInformation(ThreadMemoryPriority)](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadinformation) function. |
| **MEM_PRESERVE_PLACEHOLDER**<br><br>0x00000002 | Unmaps a mapped view back to a placeholder (after you've replaced a placeholder with a mapped view using [MapViewOfFile3](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-mapviewoffile3) or **MapViewOfFile3FromApp**). |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For more information about the behavior of this function, see the [UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile) function.