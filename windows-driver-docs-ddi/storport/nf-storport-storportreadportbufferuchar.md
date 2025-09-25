# StorPortReadPortBufferUchar macro

## Description

The **StorPortReadPortBufferUchar** routine reads a value from a specified port address

## Parameters

### `h` [in]

A pointer to the hardware device extension.

### `p` [in]

A pointer to the address from which to read.

### `b` [in]

A pointer to the buffer that receives the data that is read.

### `c` [in]

Number of unsigned characters to be read.

A ULONG containing the count.

## Remarks

For more information, see the [ScsiPortReadPortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadportbufferuchar) routine. For a nonbuffered version of this routine, see [StorPortReadPortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadportuchar).

## See also

[ScsiPortReadPortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadportbufferuchar)

[StorPortReadPortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadportuchar)