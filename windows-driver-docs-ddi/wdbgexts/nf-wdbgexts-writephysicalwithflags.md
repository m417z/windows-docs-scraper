# WritePhysicalWithFlags function

## Description

The **WritePhysicalWithFlags** function writes to physical memory.

## Parameters

### `address`

Specifies the physical address to write.

### `buf`

Specifies the address of an array of bytes to hold the data that is written.

### `size`

Specifies the number of bytes to write.

### `flags`

Specifies the properties of the physical memory to be written to. This must match the way the physical memory was advertised to the operating system on the target. Possible values are listed in the following table.

| Value | Description |
| --- | --- |
| PHYS_FLAG_DEFAULT | Use the default memory caching. |
| PHYS_FLAG_CACHED | The physical memory is cached. |
| PHYS_FLAG_UNCACHED | The physical memory is uncached. |
| PHYS_FLAG_WRITE_COMBINED | The physical memory is write-combined. |

### `sizew`

Receives the number of bytes actually written.

## Remarks

For a WdbgExts extension, include wdbgexts.h. For a DbgEng extension, include wdbgexts.h before dbgeng.h. See [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details.

## See also

[ReadPhysicalWithFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readphysicalwithflags)

[WritePhysical](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-writephysical)