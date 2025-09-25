# StorPortReadRegisterBufferUshort macro

## Description

The **StorPortReadRegisterBufferUshort** routine reads a value from a specified register address.

## Parameters

### `h` [in]

A pointer to the hardware device extension.

### `r` [in]

A pointer to the register where the data is to be read.

### `b` [in]

A pointer to the buffer that receives the data that is read.

### `c` [in]

The number of data items to be read. Each data item has a size of ```sizeof(USHORT)```.

## Remarks

For more information, see [**ScsiPortReadRegisterBufferUshort**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadregisterbufferushort). For a nonbuffered version of this routine, see [**StorPortReadRegisterUshort**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadregisterushort).