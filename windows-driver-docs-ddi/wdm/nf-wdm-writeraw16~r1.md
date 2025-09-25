## Description

**WriteRaw16** performs a raw write operation to a volatile SHORT value without any memory ordering or atomicity semantics.

## Parameters

### `Destination`

[out] A pointer to the volatile SHORT variable to write to.

### `Value`

[in] The SHORT value to write to the destination.

## Remarks

The **WriteRaw16** function performs a raw memory write operation on a 16-bit value without compiler optimization barriers or synchronization guarantees.

## See also

[ReadRaw16](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-readraw16-r1)

[WriteRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-writeraw-r1)