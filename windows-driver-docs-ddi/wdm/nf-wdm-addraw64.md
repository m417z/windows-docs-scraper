## Description

**AddRaw64** performs a raw addition operation on a volatile LONG64 value without atomic guarantees.

## Parameters

### `Destination`

[in, out] A pointer to the volatile LONG64 variable to modify. This parameter serves as both the source and destination for the addition operation.

### `Value`

[in] The LONG64 value to add to the destination.

## Return value

Returns the new LONG64 value after the addition operation.

## Remarks

The **AddRaw64** function performs a non-atomic read-add-write operation on 64-bit values. It reads the current value from the destination, adds the specified value, writes the result back, and returns the new value.

This function is not atomic and should not be used in multithreaded scenarios where multiple threads might access the same memory location. The operation consists of separate read and write operations that can be interrupted.

## See also

[AddRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-addraw)

[AddULong64Raw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-addulong64raw)

[ReadRaw64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-readraw64-r1)

[WriteRaw64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-writeraw64-r1)