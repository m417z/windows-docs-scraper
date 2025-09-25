# RtlStringCbCopyNA function

## Description

The **RtlStringCbCopyNW** and **RtlStringCbCopyNA** functions copy a byte-counted string to a buffer while limiting the size of the copied string.

## Parameters

### `pszDest` [out]

A pointer to a caller-supplied buffer that receives the copied string. The string at *pszSrc*, up to *cbSrc* bytes, is copied to the buffer at *pszDest* and terminated with a null character.

### `cbDest` [in]

The size, in bytes, of the destination buffer. The buffer must be large enough for both the string and the terminating null character.

For Unicode strings, the maximum number of bytes is NTSTRSAFE_MAX_CCH * **sizeof**(WCHAR).

For ANSI strings, the maximum number of bytes is NTSTRSAFE_MAX_CCH * **sizeof**(**char**).

### `pszSrc` [in]

A pointer to a caller-supplied, null-terminated string.

### `cbToCopy`

The maximum number of bytes to copy from *pszSrc* to *pszDest*.

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means source data was present, the string was copied without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means the copy operation did not complete due to insufficient space in the destination buffer. The destination buffer contains a truncated version of the copied string. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the function received an invalid input parameter. For more information, see the following paragraph.<br><br>The function returns the STATUS_INVALID_PARAMETER value when:<br><br>* The value in *cbDest* is larger than the maximum buffer size.<br>* The destination buffer was already full.<br>* A **NULL** pointer was present.<br>* The destination buffer's length was zero, but a nonzero length source string was present. |

## Remarks

**RtlStringCbCopyNW** and **RtlStringCbCopyNA** should be used instead of **strncpy**. However, these functions differ in behavior. If *cbSrc* is larger than the number of bytes in *pszSrc*, the **RtlStringCbCopyN** functions—unlike **strncpy**—do not fill *pszDest* with null characters until *cbSrc* bytes have been copied.

**RtlStringCbCopyN** copies a given number of bytes from a source string. The size, in bytes, of the destination buffer is provided to the function to ensure that **RtlStringCbCopyN** does not write past the end of this buffer.

Use **RtlStringCbCopyNW** to handle Unicode strings and **RtlStringCbCopyNA** to handle ANSI strings. The form you use depends on your data, as shown in the following table.

| String data type | String literal | Function |
| --- | --- | --- |
| WCHAR | L"string" | **RtlStringCbCopyNW** |
| **char** | "string" | **RtlStringCbCopyNA** |

If *pszSrc* and *pszDest* point to overlapping strings, the behavior of the function is undefined.

Neither *pszSrc* nor *pszDest* can be **NULL**. If you need to handle **NULL** string pointer values, see [RtlStringCbCopyNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopynexa).

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCbCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopya)

[RtlStringCbCopyNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopynexa)

[RtlStringCchCopyN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcopyna)