# StorPortWritePortUlong macro

## Description

The **StorPortWritePortUlong** routine writes a value to a specified register address.

## Parameters

### `h`

Pointer to the hardware device extension.

### `p`

Contains the address of the port to be written to.

### `v`

Contains the value to be written.

## Remarks

For more information, see [ScsiPortWritePortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportwriteportulong). For a buffered equivalent of this routine, see [StorPortWritePortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteportbufferulong).

## See also

[ScsiPortWritePortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportwriteportulong)

[StorPortWritePortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteportbufferulong)