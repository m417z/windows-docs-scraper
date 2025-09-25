# StringCchGetsExA function

## Description

Gets one line of text from stdin, up to and including the newline character ('\n'). The line of text is copied to the destination buffer, and the newline character is replaced with a null character. The size of the destination buffer is provided to the function to ensure that it does not write past the end of this buffer.

**Note** This function can only be used inline.

**StringCchGetsEx** adds to the functionality of [StringCchGets](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchgetsa) by returning a pointer to the end of the destination string as well as the number of characters left unused in that string. Flags may also be passed to the function for additional control.

**StringCchGetsEx** is a replacement for the following functions:

* [gets, _getws, _getts](https://learn.microsoft.com/cpp/c-runtime-library/gets-getws)

**StringCchGetsEx** is not a replacement for **fgets**, which does not replace newline characters with a terminating null character.

## Parameters

### `pszDest` [out]

Type: **LPTSTR**

The destination buffer, which receives the copied characters.

### `cchDest` [in]

Type: **size_t**

The size of the destination buffer, in characters. This value must be at least 2 for the function to succeed. The maximum number of characters allowed, including the terminating null character, is **STRSAFE_MAX_CCH**. If *cchDest* is too small to hold the full line of text, the data is truncated.

### `ppszDestEnd` [out, optional]

Type: **LPTSTR***

The address of a pointer to the end of *pszDest*. If *ppszDestEnd* is non-**NULL** and any data is copied into the destination buffer, this points to the terminating null character at the end of the string.

### `pcchRemaining` [out, optional]

Type: **size_t***

The number of unused characters in *pszDest*, including the terminating null character. If *pcchRemaining* is **NULL**, the count is not kept or returned.

### `dwFlags` [in]

Type: **DWORD**

One or more of the following values.

| Value | Meaning |
| --- | --- |
| **STRSAFE_FILL_BEHIND_NULL**<br><br>0x00000200 | If the function succeeds, the low byte of *dwFlags* (0) is used to fill the uninitialized portion of *pszDest* following the terminating null character. |
| **STRSAFE_IGNORE_NULLS**<br><br>0x00000100 | Treat **NULL** string pointers like empty strings (TEXT("")). This flag is useful for emulating functions such as [lstrcpy](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcpya). |
| **STRSAFE_FILL_ON_FAILURE**<br><br>0x00000400 | If the function fails, the low byte of *dwFlags* (0) is used to fill the entire *pszDest* buffer, and the buffer is null-terminated. In the case of a **STRSAFE_E_INSUFFICIENT_BUFFER** failure, any truncated string returned is overwritten. |
| **STRSAFE_NULL_ON_FAILURE**<br><br>0x00000800 | If the function fails, *pszDest* is set to an empty string (TEXT("")). In the case of a **STRSAFE_E_INSUFFICIENT_BUFFER** failure, any truncated string is overwritten. |
| **STRSAFE_NO_TRUNCATION**<br><br>0x00001000 | As in the case of STRSAFE_NULL_ON_FAILURE, if the function fails, *pszDest* is set to an empty string (TEXT("")). In the case of a **STRSAFE_E_INSUFFICIENT_BUFFER** failure, any truncated string is overwritten. |

## Return value

Type: **HRESULT**

This function can return one of the following values. It is strongly recommended that you use the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros to test the return value of this function.

| Return code | Description |
| --- | --- |
| **S_OK** | Characters were read from stdin, were copied to the buffer at *pszDest*, and the buffer was null-terminated. |
| **STRSAFE_E_END_OF_FILE** | Indicates an error or end-of-file condition. Use [feof](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/xssktc6e(v=vs.100)) or [ferror](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/y2wc3w90(v=vs.100)) to determine which one has occurred. |
| **STRSAFE_E_INVALID_PARAMETER** | The value in *cchDest* is larger than the maximum allowed value or an invalid flag was passed. |
| **STRSAFE_E_INSUFFICIENT_BUFFER** | The value in *cchDest* is 1 or less. |

Note that this function returns an **HRESULT** value, unlike the functions that it replaces.

## Remarks

**StringCchGetsEx** provides additional processing for proper buffer handling in your code. Poor buffer handling is implicated in many security issues that involve buffer overruns. **StringCchGetsEx** always null-terminates a nonzero-length destination buffer.

The value of *pszDest* should not be **NULL** unless the **STRSAFE_IGNORE_NULLS** flag is specified. However, an error due to insufficient space may still be returned even though **NULL** values are ignored.

**StringCchGetsEx** can be used in its generic form, or in its more specific forms. The data type of the string determines the form of this function that you should use, as shown in the following table.

| String Data Type | String Literal | Function |
| --- | --- | --- |
| **char** | "string" | **StringCchGetsExA** |
| **TCHAR** | TEXT("string") | **StringCchGetsEx** |
| **WCHAR** | L"string" | **StringCchGetsExW** |

> [!NOTE]
> The strsafe.h header defines StringCchGetsEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Reference**

[StringCbGetsEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbgetsexa)

[StringCchGets](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchgetsa)