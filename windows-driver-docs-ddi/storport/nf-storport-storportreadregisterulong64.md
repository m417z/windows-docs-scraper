# StorPortReadRegisterUlong64 macro

## Description

The **StorPortReadRegisterUlong64** routine reads a 64-bit value from a specified 64-bit register address.

## Parameters

### `h` [in]

A pointer to the hardware device extension.

### `r` [in]

A pointer to the register where the data is to be read.

## Remarks

The **StorPortReadRegisterUlong64** routine is only available on the 64-bit version of Windows.

## See also

[StorPortWriteRegisterUlong64](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteregisterulong64)