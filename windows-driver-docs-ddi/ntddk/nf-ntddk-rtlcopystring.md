# RtlCopyString function

## Description

The **RtlCopyString** routine copies a source string to a destination string.

## Parameters

### `DestinationString` [out]

A pointer to the destination string buffer.

### `SourceString` [in, optional]

A pointer to the source string buffer.

## Return value

None

## Remarks

The *DestinationString* **Length** is set to zero if no source string is supplied. The **MaximumLength** and **Buffer** members of the *DestinationString* are not modified by this routine.

The number of bytes copied from the *SourceString* is either the length of *SourceString* or the maximum length of *DestinationString*, whichever is smaller.

The *DestinationString* and *SourceString* buffers must be resident if the caller is running at IRQL >= DISPATCH_LEVEL.

## See also

[RtlCopyUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopyunicodestring)