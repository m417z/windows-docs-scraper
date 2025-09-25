# RtlCopyUnicodeString function

## Description

The **RtlCopyUnicodeString** routine copies a source string to a destination string.

## Parameters

### `DestinationString` [in, out]

A pointer to the destination string buffer. This parameter points to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure.

### `SourceString` [in, optional]

A pointer to the source string buffer. This parameter points to a **UNICODE_STRING** structure.

## Return value

None

## Remarks

If *SourceString* is **NULL**, this routine sets the **Length** field of the structure pointed to by *DestinationString* to zero.

This routine does not modify the **MaximumLength** and **Buffer** fields of the structure pointed to by *DestinationString*.

The number of bytes copied from the source string is either the source string length (specified by the **Length** member of the structure pointed to by *SourceString*) or the maximum length of the destination string (specified by the **MaximumLength** member of the structure pointed to by *DestinationString*), whichever is smaller.

The caller must properly initialize all members of the structure pointed to by *DestinationString* before calling **RtlCopyUnicodeString**. Failure to initialize the **Length** or the **MaximumLength** member before calling this routine can cause a buffer overrun.

The *DestinationString* and *SourceString* buffers must be resident if the caller is running at IRQL >= DISPATCH_LEVEL.

## See also

[RtlCopyString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlcopystring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)