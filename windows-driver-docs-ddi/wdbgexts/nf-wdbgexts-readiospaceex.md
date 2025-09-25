# ReadIoSpaceEx function

## Description

The **ReadIoSpaceEx** function is an extended version of [ReadIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readiospace). It reads not only the system I/O locations, but also I/O locations on a bus. **ReadIoSpace** works like **ReadIoSpaceEx**, except that it defaults *interfacetype* to ISA, *busnumber* to zero, and *addressspace* to 1.

## Parameters

### `address`

Specifies the I/O address to read from.

### `data`

Specifies the address of a variable to hold the data read. This must be at least the number of bytes contained in *size*.

### `size`

Specifies the address of a variable that contains the number of bytes to read. *Size* must be 1, 2, or 4. After the data is read, *size* will contain the number of bytes actually read.

### `interfacetype`

Specifies the type of interface on which the extended I/O space exists. Possible values include ISA, EISA, and MCA. For more information, see ntddk.h, which is available as part of Windows Driver Kit.

### `busnumber`

Specifies the number of the bus on which the extended I/O space exists. This is typically zero, unless there is more than one bus of a given type.

### `addressspace`

This is typically 1.

## Remarks

If you are writing 64-bit code, you should use [ReadIoSpaceEx64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readiospaceex64) instead. See [32-Bit Pointers and 64-Bit Pointers](https://learn.microsoft.com/windows-hardware/drivers/debugger/32-bit-pointers-and-64-bit-pointers) for details.

If you are writing a WdbgExts extension, include **wdbgexts.h**. If you are writing a DbgEng extension that calls this function, include **wdbgexts.h** before **dbgeng.h** (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details).