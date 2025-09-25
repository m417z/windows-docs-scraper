# RtlStringCchPrintfW function

## Description

The **RtlStringCchPrintfW** and **RtlStringCchPrintfA** functions create a character-counted text string, with formatting that is based on supplied formatting information.

## Parameters

### `pszDest` [out]

A pointer to a caller-supplied buffer that receives a formatted, null-terminated string. The function creates this string from both the formatting string that is supplied by *pszFormat* and the function's argument list.

### `cchDest` [in]

The size of the destination buffer, in characters. The buffer must be large enough to contain the formatted string plus the terminating null character. The maximum number of characters allowed is **NTSTRSAFE_MAX_CCH**.

### `pszFormat` [in]

A pointer to a null-terminated text string that contains **printf**-styled [formatting directives](https://learn.microsoft.com/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions).

### `...`

A list of arguments that are interpreted by the function, based on formatting directives contained in the *pszFormat* string.

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means source data was present, the string was created without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means the operation did not complete due to insufficient space in the destination buffer. The destination buffer contains a truncated version of the output string. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the function received an invalid input parameter. For more information, see the following paragraph.<br><br>The function returns the STATUS_INVALID_PARAMETER value when:<br><br>* The value in *cchDest*  is larger than the maximum buffer size.<br>* The destination buffer was already full.<br>* A **NULL** pointer was present.<br>* The destination buffer's length was zero, but a nonzero length source string was present. |

## Remarks

**RtlStringCchPrintfW** and **RtlStringCchPrintfA** should be used instead of the following functions:

* **sprintf**
* **swprintf**
* _**snprintf**
* _**snwprintf**

All of these functions accept a format string and a list of arguments and return a formatted string. **RtlStringCchPrintfW** and **RtlStringCchPrintfA** accept the size, in characters, of the destination buffer to ensure that the functions do not write past the end of the buffer.

Use **RtlStringCchPrintfW** to handle Unicode strings and **RtlStringCchPrintfA** to handle ANSI strings. The form you use depends on your data.

| String data type | String literal | Function |
| --- | --- | --- |
| WCHAR | L"string" | **RtlStringCchPrintfW** |
| **char** | "string" | **RtlStringCchPrintfA** |

If *pszDest* and *pszFormat* point to overlapping strings, or if any argument strings overlap, behavior of the function is undefined.

Neither *pszFormat* nor *pszDest* can be **NULL**. If you need to handle **NULL** string pointer values, use [RtlStringCchPrintfEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchprintfexa).

#### Examples

The following example shows a simple use of **RtlStringCchPrintfW** using four arguments.

```
WCHAR pszDest[30];
size_t cchDest = 30;

LPCWSTR pszFormat = L"%s %d + %d = %d.";
WCHAR* pszTxt = L"The answer is";

NTSTATUS status =
    RtlStringCchPrintfW(pszDest, cchDest, pszFormat, pszTxt, 1, 2, 3);
```

The resultant string is "The answer is 1 + 2 = 3." It is contained in the buffer at *pszDest*.

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCbPrintf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbprintfa)

[RtlStringCchPrintfEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchprintfexa)

[RtlStringCchVPrintf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchvprintfa)