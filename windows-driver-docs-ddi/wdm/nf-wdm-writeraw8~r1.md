## Description

**WriteRaw8** performs a raw write operation to a volatile CHAR value without any memory ordering or atomicity semantics.

## Parameters

### `Destination`

[out] A pointer to the volatile CHAR variable to write to.

### `Value`

[in] The CHAR value to write to the destination.

## Remarks

The **WriteRaw8** function performs a raw memory write operation on an 8-bit value without compiler optimization barriers or synchronization guarantees.

## See also

[ReadRaw8](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-readraw8-r1)

[WriteRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-writeraw-r1)