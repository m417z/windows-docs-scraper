# EngSecureMem function

## Description

The **EngSecureMem** function locks down the specified address range in memory.

## Parameters

### `Address` [in]

Pointer to the base address of the memory to be secured.

### `Length` [in]

Specifies the size of the memory range to be secured.

## Return value

**EngSecureMem** returns a handle to the secured address range upon successful completion; otherwise, it returns **NULL**.

## Remarks

The address range locked down by **EngSecureMem** will not be deallocated until it is unlocked by [EngUnsecureMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunsecuremem).