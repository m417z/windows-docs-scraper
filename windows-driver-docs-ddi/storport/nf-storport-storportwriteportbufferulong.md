# StorPortWritePortBufferUlong macro

## Description

The **StorPortWritePortBufferUlong** routine writes a value to a specified register address.

## Parameters

### `h`

Pointer to the hardware device extension.

### `p`

Contains the address of the port to be written to.

### `b`

Pointer to the buffer containing the data to be written.

### `c`

Contains the number of data items of size **sizeof**(ULONG) to be written.

## Remarks

For more information, see [ScsiPortWritePortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportwriteportbufferulong). For a nonbuffered equivalent of this routine, see [StorPortWritePortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteportulong).

## See also

[ScsiPortWritePortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportwriteportbufferulong)

[StorPortWritePortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteportulong)