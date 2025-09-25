# RtlUpperString function

## Description

The **RtlUpperString** routine copies the given *SourceString* to the *DestinationString* buffer, converting it to uppercase.

## Parameters

### `DestinationString` [in, out]

Pointer to the buffer for the converted destination string.

### `SourceString` [in]

Pointer to the source string to be converted to uppercase.

## Return value

None

## Remarks

The **MaximumLength** and **Buffer** members of *DestinationString* are not modified by this routine.

The number of bytes copied from *SourceString* is either the **Length** of *SourceString* or the **MaximumLength** of *DestinationString*, whichever is smaller.

## See also

[RtlUpperChar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlupperchar)