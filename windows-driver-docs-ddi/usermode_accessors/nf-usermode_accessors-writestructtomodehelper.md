## Description

The **WriteStructToModeHelper** function is a helper function that safely writes a structure of a specified size to memory based on the specified processor mode.

## Parameters

### `Destination`

[out] A pointer to the memory location where the data will be written.

### `Source`

[in] A pointer to the data to write to the destination memory location.

### `Size`

[in] The size, in bytes, of the data to write.

### `Mode`

[in] The processor mode that determines how the memory access is performed.

## Remarks

This function is a helper function used internally by the usermode accessor functions. It provides mode-aware writing of structures to memory, with extra safety checks when accessing user-mode memory.

## See also

[**WriteStructToMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writestructtomode)

[**WriteStructToModeAligned**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-writestructtomodealigned)