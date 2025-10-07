# RtlUTF8ToUnicodeN function

Translates the specified source string into a Unicode string, using the 8-bit Unicode Transformation Format (UTF-8) code page.

## Parameters

*UnicodeStringDestination* \[out\]

A pointer to a caller-allocated buffer that receives the translated string.

*UnicodeStringMaxByteCount* \[in\]

Maximum number of bytes to be written at *UnicodeStringDestination*. If this value causes the translated string to be truncated, **RtlUTF8ToUnicodeN** returns an error status.

*UnicodeStringActualByteCount* \[out, optional\]

A pointer to a caller-allocated variable that receives the length, in bytes, of the translated string. This parameter is optional and can be **NULL**. If the string is truncated then the returned number counts the actual truncated string count.

*UTF8StringSource* \[in\]

A pointer to the string to be translated.

*UTF8StringByteCount* \[in\]

Size, in bytes, of the string at *UTF8StringSource*.

## Return value

**RtlUTF8ToUnicodeN** returns one of the following NTSTATUS values:

| Return code | Description |
|--------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------|
| **STATUS\_SUCCESS** | The string was converted to Unicode.<br> |
| **STATUS\_SOME\_NOT\_MAPPED** | An invalid input character was encountered and replaced. This status is considered a success status.<br> |
| **STATUS\_INVALID\_PARAMETER** | Both pointers to *UnicodeStringDestination* and *UnicodeStringActualByteCount* were **NULL**.<br> |
| **STATUS\_INVALID\_PARAMETER\_4** | The *UTF8StringSource* was **NULL**.<br> |
| **STATUS\_BUFFER\_TOO\_SMALL** | *UnicodeStringDestination* was truncated.<br> |

## Remarks

Although *UnicodeStringActualByteCount* is optional and can be **NULL**, callers should provide storage for it, because the received length can be used to determine whether the conversion was successful.

If the output is truncated and an invalid input character is encountered then the function returns STATUS\_BUFFER\_TOO\_SMALL error.

If the *UnicodeStringDestination* is set to **NULL** the function will return the required number of bytes to host the translated string without any truncation in *UnicodeStringActualByteCount*.

**RtlUTF8ToUnicodeN** does not modify the source string unless the *UnicodeStringDestination* and *UTF8StringSource* pointers are equivalent. The returned Unicode string is not null-terminated.

Callers of **RtlUTF8ToUnicodeN** must be running at IRQL < DISPATCH\_LEVEL.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Wdm.h |
| DLL<br> | Ntdll.dll |

## See also

[**RtlUnicodeToUTF8N**](https://learn.microsoft.com/windows/win32/devnotes/rtlunicodetoutf8n)

