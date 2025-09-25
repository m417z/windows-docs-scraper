## Description

**WriteRaw** performs a raw write operation to a volatile LONG value without any memory ordering or atomicity semantics.

## Parameters

### `Destination`

[out] A pointer to the volatile LONG variable to write to.

### `Value`

[in] The LONG value to write to the destination.

## Remarks

The **WriteRaw** function performs a raw memory write operation without compiler optimization barriers or synchronization guarantees.

## See also

[ReadRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-readraw-r1)