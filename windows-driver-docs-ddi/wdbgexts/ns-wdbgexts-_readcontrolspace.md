# _READCONTROLSPACE structure

## Description

The **ReadControlSpace** function reads the processor-specific control space into the array pointed to by *buf*.

## Members

### `Processor`

Specifies the number of the processor whose control space is to be read.

### `Address`

Specifies the address of the control space.

### `BufLen`

The length of the buffer.

### `Buf[1]`

Specifies the object into which the control space data is read.

## Remarks

If you are writing 64-bit code, you should use [ReadControlSpace64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readcontrolspace64) instead. See [32-Bit Pointers and 64-Bit Pointers](https://learn.microsoft.com/windows-hardware/drivers/debugger/32-bit-pointers-and-64-bit-pointers) for details.

If you are writing a WdbgExts extension, include **wdbgexts.h**. If you are writing a DbgEng extension that calls this function, include **wdbgexts.h** before **dbgeng.h** (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details).