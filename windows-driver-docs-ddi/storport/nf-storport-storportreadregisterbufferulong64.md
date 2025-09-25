# StorPortReadRegisterBufferUlong64 macro

## Description

This **StorPortReadRegisterBufferUlong64** routine reads a number of **ULONG64** values from the specified 64-bit register address into a buffer.

## Parameters

### `h` [in]

A pointer to the hardware device extension.

### `r` [in]

A pointer to the register where the data is to be read. The register must be a mapped range in memory space.

### `b` [out]

A pointer to the buffer that receives the data that is read.

### `c` [in]

specifies the number of data values to read. Each data item has a size of **sizeof**(ULONG64).

## Remarks

The **StorPortReadRegisterBufferUlong64** routine is only available on the 64-bit version of Windows.

## See also

[StorPortWriteRegisterBufferUlong64](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteregisterbufferulong64)