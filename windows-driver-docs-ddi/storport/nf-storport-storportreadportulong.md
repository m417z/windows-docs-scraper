# StorPortReadPortUlong macro

## Description

The **StorPortReadPortUlong** routine reads a value from a specified port address.

## Parameters

### `h` [in]

A pointer to the hardware device extension.

### `p` [in]

A pointer to the address from which to read.

## Remarks

For more information, see the [**ScsiPortReadPortUlong**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadportulong) routine. For a buffered version of this routine see [**StorPortReadPortBufferUlong**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadportbufferulong).