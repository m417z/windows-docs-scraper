# RtlUnicodeStringToUTF8String function (wdm.h)

## Description

The **RtlUnicodeStringToUTF8String** function converts the specified Unicode source string into an UTF8 string.

## Parameters

### `DestinationString`

Pointer to a [**UTF8_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string) structure to hold the converted UTF8 string. If *AllocateDestinationString* is **TRUE**, the routine allocates a new buffer to hold the string data, and updates the **Buffer** member of *DestinationString* to point to the new buffer. Otherwise, the routine uses the currently specified buffer to hold the string. The maximum length field is only set if *AllocateDestinationString* is TRUE.

### `SourceString`

Pointer to the Unicode source string to be converted to UTF8.

### `AllocateDestinationString`

**TRUE** if this routine is to allocate the buffer space for the *DestinationString*. If it does, the buffer must be deallocated by calling [**RtlFreeUTF8String**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeutf8string).

## Return value

If the conversion succeeds, **RtlUnicodeStringToUTF8String** returns STATUS_SUCCESS. On failure, the routine does not allocate memory or perform a conversion.

## See also

[**RtlFreeUTF8String**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeutf8string)