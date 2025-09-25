# RtlStringCbPrintfW function

## Description

The **RtlStringCbPrintfW** and **RtlStringCbPrintfA** functions create a byte-counted text string, with formatting that is based on supplied formatting information.

## Parameters

### `pszDest` [out]

A pointer to a caller-supplied buffer that receives a formatted, null-terminated string. The function creates this string from both the formatting string that is supplied by *pszFormat* and the function's argument list.

### `cbDest` [in]

The size of the destination buffer, in bytes. The buffer must be large enough to contain the formatted string plus the terminating null character.

For Unicode strings, the maximum number of bytes is NTSTRSAFE_MAX_CCH * sizeof(WCHAR).

For ANSI strings, the maximum number of bytes is NTSTRSAFE_MAX_CCH * sizeof(char).

### `pszFormat` [in]

A pointer to a null-terminated text string that contains **printf**-styled [formatting directives](https://learn.microsoft.com/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions).

### `...`

A list of arguments that are interpreted by the function based on formatting directives contained in the *pszFormat* string.

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means source data was present, the string was created without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means the operation did not complete due to insufficient space in the destination buffer. The destination buffer contains a truncated version of the output string. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the function received an invalid input parameter. For more information, see the following paragraph.<br><br>The function returns the STATUS_INVALID_PARAMETER value when:<br><br>* The value in *cbDest* is larger than the maximum buffer size.<br>* The destination buffer was already full.<br>* A **NULL** pointer was present.<br>* The destination buffer's length was zero, but a nonzero length source string was present. |

## Remarks

**RtlStringCbPrintfW** and **RtlStringCbPrintfA** should be used instead of the following functions:

* **sprintf**
* **swprintf**
* _**snprintf**
* _**snwprintf**

All of these functions accept a format string and a list of arguments, interpret them, and create a formatted string. The size, in bytes, of the destination buffer is provided to **RtlStringCbPrintfW** and **RtlStringCbPrintfA** to ensure that they do not write past the end of the buffer.

Use **RtlStringCbPrintfW** to handle Unicode strings and **RtlStringCbPrintfA** to handle ANSI strings. The form you use depends on your data, as shown in the following table.

| String data type | String literal | Function |
| --- | --- | --- |
| WCHAR | L"string" | **RtlStringCbPrintfW** |
| **char** | "string" | **RtlStringCbPrintfA** |

If *pszDest* and *pszFormat* point to overlapping string or if any argument strings overlap, the behavior of the function is undefined.

Neither *pszFormat* nor *pszDest* can be **NULL**. If you need to handle **NULL** string pointer values, use [RtlStringCbPrintfEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbprintfexa).

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

#### Examples

The following example shows a basic use of **RtlStringCbPrintfW** using four arguments.

```
int const arraysize = 30;
WCHAR pszDest[arraysize];
size_t cbDest = arraysize * sizeof(WCHAR);

LPCWSTR pszFormat = L"%s %d + %d = %d.";
WCHAR* pszTxt = L"The answer is";

NTSTATUS status = RtlStringCbPrintfW(pszDest, cbDest, pszFormat, pszTxt, 1, 2, 3);
```

The resultant string is "The answer is 1 + 2 = 3." It is contained in the buffer at *pszDest*.

## See also

[RtlStringCbPrintfEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbprintfexa)

[RtlStringCbVPrintf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbvprintfa)

[RtlStringCchPrintf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchprintfa)