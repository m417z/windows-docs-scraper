# RtlUpcaseUnicodeString function

## Description

The **RtlUpcaseUnicodeString** routine converts a copy of the source string to uppercase and writes the converted string in the destination buffer.

## Parameters

### `DestinationString` [in, out]

Pointer to a caller-allocated buffer for the converted Unicode string.

### `SourceString` [in]

Pointer to the source Unicode string to be converted to uppercase.

### `AllocateDestinationString` [in]

Specifies if **RtlUpcaseUnicodeString** is to allocate the buffer space for the *DestinationString*. If it does, the buffer must be deallocated by calling **RtlFreeUnicodeString**.

## Return value

If the operation succeeds, **RtlUpcaseUnicodeString** returns STATUS_SUCCESS. Otherwise, no storage was allocated, and no conversion was done.

## See also

[RtlFreeUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring)

[RtlUpcaseUnicodeChar](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlupcaseunicodechar)