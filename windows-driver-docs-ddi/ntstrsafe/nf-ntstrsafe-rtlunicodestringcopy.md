# RtlUnicodeStringCopy function

## Description

The **RtlUnicodeStringCopy** function copies a string from one [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure to another.

## Parameters

### `DestinationString` [out]

A pointer to a **UNICODE_STRING** structure. The source string is copied to the destination string. The maximum number of bytes in the structure's string buffer is NTSTRSAFE_UNICODE_STRING_MAX_CCH * sizeof(WCHAR).

### `SourceString` [in]

A pointer to a **UNICODE_STRING** structure. This structure includes a buffer that contains the source string. This string will be copied to the destination string. The maximum number of bytes in the structure's string buffer is NTSTRSAFE_UNICODE_STRING_MAX_CCH * sizeof(WCHAR).

## Return value

**RtlUnicodeStringCopy** returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means that source data was present, the string was copied without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means that the copy operation did not complete because of insufficient buffer space. The destination buffer contains a truncated version of the source string. |
| **STATUS_INVALID_PARAMETER** | This *error* status means that the function received an invalid input parameter. For more information, see the following list. |

**RtlUnicodeStringCopy** returns the STATUS_INVALID_PARAMETER value when one of the following occurs:

* The contents of a **UNICODE_STRING** structure are invalid.
* The destination buffer is already full.
* A buffer pointer is **NULL**.
* The destination buffer's length is zero, but a nonzero length source string is present.

For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The **RtlUnicodeStringCopy** function uses the destination buffer's size to ensure that the copy operation does not write past the end of the buffer. If the string must be truncated at the end of the destination buffer, the function does not terminate the resultant string with a null character.

If the source and destination strings overlap, the behavior of the function is undefined.

The *SourceString* and *DestinationString* pointers cannot be **NULL**. If you need to handle **NULL** pointer values, use the [RtlUnicodeStringCopyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringcopyex) function.

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlUnicodeStringCopyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringcopyex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)