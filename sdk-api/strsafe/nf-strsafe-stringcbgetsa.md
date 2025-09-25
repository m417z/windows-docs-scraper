# StringCbGetsA function

## Description

Gets one line of text from stdin, up to and including the newline character ('\n'). The line of text is copied to the destination buffer, and the newline character is replaced with a null character. The size of the destination buffer is provided to the function to ensure that it does not write past the end of this buffer.

**Note** This function can only be used inline.

**StringCbGets** is a replacement for the following functions:

* [gets, _getws, _getts](https://learn.microsoft.com/cpp/c-runtime-library/gets-getws)

**StringCbGets** is not a replacement for **fgets**, which does not replace newline characters with a terminating null character.

## Parameters

### `pszDest` [out]

Type: **LPTSTR**

The destination buffer, which receives the input.

### `cbDest` [in]

Type: **size_t**

The size of the destination buffer, in bytes. This value must be greater than `sizeof(TCHAR)` for the function to succeed. The maximum number of bytes allowed is `STRSAFE_MAX_CCH * sizeof(TCHAR)`. If *cbDest* is too small to hold the full line of text, the data is truncated.

## Return value

Type: **HRESULT**

This function can return one of the following values. It is strongly recommended that you use the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros to test the return value of this function.

| Return code | Description |
| --- | --- |
| **S_OK** | Data was read from stdin, was copied to the buffer at *pszDest*, and the buffer was null-terminated. |
| **STRSAFE_E_END_OF_FILE** | Indicates an error or end-of-file condition. Use [feof](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/xssktc6e(v=vs.100)) or [ferror](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/y2wc3w90(v=vs.100)) to determine which one has occurred. |
| **STRSAFE_E_INVALID_PARAMETER** | The value in *cbDest* is larger than the maximum allowed value. |
| **STRSAFE_E_INSUFFICIENT_BUFFER** | The value in *cbDest* is `sizeof(TCHAR)` or less. |

Note that this function returns an **HRESULT** value, unlike the functions that it replaces.

## Remarks

**StringCbGets** provides additional processing for proper buffer handling in your code. Poor buffer handling is implicated in many security issues that involve buffer overruns. **StringCbGets** always null-terminates a nonzero-length destination buffer.

The value of *pszDest* should not be **NULL**. See [StringCbGetsEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbgetsexa) if you require the handling of null string pointer values.

**StringCbGets** can be used in its generic form, or in its more specific forms. The data type of the string determines the form of this function that you should use, as shown in the following table.

| String Data Type | String Literal | Function |
| --- | --- | --- |
| **char** | "string" | **StringCbGetsA** |
| **TCHAR** | TEXT("string") | **StringCbGets** |
| **WCHAR** | L"string" | **StringCbGetsW** |

> [!NOTE]
> The strsafe.h header defines StringCbGets as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Reference**

[StringCbGetsEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbgetsexa)

[StringCchGets](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchgetsa)