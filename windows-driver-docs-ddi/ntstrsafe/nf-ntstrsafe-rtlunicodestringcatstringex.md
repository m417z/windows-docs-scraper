# RtlUnicodeStringCatStringEx function

## Description

The **RtlUnicodeStringCatStringEx** function concatenates two strings when the destination string is contained in a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure.

## Parameters

### `DestinationString` [in, out]

Optional. A pointer to a **UNICODE_STRING** structure. This structure includes a buffer that, on input, contains a destination string to which the source string will be concatenated. On output, this buffer is the destination buffer that contains the entire resultant string. The source string (excluding the terminating null) is added to the end of the destination string. The maximum number of bytes in the structure's string buffer is `NTSTRSAFE_UNICODE_STRING_MAX_CCH * sizeof(WCHAR)`. *DestinationString* can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `pszSrc` [in]

Optional. A caller-supplied pointer to a null-terminated source string. This string will be concatenated to the end of the string that is contained in the **UNICODE_STRING** structure that *DestinationString* specifies. *pszSrc* can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `RemainingString` [out, optional]

Optional. If the caller supplies a non-**NULL** pointer to a **UNICODE_STRING** structure, the function sets this structure's **Buffer** member to the end of the concatenated string, sets the structure's **Length** member to zero, and sets the structure's **MaximumLength** member to the number of bytes that are remaining in the destination buffer. This pointer can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `dwFlags` [in]

One or more flags and, optionally, a fill byte. The flags are defined as follows:

| Value | Meaning |
| --- | --- |
| **STRSAFE_FILL_BEHIND** | If this flag is set and the function succeeds, the low byte of *dwFlags* is used to fill the portion of the destination buffer that follows the last character in the string. |
| **STRSAFE_IGNORE_NULLS** | If this flag is set and the function succeeds, the low byte of *dwFlags* is used to fill the portion of the destination buffer that follows the last character in the string. |
| **STRSAFE_FILL_ON_FAILURE** | If this flag is set and the function fails, the low byte of *dwFlags* is used to fill the entire destination buffer. This operation overwrites any preexisting buffer contents. |
| **STRSAFE_NULL_ON_FAILURE** | If this flag is set and the function fails, the destination buffer is set to an empty string (TEXT("")). This operation overwrites any preexisting buffer contents. |
| **STRSAFE_NO_TRUNCATION** | If this flag is set and the function returns **STATUS_BUFFER_OVERFLOW**:<br><br>* If **STRSAFE_FILL_ON_FAILURE** is also specified, **STRSAFE_NO_TRUNCATION** fills the destination buffer   accordingly.<br>* Otherwise, the destination buffer will be unmodified. |
| **STRSAFE_ZERO_LENGTH_ON_FAILURE** | If this flag is set and the function returns STATUS_BUFFER_OVERFLOW, the destination string length is set to zero bytes. |

## Return value

**RtlUnicodeStringCatStringEx** returns one of the following NTSTATUS values.

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | This *success* status means source data was present, and the strings were concatenated without truncation. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means that the copy operation did not complete because of insufficient space in the destination buffer. If **STRSAFE_NO_TRUNCATION** is set, see the *dwFlags* parameter for more information. |
| **STATUS_INVALID_PARAMETER** | This *error* status means that the function received an invalid input parameter. For more information, see the following list. |

**RtlUnicodeStringCatStringEx** returns the STATUS_INVALID_PARAMETER value when one of the following occurs:

- The contents of a **UNICODE_STRING** structure are invalid.
- An invalid flag is specified in *dwFlags*.
- The destination buffer is already full.
- A buffer pointer is **NULL** and the STRSAFE_IGNORE_NULLS flag is not specified in *dwFlags*.
- The destination buffer pointer is **NULL**, but the buffer size is not zero.
- The destination buffer pointer is **NULL**, or its length is zero, but a nonzero length source string is present.

For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The **RtlUnicodeStringCatStringEx** function uses the destination buffer's size to ensure that the concatenation operation does not write past the end of the buffer. By default, the function does *not* terminate the resultant string with a null character value (that is, with zero). As an option, the caller can use the STRSAFE_FILL_BEHIND flag and a fill byte value of zero to null-terminate a resultant string that does not occupy the entire destination buffer.

**RtlUnicodeStringCatStringEx** adds to the functionality of the [RtlUnicodeStringCatString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringcatstring) function by returning a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that identifies the end of the destination string and the number of bytes that are left unused in that string. You can pass flags to **RtlUnicodeStringCatStringEx**or additional control.

If the source and destination strings overlap, the behavior of the function is undefined.

The *pszSrc* and *DestinationString* pointers cannot be **NULL** unless the STRSAFE_IGNORE_NULLS flag is set in *dwFlags*. If STRSAFE_IGNORE_NULLS is set, one or both of these pointers can be **NULL**. If the *DestinationString* pointer is **NULL**, the *pszSrc* pointer must either be **NULL** or point to an empty string.

For more information about the safe string functions, see [Using safe string functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

- [RtlUnicodeStringCatString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringcatstring)
- [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)