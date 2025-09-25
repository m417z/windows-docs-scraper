# RtlStringCchVPrintfA function

## Description

The **RtlStringCchVPrintfW** and **RtlStringCchVPrintfA** functions create a character-counted text string, with formatting that is based on supplied formatting information.

## Parameters

### `pszDest` [out]

A pointer to a caller-supplied buffer that receives a formatted, null-terminated string. The function creates this string from both the formatting string that is supplied by *pszFormat* and the arguments supplied by *argList*.

### `cchDest` [in]

The size of the destination buffer, in characters. The buffer must be large enough to contain the formatted string plus the terminating null character. The maximum number of characters allowed is NTSTRSAFE_MAX_CCH.

### `pszFormat` [in]

A pointer to a null-terminated text string that contains **printf**-styled formatting directives.

### `argList` [in]

A **va_list**-typed argument list. Arguments contained in the argument list will be interpreted by using the formatting string that is supplied by *pszFormat*.

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means source data was present, the output string was created without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means the operation did not complete due to insufficient space in the destination buffer. The destination buffer contains a truncated version of the created string. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the function received an invalid input parameter. For more information, see the following paragraph.<br><br>The function returns the STATUS_INVALID_PARAMETER value when:<br><br>* The value in *cchDest*  is larger than the maximum buffer size.<br>* The destination buffer was already full.<br>* A **NULL** pointer was present.<br>* The destination buffer length was zero, but a nonzero length source string was present. |

## Remarks

**RtlStringCchVPrintfW** and **RtlStringCchVPrintfA** should be used instead of the following functions:

* **vsprintf**
* **vswprintf**
* _**vsnprintf**
* _**vsnwprintf**

All of these functions accept a format string and its arguments, which are provided as a **va_list**-typed argument list, and return a formatted string. **RtlStringCchVPrintfW** and **RtlStringCchVPrintfA** receive the size, in characters, of the destination buffer to ensure that the functions do not write past the end of the buffer.

For more information about **va_list**-typed argument lists, see the Microsoft Windows SDK documentation.

Use **RtlStringCchVPrintfW** to handle Unicode strings and **RtlStringCchVPrintfA** to handle ANSI strings. The form you use depends on your data, as shown in the following table.

| String data type | String literal | Function |
| --- | --- | --- |
| WCHAR | L"string" | **RtlStringCchVPrintfW** |
| **char** | "string" | **RtlStringCchVPrintfA** |

If *pszDest* and *pszFormat* point to overlapping strings, or if any argument strings overlap, the behavior of the function is undefined.

Neither *pszFormat* nor *pszDest* can be **NULL**. If you need to handle **NULL** string pointer values, use [RtlStringCchVPrintfEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchvprintfexa).

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCbVPrintf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbvprintfa)

[RtlStringCchPrintf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchprintfa)

[RtlStringCchVPrintfEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchvprintfexa)