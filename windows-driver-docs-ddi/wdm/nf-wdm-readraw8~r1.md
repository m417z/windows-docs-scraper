## Description

**ReadRaw8** performs a raw read operation on a volatile CHAR value without any memory ordering or atomicity semantics.

## Parameters

### `Source`

[in] A pointer to the volatile CHAR variable to read from.

## Return value

Returns the CHAR value read from the specified memory location.

## Remarks

The **ReadRaw8** function performs a raw memory read operation on an 8-bit value without compiler optimization barriers or synchronization guarantees.

## See also

[WriteRaw8](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-writeraw8-r1)

[ReadRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-readraw-r1)