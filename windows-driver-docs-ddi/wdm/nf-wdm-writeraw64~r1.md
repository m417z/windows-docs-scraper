## Description

**WriteRaw64** performs a raw write operation to a volatile LONG64 value without any memory ordering or atomicity semantics.

## Parameters

### `Destination`

[out] A pointer to the volatile LONG64 variable to write to.

### `Value`

[in] The LONG64 value to write to the destination.

## Remarks

The **WriteRaw64** function performs a raw memory write operation on a 64-bit value without compiler optimization barriers or synchronization guarantees.

## See also

[ReadRaw64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-readraw64-r1)

[WriteRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-writeraw-r1)