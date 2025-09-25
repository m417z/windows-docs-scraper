# RtlStringCbCatNA function

## Description

The **RtlStringCbCatNW** and **RtlStringCbCatNA** functions concatenate two byte-counted strings while limiting the size of the appended string.

## Parameters

### `pszDest` [in, out]

Pointer to a buffer which, on input, contains a null-terminated string to which *pszSrc* will be concatenated. On output, this is the destination buffer that contains the entire resultant string. The string at *pszSrc*, up to *cbToAppend* bytes, is added to the end of the string at *pszDest* and terminated with a null character.

### `cbDest` [in]

The size of the destination buffer, in bytes. The buffer must be large enough to include both strings and the terminating null character.

For Unicode strings, the maximum number of bytes is NTSTRSAFE_MAX_CCH * sizeof(WCHAR).

For ANSI strings, the maximum number of bytes is NTSTRSAFE_MAX_CCH * sizeof(char).

### `pszSrc` [in]

Pointer to a null-terminated string. This string will be concatenated to the end of the string that is contained in the buffer at *pszDest*.

### `cbToAppend`

The maximum number of bytes to append to the string that is contained in the buffer at *pszDest*.

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means source data was present, the strings were concatenated without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means the concatenation operation did not complete due to insufficient buffer space. The destination buffer contains a truncated, null-terminated version of the intended result. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the function received an invalid input parameter. For more information, see the following paragraph.<br><br>The function returns the STATUS_INVALID_PARAMETER value when:<br><br>* The value in *cbDest* is larger than the maximum buffer size.<br>* The destination buffer was already full.<br>* A **NULL** pointer was present.<br>* The destination buffer's length was zero, but a nonzero length source string was present. |

## Remarks

**RtlStringCbCatNW** and **RtlStringCbCatNA** should be used instead of the following functions:

* **strncat**
* **wcsncat**

The size, in bytes, of the destination buffer is provided to **RtlStringCbCatNW** and **RtlStringCbCatNA** to ensure that they do not write past the end of the buffer.

Use **RtlStringCbCatNW** to handle Unicode strings and **RtlStringCbCatNA** to handle ANSI strings. The form you use depends on your data, as shown in the following table

| String data type | String literal | Function |
| --- | --- | --- |
| WCHAR | L"string" | **RtlStringCbCatNW** |
| **char** | "string" | **RtlStringCbCatNA** |

If *pszSrc* and *pszDest* point to overlapping strings, the behavior of the function is undefined.

Neither *pszSrc* nor *pszDest* can be **NULL**. If you need to handle **NULL** string pointer values, use [RtlStringCbCatNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcatnexa).

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCbCat](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcata)

[RtlStringCbCatNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcatnexa)

[RtlStringCchCatN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcatna)