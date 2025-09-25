# StorPortReadRegisterUchar macro

## Description

The **StorPortReadRegisterUchar** routine reads a value from a specified register address.

## Parameters

### `h` [in]

A pointer to the hardware device extension.

### `r` [in]

A pointer to the register where the data is to be read.

## Remarks

For more information, see [ScsiPortReadRegisterUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadregisteruchar). For a buffered version of this routine, see [StorPortReadRegisterBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadregisterbufferuchar).

## See also

[ScsiPortReadRegisterUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadregisteruchar)

[StorPortReadRegisterBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadregisterbufferuchar)