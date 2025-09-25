# WriteControlSpace function

## Description

The **WriteControlSpace** function writes to the processor-specific control space of the current target.

## Parameters

### `processor`

Specifies the index of the processor whose control space is to be written.

### `address`

Specifies the address of the control space.

### `buf`

Specifies the data to be written to the control space.

### `size`

Specifies the number of bytes to be written. This is the number of bytes in the *buf* buffer.

## Remarks

This function can only be called in kernel-mode debugging.

## See also

[ReadControlSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readcontrolspace)

[ReadControlSpace64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-readcontrolspace64)