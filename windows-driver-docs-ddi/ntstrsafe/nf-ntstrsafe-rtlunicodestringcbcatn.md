# RtlUnicodeStringCbCatN function

## Description

The **RtlUnicodeStringCbCatN** function concatenates two strings that are contained in [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structures while limiting the size of the copied string.

## Parameters

### `DestinationString` [in, out]

A pointer to a **UNICODE_STRING** structure. This structure includes a buffer that, on input, contains a destination string to which the source string will be concatenated. On output, this buffer is the destination buffer that contains the entire resultant string. The source string is added to the end of the destination string. The maximum number of bytes in the structure's string buffer is NTSTRSAFE_UNICODE_STRING_MAX_CCH * sizeof(WCHAR).

### `SourceString` [in]

A pointer to a **UNICODE_STRING** structure. This structure includes a buffer that contains the source string. This string will be added to the end of the destination string. The maximum number of bytes in the structure's string buffer is NTSTRSAFE_UNICODE_STRING_MAX_CCH * sizeof(WCHAR).

### `cbToAppend` [in]

The maximum number of bytes to append to the string that the *DestinationString* parameter describes.

## Return value

**RtlUnicodeStringCbCatN** returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means that source data was present, the strings were concatenated without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means that the concatenation operation did not complete because of insufficient buffer space. The destination buffer contains a truncated, null-terminated version of the intended result. |
| **STATUS_INVALID_PARAMETER** | This *error* status means that the function received an invalid input parameter. For more information, see the following list. |

**RtlUnicodeStringCbCatN** returns the STATUS_INVALID_PARAMETER value when one of the following occurs:

* The contents of the **UNICODE_STRING** structure are invalid.
* The destination buffer is already full.
* A buffer pointer is **NULL**.
* The destination buffer's length is zero, but a nonzero length source string is present.
* The *cbToAppend* parameter's value is greater than NTSTRSAFE_UNICODE_STRING_MAX_CCH * sizeof(WCHAR).

For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The **RtlUnicodeStringCbCatN** function uses the destination buffer's size to ensure that the concatenation operation does not write past the end of the buffer. The function does not terminate the resultant string with a null character value (that is, with zero).

If the source and destination strings overlap, the behavior of the function is undefined.

The *SourceString* and *DestinationString* pointers cannot be **NULL**. If you need to handle **NULL** pointer values, use the [RtlUnicodeStringCbCatNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringcbcatnex) function.

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlUnicodeStringCbCatNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringcbcatnex)

[RtlUnicodeStringCchCatN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringcchcatn)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)