# RtlStringCchCopyNW function

## Description

The **RtlStringCchCopyNW** and **RtlStringCchCopyNA** functions copy a character-counted string to a buffer while limiting the size of the copied string.

## Parameters

### `pszDest` [out]

A pointer to a caller-supplied buffer that receives the copied string. The string at *pszSrc*, up to *cchSrc* characters, is copied to the buffer at *pszDest* and terminated with a null character.

### `cchDest` [in]

The size of the destination buffer, in characters. The maximum number of characters allowed is NTSTRSAFE_MAX_CCH.

### `pszSrc` [in]

A pointer to a caller-supplied, null-terminated string.

### `cchToCopy`

The maximum number of characters to copy from *pszSrc* to the buffer that is supplied by *pszDest*.

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means source data was present, the string was copied without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means the copy operation did not complete due to insufficient space in the destination buffer. The destination buffer contains a truncated version of the copied string. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the function received an invalid input parameter. For more information, see the following paragraph.<br><br>The function returns the STATUS_INVALID_PARAMETER value when:<br><br>* The value in *cchDest* is larger than the maximum buffer size.<br>* The destination buffer was already full.<br>* A **NULL** pointer was present.<br>* The destination buffer's length was zero, but a nonzero length source string was present. |

## Remarks

**RtlStringCchCopyNW** and **RtlStringCchCopyNA** should be used instead of **strncpy**.

The functions copy a given number of characters from a source string. **RtlStringCchCopyNW** and **RtlStringCchCopyNA** receive the size, in characters, of the destination buffer to ensure that the functions do not write past the end of the buffer.

Note that these functions behave differently from **strncpy** in one respect. If *cchSrc* is larger than the number of characters in *pszSrc*, **RtlStringCchCopyNW** and **RtlStringCchCopyNA**—unlike **strncpy**—do not continue to pad *pszDest* with null characters until *cchSrc* characters have been copied.

Use **RtlStringCchCopyNW** to handle Unicode strings and **RtlStringCchCopyNA** to handle ANSI strings. The form you use depends on your data, as shown in the following table.

| String data type | String literal | Function |
| --- | --- | --- |
| WCHAR | L"string" | **RtlStringCchCopyNW** |
| **char** | "string" | **RtlStringCchCopyNA** |

If *pszSrc* and *pszDest* point to overlapping strings, the behavior of the function is undefined.

Neither *pszSrc* nor *pszDest* can be **NULL**. If you need to handle **NULL** string pointer values, use [RtlStringCchCopyNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcopynexa).

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCbCopyN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopyna)

[RtlStringCchCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcopya)

[RtlStringCchCopyNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcopynexa)