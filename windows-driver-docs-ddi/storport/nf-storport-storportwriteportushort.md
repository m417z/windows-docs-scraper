# StorPortWritePortUshort macro

## Description

The **StorPortWritePortUshort** routine writes a value to a specified register address.

## Parameters

### `h`

Pointer to the hardware device extension.

### `p`

Contains the address of the port to be written to.

### `v`

Contains the value to be written.

## Remarks

For more information, see [ScsiPortWritePortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportwriteportushort). For a buffered equivalent of this routine, see [StorPortWritePortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteportbufferushort).

## See also

[ScsiPortWritePortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportwriteportushort)

[StorPortWritePortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteportbufferushort)