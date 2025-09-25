## Description

**AddULongRaw** performs a raw addition operation on a volatile ULONG value without atomic guarantees.

## Parameters

### `Destination`

[in, out] A pointer to the volatile ULONG variable to modify. This parameter serves as both the source and destination for the addition operation.

### `Value`

[in] The ULONG value to add to the destination.

## Return value

Returns the new ULONG value after the addition operation.

## Remarks

The **AddULongRaw** function performs a non-atomic read-add-write operation on unsigned long values. This function internally casts the ULONG pointers to LONG pointers and calls `AddRaw`, then casts the result back to ULONG.

This function is not atomic and should not be used in multithreaded scenarios where multiple threads might access the same memory location. The operation consists of separate read and write operations that can be interrupted.

## See also

[AddRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-addraw)

[AddULong64Raw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-addulong64raw)

[AddRaw64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-addraw64)