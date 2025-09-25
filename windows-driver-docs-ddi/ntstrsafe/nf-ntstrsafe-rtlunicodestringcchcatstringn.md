# RtlUnicodeStringCchCatStringN function

## Description

The **RtlUnicodeStringCchCatStringN** function concatenates two strings when the destination string is contained in a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure, while limiting the size of the appended string.

## Parameters

### `DestinationString` [in, out]

A pointer to a **UNICODE_STRING** structure. This structure includes a buffer that, on input, contains a string to which the source string will be concatenated. On output, this buffer is the destination buffer that contains the entire resultant string. The source string (excluding the terminating **NULL**) is added to the end of the destination string. The maximum number of characters in the structure's string buffer is NTSTRSAFE_UNICODE_STRING_MAX_CCH.

### `pszSrc` [in]

A caller-supplied pointer to a null-terminated string. This string will be concatenated to the end of the string that is contained in the *DestinationString* parameter's **UNICODE_STRING** structure.

### `cchToAppend` [in]

The maximum number of characters to append to the string that the *DestinationString* parameter describes.

## Return value

**RtlUnicodeStringCchCatStringN** returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means that source data was present, the strings were concatenated without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means that the concatenated operation did not complete because of insufficient buffer space. The destination buffer contains a truncated, null-terminated version of the intended result. |
| **STATUS_INVALID_PARAMETER** | This *error* status means that the function received an invalid input parameter. For more information, see the following list. |

**RtlUnicodeStringCchCatStringN** returns the STATUS_INVALID_PARAMETER value when one of the following occurs:

* The contents of the **UNICODE_STRING** structure are invalid.
* The destination buffer is already full.
* A buffer pointer is **NULL**.
* The destination buffer's length is zero, but a nonzero length source string is present.
* The *cchToAppend* parameter's value is greater than NTSTRSAFE_UNICODE_STRING_MAX_CCH.

For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The **RtlUnicodeStringCchCatStringN** function uses the destination buffer's size to ensure that the concatenation operation does not write past the end of the buffer. The function does not terminate the resultant string with a null character value (that is, with zero).

If the source and destination strings overlap, the behavior of the function is undefined.

The *pszSrc* and *DestinationString* pointers cannot be **NULL**. If you need to handle **NULL** pointer values, use the [RtlUnicodeStringCchCatStringNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringcchcatstringnex) function.

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlUnicodeStringCbCatStringN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringcbcatstringn)

[RtlUnicodeStringCchCatStringNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringcchcatstringnex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)