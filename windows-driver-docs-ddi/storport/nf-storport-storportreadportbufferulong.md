# StorPortReadPortBufferUlong macro

## Description

The **StorPortReadPortBufferUlong** routine reads a value from a specified port address.

## Parameters

### `h` [in]

A pointer to the hardware device extension.

### `p` [in]

Pointer to the address from which to read.

### `b` [in]

A pointer to the buffer that receives the data that is read.

### `c` [in]

Specifies the number of data items to be read. Each data item has a size of sizeof(ULONG).

## Remarks

For more information, see the [**ScsiPortReadPortBufferUlong**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportreadportbufferulong) routine. For a nonbuffered version of this routine, see [**StorPortReadPortUlong**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadportulong).