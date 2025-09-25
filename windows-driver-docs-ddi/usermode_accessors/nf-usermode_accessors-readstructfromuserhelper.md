## Description

The **ReadStructFromUserHelper** function is a helper function that safely reads a structure of a specified size from user-mode memory.

## Parameters

### `Destination`

[out] A pointer to the buffer that receives the data read from user-mode memory.

### `Source`

[in] A pointer to the user-mode memory location from which to read the data.

### `Size`

[in] The size, in bytes, of the data to read.

## Remarks

This function is a helper function used internally by the user-mode accessor functions. It provides optimized reading of structures from user-mode memory based on the structure size.

## See also

[**ReadStructFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readstructfromuser)

[**ReadStructFromUserAligned**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readstructfromuseraligned)