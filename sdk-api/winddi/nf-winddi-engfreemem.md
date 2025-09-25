# EngFreeMem macro

## Description

The **EngFreeMem** function deallocates a block of system memory.

## Parameters

### `p` [in]

Pointer to the block of memory being deallocated.

## Remarks

This routine releases memory allocated by [EngAllocMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocmem). The memory block must not be accessed after it is freed.

## See also

[EngAllocMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocmem)