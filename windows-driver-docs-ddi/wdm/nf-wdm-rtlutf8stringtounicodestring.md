# RtlUTF8StringToUnicodeString function (wdm.h)

## Description

The **RtlUTF8StringToUnicodeString** function converts the specified UTF8 source string into a Unicode string in accordance with the current system locale information.

## Parameters

### `DestinationString`

Pointer to a [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure to hold the converted Unicode string.

If *AllocateDestinationString* is **TRUE**, the routine allocates a new buffer to hold the string data, updates the **Buffer** member of *DestinationString* to point to the new buffer, and set the maximum length field. Otherwise, the routine uses the currently-specified buffer to hold the string.

### `SourceString`

Pointer to the UTF8 string to be converted to Unicode.

### `AllocateDestinationString`

Specifies if this routine should allocate the buffer space for the destination string. If it does, the caller must deallocate the buffer by calling [**RtlFreeUnicodeString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring).

## Return value

If the conversion succeeds, **RtlUTF8StringToUnicodeString** returns STATUS_SUCCESS. On failure, the routine does not allocate memory or perform a conversion.

## See also

[**RtlFreeUnicodeString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring)