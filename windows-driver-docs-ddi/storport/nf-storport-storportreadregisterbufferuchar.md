# StorPortReadRegisterBufferUchar macro

## Description

The **StorPortReadRegisterBufferUchar** routine reads a value from a specified register address.

## Parameters

### `h` [in]

A Pointer to the hardware device extension.

### `r` [in]

Pointer to the register where the data is to be read.

### `b` [in]

A pointer to the buffer that receives the data that is read.

### `c` [in]

Number of data items to be read. Each data item has a size of **sizeof**(UCHAR).

## Remarks

For more information, see [ScsiPortReadRegisterBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadregisterbufferuchar). For a nonbuffered version of this routine, see [StorPortReadRegisterUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadregisteruchar).

## See also

[ScsiPortReadRegisterBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadregisterbufferuchar)

[StorPortReadRegisterUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadregisteruchar)