# RtlUnicodeStringToAnsiString function

## Description

The **RtlUnicodeStringToAnsiString** routine converts a given Unicode string into an ANSI string.

## Parameters

### `DestinationString` [in, out]

Pointer to an [ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string) structure to hold the converted ANSI string. If *AllocateDestinationString* is **TRUE**, the routine allocates a new buffer to hold the string data, and updates the **Buffer** member of *DestinationString* to point to the new buffer. Otherwise, the routine uses the currently specified buffer to hold the string.

### `SourceString` [in]

Pointer to the Unicode source string to be converted to ANSI.

### `AllocateDestinationString` [in]

**TRUE** if this routine is to allocate the buffer space for the *DestinationString*. If it does, the buffer must be deallocated by calling [RtlFreeAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeansistring).

## Return value

If the conversion succeeds, **RtlUnicodeStringToAnsiString** returns STATUS_SUCCESS. Otherwise, no storage was allocated, and no conversion was done.

## Remarks

The translation is done in accord with the current system-locale information.

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)

[RtlAnsiStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlansistringtounicodestring)

[RtlFreeAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeansistring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)