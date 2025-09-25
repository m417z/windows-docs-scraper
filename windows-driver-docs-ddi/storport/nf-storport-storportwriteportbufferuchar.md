# StorPortWritePortBufferUchar macro

## Description

The **StorPortWritePortBufferUchar** routine writes a value to a specified register address.

## Parameters

### `h`

Pointer to the hardware device extension.

### `p`

Contains the address of the port to be written to.

### `b`

Pointer to the buffer containing the data to be written.

### `c`

Contains the number of data items of size **sizeof**(UCHAR) to be written.

## Remarks

For more information, see [ScsiPortWritePortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportwriteportbufferuchar). For a nonbuffered equivalent of this routine, see [StorPortWritePortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteportuchar).

## See also

[ScsiPortWritePortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportwriteportbufferuchar)

[StorPortWritePortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteportuchar)