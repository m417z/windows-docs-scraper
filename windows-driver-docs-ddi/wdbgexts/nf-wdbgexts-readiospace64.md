# ReadIoSpace64 function

## Description

The **ReadIoSpace64** function reads from the system I/O locations.

## Parameters

### `address`

Specifies the I/O address to read from.

### `data`

Specifies the address of a variable to hold the data read. This must be at least the number of bytes contained in *size*.

### `size`

Specifies the address of a variable that contains the number of bytes to read. *Size* must be 1, 2, or 4. After the data is read, *size* will contain the number of bytes actually read.

## Remarks

If you are writing 32-bit code, you should use [ReadIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readiospace) instead. See [32-Bit Pointers and 64-Bit Pointers](https://learn.microsoft.com/windows-hardware/drivers/debugger/32-bit-pointers-and-64-bit-pointers) for details.

If you are writing a WdbgExts extension, include **wdbgexts.h**. If you are writing a DbgEng extension that calls this function, include **wdbgexts.h** before **dbgeng.h** (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details).