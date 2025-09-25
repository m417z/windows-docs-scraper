## Description

**ReadRaw16** performs a raw read operation on a volatile SHORT value without any memory ordering or atomicity semantics.

## Parameters

### `Source`

[in] A pointer to the volatile SHORT variable to read from.

## Return value

Returns the SHORT value read from the specified memory location.

## Remarks

The **ReadRaw16** function performs a raw memory read operation on a 16-bit value without compiler optimization barriers or synchronization guarantees. It's useful on strongly-ordered architectures where precise control over memory access is required.

## See also

[WriteRaw16](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-writeraw16-r1)

[ReadRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-readraw-r1)