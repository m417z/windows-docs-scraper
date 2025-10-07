# RtlUnicodeToUTF8N function

Translates the specified Unicode string into a new character string, using the 8-bit Unicode Transformation Format (UTF-8) code page.

## Parameters

*UTF8StringDestination* \[out\]

A pointer to a caller-allocated buffer to receive the translated string.

*UTF8StringMaxByteCount* \[in\]

Maximum number of bytes to be written to *UTF8StringDestination*. If this value causes the translated string to be truncated, **RtlUnicodeToUTF8N** returns an error status.

*UTF8StringActualByteCount* \[out, optional\]

A pointer to a caller-allocated variable that receives the length, in bytes, of the translated string. This parameter is optional and can be **NULL**. If the string is truncated then the returned number counts the actual truncated string count.

*UnicodeStringSource* \[in\]

A pointer to the Unicode source string to be translated.

*UnicodeStringByteCount * \[in\]

Specifies the number of bytes in the Unicode source string that the *UnicodeStringSource* parameter points to.

## Return value

**RtlUnicodeToUTF8N** returns one of the following NTSTATUS values:

| Return code | Description |
|--------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------|
| **STATUS\_SUCCESS** | The Unicode string was converted to UTF-8.<br> |
| **STATUS\_SOME\_NOT\_MAPPED** | An invalid input character was encountered and replaced. This status is considered a success status.<br> |
| **STATUS\_INVALID\_PARAMETER** | Both pointers to *UTF8StringDestination* and *UTF8StringActualByteCount* were **NULL**.<br> |
| **STATUS\_INVALID\_PARAMETER\_4** | The *UnicodeStringSource* was **NULL**.<br> |
| **STATUS\_BUFFER\_TOO\_SMALL** | *UTF8StringDestination* was truncated.<br> |

## Remarks

Although *UTF8StringActualByteCount* is optional and can be **NULL**, callers should provide storage for it, because the received length can be used to determine whether the conversion was successful. This routine does not modify the source string. It returns a null-terminated UTF-8 string if the given *UnicodeStringSource* included a NULL terminator and if the given *UTF8StringMaxByteCount* did not cause truncation.

If the output is truncated and an invalid input character is encountered then the function returns STATUS\_BUFFER\_TOO\_SMALL error.

If the *UTF8StringDestination* is set to **NULL** the function will return the required number of bytes to host the translated string without any truncation in *UTF8StringActualByteCount*.

Callers of **RtlUnicodeToUTF8N** must be running at IRQL < DISPATCH\_LEVEL.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Wdm.h |
| DLL<br> | Ntdll.dll |

## See also

[**RtlUTF8ToUnicodeN**](https://learn.microsoft.com/windows/win32/devnotes/rtlutf8tounicoden)

