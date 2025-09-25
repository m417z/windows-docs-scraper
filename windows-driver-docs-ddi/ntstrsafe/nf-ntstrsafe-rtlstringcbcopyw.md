# RtlStringCbCopyW function

## Description

The **RtlStringCbCopyW** and **RtlStringCbCopyA** functions copy a byte-counted string into a buffer.

## Parameters

### `pszDest` [out]

A pointer to a caller-supplied buffer that receives the copied string. The string at *pszSrc* is copied to the buffer at *pszDest* and terminated with a null character.

### `cbDest` [in]

The size, in bytes, of the destination buffer. The buffer must be large enough for the string and the terminating null character.

For Unicode strings, the maximum number of bytes is NTSTRSAFE_MAX_CCH * sizeof(WCHAR).

For ANSI strings, the maximum number of bytes is NTSTRSAFE_MAX_CCH * sizeof(char).

### `pszSrc` [in]

A pointer to a caller-supplied, null-terminated string.

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means source data was present, the string was copied without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means the copy operation did not complete due to insufficient buffer space. The destination buffer contains a truncated, null-terminated version of the intended result. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the function received an invalid input parameter. For more information, see the following paragraph.<br><br>The function returns the STATUS_INVALID_PARAMETER value when:<br><br>* The value in *cbDest* is larger than the maximum buffer size.<br>* The destination buffer was already full.<br>* A **NULL** pointer was present.<br>* The destination buffer's length was zero, but a nonzero length source string was present. |

## Remarks

**RtlStringCbCopyA** and **RtlStringCbCopyW** should be used instead of the following functions:

* **strcpy**
* **wcscpy**

**RtlStringCbCopyA** and **RtlStringCbCopyW** are not replacements for **strncpy**. To replace **strncpy**, use [RtlStringCbCopyN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopyna) or [RtlStringCbCopyNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopynexa).

The size of the destination buffer is provided to the function to ensure that **RtlStringCbCopy** does not write past the end of the buffer.

Use **RtlStringCbCopyW** to handle Unicode strings and **RtlStringCbCopyA** to handle ANSI strings. The form you use depends on your data as shown in the following table.

| String data type | String literal | Function |
| --- | --- | --- |
| WCHAR | L"string" | **RtlStringCbCopyW** |
| **char** | "string" | **RtlStringCbCopyA** |

If *pszSrc* and *pszDest* point to overlapping strings, the behavior of the function is undefined.

Neither *pszSrc* nor *pszDest* can be **NULL**. If you need to handle **NULL** string pointer values, use [RtlStringCbCopyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopyexa).

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCbCopyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopyexa)

[RtlStringCchCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcopya)