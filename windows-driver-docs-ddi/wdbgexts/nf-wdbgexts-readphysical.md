# ReadPhysical function

## Description

The **ReadPhysical** function reads from physical memory.

## Parameters

### `address`

Specifies the physical address to read.

### `buf`

Specifies the address of an array of bytes to hold the data that is read.

### `size`

Specifies the number of bytes to read.

### `sizer`

Receives the number of bytes actually read.

## Remarks

If you are writing a WdbgExts extension, include **wdbgexts.h**. If you are writing a DbgEng extension that calls this function, include **wdbgexts.h** before **dbgeng.h** (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details).