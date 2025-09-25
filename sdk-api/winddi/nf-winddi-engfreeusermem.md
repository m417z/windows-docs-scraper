# EngFreeUserMem macro

## Description

The **EngFreeUserMem** function deallocates a block of user memory.

## Parameters

### `p` [in]

Pointer to the block of user memory being deallocated.

## Remarks

This routine releases memory allocated by [EngAllocUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocusermem). The memory block must not be accessed after it is freed.

## See also

[EngAllocUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocusermem)