# WriteIoSpace function

## Description

The **WriteIoSpace** function writes to the system I/O locations.

## Parameters

### `address`

Specifies the I/O address to write to.

### `data`

Specifies the address of a variable that holds the data to write. This must be at least the number of bytes contained in *size*.

### `size`

Specifies the address of a variable that contains the number of bytes to write. *Size* must be 1, 2, or 4. After the data is written, *size* will contain the number of bytes actually written.

## Remarks

If you are writing 64-bit code, you should use [WriteIoSpace64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-writeiospace64) instead. See [32-Bit Pointers and 64-Bit Pointers](https://learn.microsoft.com/windows-hardware/drivers/debugger/32-bit-pointers-and-64-bit-pointers) for details.

For a WdbgExts extension, include wdbgexts.h. For a DbgEng extension, include wdbgexts.h before dbgeng.h. See [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details.