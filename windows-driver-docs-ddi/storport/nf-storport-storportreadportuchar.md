# StorPortReadPortUchar macro

## Description

The **StorPortReadPortUchar** routine reads a value from a specified port address

## Parameters

### `h` [in]

A pointer to the hardware device extension.

### `p` [in]

Pointer to the address from which to read.

## Remarks

For more information, see the [ScsiPortReadPortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadportbufferuchar) routine. For a buffered version of this routine, see [StorPortReadPortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadportbufferuchar).

## See also

[ScsiPortReadPortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadportbufferuchar)

[StorPortReadPortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadportbufferuchar)