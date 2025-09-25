# RtlStringCchCatA function

## Description

The **RtlStringCchCatW** and **RtlStringCchCatA** functions concatenate two character-counted strings.

## Parameters

### `pszDest` [in, out]

A pointer to a buffer which, on input, contains a null-terminated string to which *pszSrc* will be concatenated. On output, this is the destination buffer that contains the entire resultant string. The string at *pszSrc* is added to the end of the string at *pszDest* and terminated with a null character.

### `cchDest` [in]

The size, in characters, of the destination buffer. The maximum number of characters allowed is NTSTRSAFE_MAX_CCH.

### `pszSrc` [in]

A pointer to a null-terminated string. This string will be concatenated to the end of the string that is contained in the buffer at *pszDest*.

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means source data was present, the output string was created without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means the operation did not complete due to insufficient space in the destination buffer. The destination buffer contains a truncated, null-terminated version of the intended result. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the function received an invalid input parameter. For more information, see the following paragraph.<br><br>The function returns the STATUS_INVALID_PARAMETER value when:<br><br>* The value in *cchDest*  is larger than the maximum buffer size.<br>* The destination buffer was already full.<br>* A **NULL** pointer was present.<br>* The destination buffer pointer was **NULL**, but the buffer size was not zero.<br>* The destination buffer length was zero, but a nonzero length source string was present. |

## Remarks

**RtlStringCchCatW** and **RtlStringCchCatA** should be used instead of the following functions:

* **strcat**
* **wcscat**

The size, in characters, of the destination buffer is provided to ensure that **RtlStringCchCatW** and **RtlStringCchCatA** do not write past the end of the buffer.

Use **RtlStringCchCatW** to handle Unicode strings and **RtlStringCchCatA** to handle ANSI strings. The form you use depends on your data, as shown in the following table.

| String data type | String literal | Function |
| --- | --- | --- |
| WCHAR | L"string" | **RtlStringCchCatW** |
| **char** | "string" | **RtlStringCchCatA** |

If *pszSrc* and *pszDest* point to overlapping strings, the behavior of the function is undefined.

Neither *pszSrc* nor *pszDest* can be **NULL**. If you need to handle **NULL** string pointer values, use [RtlStringCchCatEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcatexa).

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCbCat](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcata)

[RtlStringCchCatEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcatexa)

[RtlStringCchCatN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcatna)