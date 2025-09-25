# WriteIoSpaceEx64 function

## Description

The **WriteIoSpaceEx64** function is an extended version of [WriteIoSpace64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-writeiospace64). It can write to either a system I/O location or an I/O location on a bus. **WriteIoSpace64** works like **WriteIoSpaceEx64**, except that it defaults *interfacetype* to ISA, *busnumber* to zero, and *addressspace* to 1.

## Parameters

### `address`

Specifies the I/O address to write to.

### `data`

Specifies the address of a variable that holds the data to write. This must be at least the number of bytes contained in *size*.

### `size`

Specifies the address of a variable that contains the number of bytes to write. *Size* must be 1, 2, or 4. After the data is written, *size* will contain the number of bytes actually written.

### `interfacetype`

Specifies the type of interface on which the extended I/O space exists. Possible values include ISA, EISA, and MCA. For more information, see ntddk.h, which is available as part of the Windows Driver Kit.

### `busnumber`

Specifies the number of the bus on which the extended I/O space exists. This is typically zero, unless there is more than one bus of a given type.

### `addressspace`

This is typically 1.

## Remarks

If you are writing 32-bit code, you should use [WriteIoSpaceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-writeiospaceex) instead. See [32-Bit Pointers and 64-Bit Pointers](https://learn.microsoft.com/windows-hardware/drivers/debugger/32-bit-pointers-and-64-bit-pointers) for details.

For a WdbgExts extension, include wdbgexts.h. For a DbgEng extension, include wdbgexts.h before dbgeng.h. See [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details.