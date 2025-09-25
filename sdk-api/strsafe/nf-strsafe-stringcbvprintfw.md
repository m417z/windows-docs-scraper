# StringCbVPrintfW function

## Description

Writes formatted data to the specified string using a pointer to a list of arguments. The size of the destination buffer is provided to the function to ensure that it does not write past the end of this buffer.

**StringCbVPrintf** is a replacement for the following functions:

* [vsprintf, vswprintf, _vstprintf](https://learn.microsoft.com/cpp/c-runtime-library/reference/vsprintf-vsprintf-l-vswprintf-vswprintf-l-vswprintf-l)
* [vsnprintf, _vsnwprintf, _vsntprintf](https://learn.microsoft.com/cpp/c-runtime-library/reference/vsnprintf-vsnprintf-vsnprintf-l-vsnwprintf-vsnwprintf-l)
* [wvsprintf](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-wvsprintfa)
* [wvnsprintf](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-wvnsprintfa)

## Parameters

### `pszDest` [out]

Type: **LPTSTR**

The destination buffer, which receives the formatted, null-terminated string created from *pszFormat* and *argList*.

### `cbDest` [in]

Type: **size_t**

The size of the destination buffer, in bytes. This value must be sufficiently large to accommodate the final formatted string plus the terminating null character. The maximum number of bytes allowed is `STRSAFE_MAX_CCH * sizeof(TCHAR)`.

### `pszFormat` [in]

Type: **LPCTSTR**

The format string. This string must be null-terminated. For more information, see [Format Specification Syntax](https://learn.microsoft.com/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions).

### `argList` [in]

Type: **va_list**

The arguments to be inserted into the *pszFormat* string.

## Return value

Type: **HRESULT**

This function can return one of the following values. It is strongly recommended that you use the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros to test the return value of this function.

| Return code | Description |
| --- | --- |
| **S_OK** | There was sufficient space for the result to be copied to *pszDest* without truncation, and the buffer is null-terminated. |
| **STRSAFE_E_INVALID_PARAMETER** | The value in *cbDest* is either 0 or larger than `STRSAFE_MAX_CCH * sizeof(TCHAR)`. |
| **STRSAFE_E_INSUFFICIENT_BUFFER** | The copy operation failed due to insufficient buffer space. The destination buffer contains a truncated, null-terminated version of the intended result. In situations where truncation is acceptable, this may not necessarily be seen as a failure condition. |

Note that this function returns an **HRESULT** value, unlike the functions that it replaces.

## Remarks

**StringCbVPrintf** provides additional processing for proper buffer handling in your code. Poor buffer handling is implicated in many security issues that involve buffer overruns. **StringCbVPrintf** always null-terminates a nonzero-length destination buffer.

For more information on va_lists, see the conventions defined in Stdarg.h.

Behavior is undefined if the strings pointed to by *pszDest*, *pszFormat*, or any argument strings overlap.

Neither *pszFormat* nor *pszDest* should be **NULL**. See [StringCbVPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbvprintfexa) if you require the handling of null string pointer values.

**StringCbVPrintf** can be used in its generic form, or in its more specific forms. The data type of the string determines the form of this function that you should use, as shown in the following table.

| String Data Type | String Literal | Function |
| --- | --- | --- |
| **char** | "string" | **StringCbVPrintfA** |
| **TCHAR** | TEXT("string") | **StringCbVPrintf** |
| **WCHAR** | L"string" | **StringCbVPrintfW** |

> [!NOTE]
> The strsafe.h header defines StringCbVPrintf as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Reference**

[StringCbPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbprintfa)

[StringCbVPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbvprintfexa)

[StringCchVPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchvprintfa)