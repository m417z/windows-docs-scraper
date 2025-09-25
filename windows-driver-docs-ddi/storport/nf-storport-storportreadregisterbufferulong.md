# StorPortReadRegisterBufferUlong macro

## Description

The **StorPortReadRegisterBufferUlong** routine reads a value from a specified register address.

## Parameters

### `h` [in]

A pointer to the hardware device extension.

### `r` [in]

Pointer to the register where the data is to be read.

### `b` [in]

Pointer to the buffer that receives the data that is read.

### `c` [in]

Specifies the number of data items to be read. Each data item has a size of **sizeof**(ULONG).

## Remarks

For more information, see [ScsiPortReadRegisterBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadregisterbufferulong). For a nonbuffered version of this routine, see [StorPortReadRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadregisterulong).

## See also

[ScsiPortReadRegisterBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadregisterbufferulong)

[StorPortReadRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadregisterulong)