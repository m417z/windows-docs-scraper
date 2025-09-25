## Description

**ReadRaw64** performs a raw read operation on a volatile LONG64 value without any memory ordering or atomicity semantics.

## Parameters

### `Source`

[in] A pointer to the volatile LONG64 variable to read from.

## Return value

Returns the LONG64 value read from the specified memory location.

## Remarks

The **ReadRaw64** function performs a raw memory read operation on a 64-bit value without compiler optimization barriers or synchronization guarantees.

## See also

[WriteRaw64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-writeraw64-r1)

[ReadRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-readraw-r1)