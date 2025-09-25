# WritePhysical function

## Description

The **WritePhysical** function writes to physical memory.

## Parameters

### `address` [in]

Specifies the physical address to write.

### `buf` [in]

Specifies the address of an array of bytes to hold the data that is written.

### `size` [in]

Specifies the number of bytes to write.

### `sizew` [out, optional]

Receives the number of bytes actually written.

## Remarks

For a WdbgExts extension, include wdbgexts.h. For a DbgEng extension, include wdbgexts.h before dbgeng.h. See [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details.