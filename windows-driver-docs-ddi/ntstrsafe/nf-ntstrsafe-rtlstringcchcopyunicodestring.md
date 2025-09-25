# RtlStringCchCopyUnicodeString function

## Description

The **RtlStringCchCopyUnicodeString** function copies the contents of a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure to a specified destination.

## Parameters

### `pszDest` [out]

A pointer to a buffer that receives the copied string. The string that the *SourceString* parameter's **UNICODE_STRING** structure points to is copied to the buffer at *pszDest* and terminated with a null character.

### `cchDest` [in]

The size, in characters, of the destination buffer. The buffer must be large enough for the string and the terminating null character. The maximum number of characters is NTSTRSAFE_UNICODE_STRING_MAX_CCH.

### `SourceString` [in]

A pointer to a **UNICODE_STRING** structure that contains the string to be copied. The maximum number of characters in the string is NTSTRSAFE_UNICODE_STRING_MAX_CCH.

## Return value

**RtlStringCchCopyUnicodeString** returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means that source data was present, the string was copied without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means that the copy operation did not complete because of insufficient buffer space. The destination buffer contains a truncated, null-terminated version of the intended result. |
| **STATUS_INVALID_PARAMETER** | This *error* status means that the function received an invalid input parameter. For more information, see the following list. |

**RtlStringCchCopyUnicodeString** returns the STATUS_INVALID_PARAMETER value when one of the following occurs:

* The contents of the **UNICODE_STRING** structure are invalid.
* The value in *cbDest* is larger than the maximum buffer size.
* The destination buffer (which *pszDest* points to) is already full.
* A buffer pointer is **NULL**.
* The destination buffer's length is zero, but a nonzero length source string is present.

For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The **RtlStringCchCopyUnicodeString** function uses the destination buffer's size (which *cchDest* specifies) to ensure that the copy operation does not write past the end of the buffer.

If the source and destination strings overlap, the behavior of the function is undefined.

The *SourceString* and *pszDest* pointers cannot be **NULL**. If you need to handle **NULL** pointer values, use the [RtlStringCchCopyUnicodeStringEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcopyunicodestringex) function.

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCbCopyUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopyunicodestring)

[RtlStringCchCopyUnicodeStringEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcopyunicodestringex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)