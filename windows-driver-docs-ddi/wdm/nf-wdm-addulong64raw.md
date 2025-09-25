## Description

**AddULong64Raw** performs a raw addition operation on a volatile ULONG64 value without atomic guarantees.

## Parameters

### `Destination`

[in, out] A pointer to the volatile ULONG64 variable to modify. This parameter serves as both the source and destination for the addition operation.

### `Value`

[in] The ULONG64 value to add to the destination.

## Return value

Returns the new ULONG64 value after the addition operation.

## Remarks

The **AddULong64Raw** function performs a non-atomic read-add-write operation on 64-bit unsigned long values.

This function shouldn't be used in multithreaded scenarios where multiple threads might access the same memory location. The operation consists of separate read and write operations that can be interrupted.

## See also

[AddRaw64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-addraw64)

[AddULongRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-addulongraw)

[AddRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-addraw)