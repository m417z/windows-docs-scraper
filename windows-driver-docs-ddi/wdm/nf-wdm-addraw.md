## Description

**AddRaw** performs a raw addition operation on a volatile LONG value without atomic guarantees.

## Parameters

### `Destination`

[in, out] A pointer to a volatile LONG variable to modify. This parameter serves as both the source and destination for the addition operation.

### `Value`

[in] The LONG value to add to the destination.

## Return value

Returns the new LONG value after the addition operation.

## Remarks

The **AddRaw** function performs a non-atomic read-add-write operation. It reads the current value from the destination, adds the specified value, writes the result back, and returns the new value.

This function is not atomic and should not be used in multithreaded scenarios where multiple reads might access the same memory location. The operation consists of separate read and write operations that can be interrupted.

## See also

[AddRaw64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-addraw64)

[AddULongRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-addulongraw)

[ReadRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-readraw-r1)

[WriteRaw](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-writeraw-r1)