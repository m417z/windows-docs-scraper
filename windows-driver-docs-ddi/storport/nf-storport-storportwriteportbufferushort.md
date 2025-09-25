# StorPortWritePortBufferUshort macro

## Description

The **StorPortWritePortBufferUshort** routine writes a value to a specified register address.

## Parameters

### `h`

Pointer to the hardware device extension.

### `p`

Contains the address of the port to be written to.

### `b`

Pointer to the buffer containing the data to be written.

### `c`

Contains the number of data items of size **sizeof**(USHORT) to be written.

## Remarks

For more information, see [ScsiPortWritePortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportwriteportbufferushort). For a non-buffered equivalent of this routine, see [StorPortWritePortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteportushort).

## See also

[ScsiPortWritePortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportwriteportbufferushort)

[StorPortWritePortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteportushort)