# StorPortReadRegisterUshort macro

## Description

The **StorPortReadRegisterUshort** routine reads a value from a specified register address.

## Parameters

### `h` [in]

A Pointer to the hardware device extension.

### `r` [in]

A Pointer to the register where the data is to be read.

## Remarks

For more information, see [ScsiPortReadRegisterUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadregisterushort). For a buffered version of this routine, see [StorPortReadRegisterBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadregisterbufferushort).

## See also

[ScsiPortReadRegisterUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadregisterushort)

[StorPortReadRegisterBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadregisterbufferushort)