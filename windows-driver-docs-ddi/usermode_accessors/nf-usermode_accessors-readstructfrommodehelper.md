## Description

The **ReadStructFromModeHelper** function is a helper function that safely reads a structure of a specified size from memory based on the specified processor mode.

## Parameters

### `Destination`

[out] A pointer to the buffer that receives the data read from memory.

### `Source`

[in] A pointer to the memory location from which to read the data.

### `Size`

[in] The size, in bytes, of the data to read.

### `Mode`

[in] The processor mode that determines how the memory access is performed.

## Remarks

This function is a helper function used internally by the user-mode accessor functions. It provides mode-aware reading of structures from memory, with extra safety checks when accessing user-mode memory.

## See also

[**ReadStructFromMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readstructfrommode)

[**ReadStructFromModeAligned**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-readstructfrommodealigned)