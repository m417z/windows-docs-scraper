# RtlStringCchCopyW function

## Description

The **RtlStringCchCopyW** and **RtlStringCchCopyA** functions copy a null-terminated source string into a destination buffer of specified length.

## Parameters

### `pszDest` [out]

A pointer to a caller-supplied buffer that receives the copied string. The string at *pszSrc* is copied to the buffer at *pszDest* and terminated with a null character.

### `cchDest` [in]

The size, in characters, of the destination buffer. The maximum number of characters allowed is NTSTRSAFE_MAX_CCH.

### `pszSrc` [in]

A pointer to a caller-supplied, null-terminated string.

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means source data was present, the string was copied without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means the copy operation did not complete due to insufficient buffer space. The destination buffer contains a truncated, null-terminated version of the intended result. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the function received an invalid input parameter. For more information, see the following paragraph.<br><br>The function returns the STATUS_INVALID_PARAMETER value when:<br><br>* The value in *cchDest* is larger than the maximum buffer size.<br>* A **NULL** pointer was present.<br>* The destination buffer length was zero at entry. |

## Remarks

**RtlStringCchCopyW** and **RtlStringCchCopyA** should be used instead of the following functions:

* **strcpy**
* **wcscpy**

These functions are not replacements for **strncpy**. Use [RtlStringCchCopyN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcopyna) or [RtlStringCchCopyNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcopynexa) to replace **strncpy**.

The size, in characters, of the destination buffer is provided to **RtlStringCchCopyW** and **RtlStringCchCopyA** to ensure that they do not write past the end of the buffer.

Use **RtlStringCchCopyW** to handle Unicode strings and **RtlStringCchCopyA** to handle ANSI strings. The form you use depends your data, as shown in the following table.

| String data type | String literal | Function |
| --- | --- | --- |
| WCHAR | L"string" | **RtlStringCchCopyW** |
| **char** | "string" | **RtlStringCchCopyA** |

If *pszSrc* and *pszDest* point to overlapping strings, the behavior of the function is undefined.

Neither *pszSrc* nor *pszDest* can be **NULL**. If you need to handle **NULL** string pointer values, use [RtlStringCchCopyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcopyexa).

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCbCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopya)

[RtlStringCchCopyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcopyexa)