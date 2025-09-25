# RtlUnicodeStringCbCopyStringN function

## Description

The **RtlUnicodeStringCbCopyStringN** function copies a string into a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure while limiting the size of the copied string.

## Parameters

### `DestinationString` [out]

A pointer to a **UNICODE_STRING** structure that receives the copied string. The string that the *pszSrc* parameter points to (excluding the terminating null) is copied into the buffer that the *DestinationString* parameter's **UNICODE_STRING** structure points to. The maximum number of bytes in the string is NTSTRSAFE_UNICODE_STRING_MAX_CCH * sizeof(WCHAR).

### `pszSrc` [in]

A pointer to the string to be copied.

### `cbToCopy` [in]

The number of bytes to be copied from the source to the destination.

## Return value

**RtlUnicodeStringCbCopyN** returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means that source data was present, the string was copied without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means that the copy operation did not complete because of insufficient buffer space. The destination buffer contains a truncated, null-terminated version of the intended result. |
| **STATUS_INVALID_PARAMETER** | This *error* status means that the function received an invalid input parameter. For more information, see the following list. |

**RtlUnicodeStringCbCopyN** returns the STATUS_INVALID_PARAMETER value when one of the following occurs:

* The contents of the **UNICODE_STRING** structure are invalid.
* The destination buffer is already full.
* A buffer pointer is **NULL**.
* The destination buffer's length is zero, but a nonzero length source string is present.
* The *cbToCopy* parameter's value is greater than NTSTRSAFE_UNICODE_STRING_MAX_CCH * sizeof(WCHAR).

For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The **RtlUnicodeStringCbCopyN** function uses the destination buffer's size to ensure that the copy operation does not write past the end of the buffer. The function does not terminate the resultant string with a null character value (that is, with zero).

If the source and destination strings overlap, the behavior of the function is undefined.

The *pszSrc* and *DestinationString* pointers cannot be **NULL**. If you need to handle **NULL** pointer values, use the [RtlUnicodeStringCbCopyNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringcbcopynex) function.

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlUnicodeStringCbCopyNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringcbcopynex)

[RtlUnicodeStringCchCopyN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringcchcopyn)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)