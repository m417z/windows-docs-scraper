## Description

**ReadRaw** performs a raw read operation on a volatile LONG value without any memory ordering semantics.

## Parameters

### `Source`

[in] A pointer to a volatile LONG value to read from.

## Return value

Returns the LONG value read from the specified memory location.

## Remarks

The **ReadRaw** function executes a plain read from memory without providing any ordering, fencing, or atomicity guarantees. Use this function only when you knowingly manage synchronization elsewhere or when interacting with hardware where the raw access is required.

## See also

[**WriteRaw**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-writeraw-r1)