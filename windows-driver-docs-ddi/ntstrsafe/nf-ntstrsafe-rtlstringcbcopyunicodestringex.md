# RtlStringCbCopyUnicodeStringEx function

## Description

The **RtlStringCbCopyUnicodeStringEx** function copies the contents of a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure to a specified destination.

## Parameters

### `pszDest` [out]

Optional. A pointer to a buffer that receives the copied string. The string that the *SourceString* parameter's **UNICODE_STRING** structure points to is copied to the buffer at *pszDest* and terminated with a null character. This pointer can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `cbDest` [in]

The size, in bytes, of the destination buffer. The buffer must be large enough for the string and the terminating null character. The maximum number of bytes in the buffer is `NTSTRSAFE_MAX_CCH * sizeof(WCHAR)`.

### `SourceString` [in]

Optional. A pointer to a **UNICODE_STRING** structure that contains the string to be copied. The maximum number of bytes in the string is `NTSTRSAFE_UNICODE_STRING_MAX_CCH * sizeof(WCHAR)`. This pointer can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `ppszDestEnd` [out]

Optional. If the caller supplies a non-**NULL** address pointer, then after the copy operation completes, the function loads that address with a pointer to the destination buffer's resulting **NULL** string terminator.

### `pcbRemaining` [out, optional]

Optional. If the caller supplies a non-**NULL** address pointer, the function loads the address with the number of unused bytes that are in the buffer that *pszDest* points to, including bytes that are used for the terminating null character.

### `dwFlags` [in]

One or more flags and, optionally, a fill byte. The flags are defined as follows:

| Value | Meaning |
| --- | --- |
| **STRSAFE_FILL_BEHIND_NULL** | If this flag is set and the function succeeds, the low byte of *dwFlags* is used to fill the portion of the destination buffer that follows the terminating null character. |
| **STRSAFE_IGNORE_NULLS** | If this flag is set, either the source or destination pointer, or both, can be **NULL**. **RtlStringCbCopyUnicodeStringEx** treats **NULL** source buffer pointers like empty strings (TEXT("")), which can be copied. **NULL** destination buffer pointers cannot receive nonempty strings. |
| **STRSAFE_FILL_ON_FAILURE** | If this flag is set and the function fails, the low byte of *dwFlags* is used to fill the entire destination buffer, and the buffer is null-terminated. This operation overwrites any preexisting buffer contents. |
| **STRSAFE_NULL_ON_FAILURE** | If this flag is set and the function fails, the destination buffer is set to an empty string (TEXT("")). This operation overwrites any preexisting buffer contents. |
| **STRSAFE_NO_TRUNCATION** | If this flag is set and the function returns **STATUS_BUFFER_OVERFLOW**:<br><br>* If **STRSAFE_FILL_ON_FAILURE** is also specified, **STRSAFE_NO_TRUNCATION** fills the destination buffer accordingly.<br>* Otherwise, the contents of the destination buffer will be set to an empty string, even if **STRSAFE_NULL_ON_FAILURE** is not set. **STRSAFE_FILL_BEHIND_NULL** is ignored. |

## Return value

**RtlStringCbCopyUnicodeStringEx** returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means that source data was present, the string was copied without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means that the copy operation did not complete because of insufficient space in the destination buffer. If **STRSAFE_NO_TRUNCATION** is set in *dwFlags*, the destination buffer is not modified. If the flag is not set, the destination buffer contains a truncated version of the copied string. |
| **STATUS_INVALID_PARAMETER** | This *error* status means that the function received an invalid input parameter. For more information, see the following list. |

**RtlStringCbCopyUnicodeStringEx** returns the STATUS_INVALID_PARAMETER value when one of the following occurs:

- The contents of the **UNICODE_STRING** structure are invalid.
- An invalid flag is specified in dwFlags.
- The value in *cbDest* is larger than the maximum buffer size.
- The destination buffer (which *pszDest* points to) is already full.
- A buffer pointer is **NULL** and the STRSAFE_IGNORE_NULLS flag is not specified.
- The destination buffer pointer is **NULL**, but the buffer size is not zero.
- The destination buffer pointer is **NULL** or its length is zero, but a nonzero length source string is present.

For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The **RtlStringCbCopyUnicodeStringEx** function uses the destination buffer's size (which the *cbDest* parameter specifies) to ensure that the copy operation does not write past the end of the buffer.

**RtlStringCbCopyUnicodeStringEx** adds to the functionality of the [RtlStringCbCopyUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopyunicodestring) function by returning a pointer to the end of the destination string and the number of bytes that are left unused in that string. You can pass flags to the function for additional control.

If the source and destination strings overlap, the behavior of the function is undefined.

The *SourceString* and *pszDest* pointers cannot be **NULL** unless the STRSAFE_IGNORE_NULLS flag is set in *dwFlags*. If STRSAFE_IGNORE_NULLS is set, one or both of these pointers can be **NULL**. If the *pszDest* pointer is **NULL**, the *SourceString* pointer must be **NULL** or the [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure must describe an empty string.

For more information about the safe string functions, see [Using safe string functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

- [RtlStringCbCopyUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopyunicodestring)
- [RtlStringCchCopyUnicodeStringEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcopyunicodestringex)
- [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)