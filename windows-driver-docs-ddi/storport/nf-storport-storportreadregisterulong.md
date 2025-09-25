# StorPortReadRegisterUlong macro

## Description

The **StorPortReadRegisterUlong** routine reads a value from a specified register address.

## Parameters

### `h` [in]

A pointer to the hardware device extension.

### `r` [in]

Pointer to the register where the data is to be read.

## Remarks

For more information, see [ScsiPortReadRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadregisterulong). For a buffered version of this routine, see [StorPortReadRegisterBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadregisterbufferulong).

## See also

[ScsiPortReadRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadregisterulong)

[StorPortReadRegisterBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadregisterbufferulong)