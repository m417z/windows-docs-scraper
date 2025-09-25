# EngAllocMem macro

## Description

The **EngAllocMem** function allocates a block of memory and inserts a caller-supplied tag before the allocation.

## Parameters

### `flags` [in]

Specifies how to allocate memory. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| FL_NONPAGED_MEMORY | Allocate memory from the nonpaged pool. If this flag is not set, the memory is allocated from the system's paged pool. |
| FL_ZERO_MEMORY | Zero-initialize the allocated memory. If this flag is not set, the memory is returned uninitialized. |

### `cj` [in]

Specifies the number of bytes to allocate.

### `tag` [in]

Specifies a 4-byte [pool tag](https://learn.microsoft.com/windows-hardware/drivers/) that uniquely identifies the driver that does the memory allocation. For more information about pool tags, see [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-exallocatepoolwithtag).

## Remarks

When the memory is no longer needed, it should be freed by a call to the **EngFreeMem** function.

## See also

[EngFreeMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreemem)