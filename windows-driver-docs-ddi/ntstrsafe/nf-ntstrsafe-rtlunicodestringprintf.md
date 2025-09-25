# RtlUnicodeStringPrintf function

## Description

The **RtlUnicodeStringPrintf** function creates a text string, with formatting that is based on supplied formatting information, and stores the string in a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure.

## Parameters

### `DestinationString` [out]

A pointer to a **UNICODE_STRING** structure that receives a formatted string. **RtlUnicodeStringPrintf** creates this string from the formatting string that *pszFormat* specifies and the function's argument list. The maximum number of characters in the string is NTSTRSAFE_UNICODE_STRING_MAX_CCH.

### `pszFormat` [in]

A pointer to a null-terminated text string that contains **printf**-styled formatting directives.

### `...`

Optional. A list of arguments that the function interprets, based on formatting directives that the *pszFormat* string contains.

## Return value

**RtlUnicodeStringPrintf** returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means that source data was present, the string was copied without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means that the operation did not complete because of insufficient buffer space. The destination buffer contains a truncated, null-terminated version of the intended result. |
| **STATUS_INVALID_PARAMETER** | This *error* status means that the function received an invalid input parameter. For more information, see the following list. |

**RtlUnicodeStringPrintf** returns the STATUS_INVALID_PARAMETER value when one of the following occurs:

* The contents of the **UNICODE_STRING** structure that the *DestinationString* parameter points to are invalid.
* The destination buffer is already full.
* A **NULL** pointer is present.
* The destination buffer's length is zero, but a nonzero length source string is present.

For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The **RtlUnicodeStringPrintf** function uses the destination buffer's size to ensure that the string formatting operation does not write past the end of the buffer. The function does not terminate the resultant string with a null character.

If the format string and destination string overlap, the behavior of the function is undefined.

The *pszFormat* and *DestinationString* pointers cannot be **NULL**. If you need to handle **NULL** pointer values, use the [RtlUnicodeStringPrintfEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringprintfex) function.

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlUnicodeStringPrintfEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringprintfex)

[RtlUnicodeStringVPrintf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringvprintf)

[RtlUnicodeStringVPrintfEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringvprintfex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)