## Description

The **WriteStructToUserHelper** function is a helper function that safely writes a structure of a specified size to user-mode memory.

## Parameters

### `Destination`

[out] A pointer to the user-mode memory location where the data will be written.

### `Source`

[in] A pointer to the data to write to the destination memory location.

### `Size`

[in] The size, in bytes, of the data to write.

## Remarks

This function is a helper function used internally by the user-mode accessor functions. It provides optimized writing of structures to user-mode memory based on the structure size.

## See also

[**WriteStructToUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writestructtouser)

[**WriteStructToUserAligned**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writestructtouseraligned)