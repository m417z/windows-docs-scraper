# StorPortWritePortUchar macro

## Description

The **StorPortWritePortUchar** routine writes a value to a specified register address.

## Parameters

### `h`

Pointer to the hardware device extension.

### `p`

Contains the address of the port to be written to.

### `v`

Contains the value to be written.

## Remarks

For more information, see [ScsiPortWritePortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportwriteportuchar). For a buffered equivalent of this routine, see [StorPortWritePortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteportbufferuchar).

## See also

[ScsiPortWritePortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportwriteportuchar)

[StorPortWritePortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteportbufferuchar)