# ReadPhysicalWithFlags function

## Description

The **ReadPhysicalWithFlags** function reads from physical memory.

## Parameters

### `address`

Specifies the physical address to read.

### `buf`

Specifies the address of an array of bytes to hold the data that is read.

### `size`

Specifies the number of bytes to read.

### `flags`

Specifies the properties of the physical memory to be read. This must match the way the physical memory was advertised to the operating system on the target. Possible values are listed in the following table.

| Value | Description |
| --- | --- |
| PHYS_FLAG_DEFAULT | Use the default memory caching. |
| PHYS_FLAG_CACHED | The physical memory is cached. |
| PHYS_FLAG_UNCACHED | The physical memory is uncached. |
| PHYS_FLAG_WRITE_COMBINED | The physical memory is write-combined. |

### `sizer`

Receives the number of bytes actually read.

## Remarks

If you are writing a WdbgExts extension, include **wdbgexts.h**. If you are writing a DbgEng extension that calls this function, include **wdbgexts.h** before **dbgeng.h** (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details).

## See also

[ReadPhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readphysical)

[WritePhysicalWithFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-writephysicalwithflags)