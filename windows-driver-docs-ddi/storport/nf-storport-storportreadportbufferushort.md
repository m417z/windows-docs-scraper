# StorPortReadPortBufferUshort macro

## Description

The **StorPortReadPortBufferUshort** routine reads a value from a specified port address.

## Parameters

### `h` [in]

A pointer to the hardware device extension.

### `p` [in]

A pointer to the address from which to read.

### `b` [in]

Pointer to the buffer that receives the data that is read.

### `c` [in]

Number of data items to be read. Each data item has a size of **sizeof**(USHORT).

## Remarks

For more information, see [ScsiPortReadPortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadportbufferushort). For a nonbuffered version of this routine, see [StorPortReadPortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadportushort).

## See also

[ScsiPortReadPortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadportbufferushort)

[StorPortReadPortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadportushort)