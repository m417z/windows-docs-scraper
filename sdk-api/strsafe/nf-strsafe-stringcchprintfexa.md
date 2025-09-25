# StringCchPrintfExA function

## Description

Writes formatted data to the specified string. The size of the destination buffer is provided to the function to ensure that it does not write past the end of this buffer.

**StringCchPrintfEx** adds to the functionality of [StringCchPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa) by returning a pointer to the end of the destination string as well as the number of characters left unused in that string. Flags may also be passed to the function for additional control.

**StringCchPrintfEx** is a replacement for the following functions:

* [sprintf, swprintf, _stprintf](https://learn.microsoft.com/cpp/c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l)
* [wsprintf](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-wsprintfa)
* [wnsprintf](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-wnsprintfa)
* [_snprintf, _snwprintf, _sntprintf](https://learn.microsoft.com/cpp/c-runtime-library/reference/snprintf-snprintf-snprintf-l-snwprintf-snwprintf-l)

## Parameters

### `pszDest` [out]

Type: **LPTSTR**

The destination buffer, which receives the formatted, null-terminated string created from *pszFormat* and its arguments.

### `cchDest` [in]

Type: **size_t**

The size of the destination buffer, in characters. This value must be sufficiently large to accommodate the final formatted string plus 1 to account for the terminating null character. The maximum number of characters allowed is **STRSAFE_MAX_CCH**.

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
| **STRSAFE_IGNORE_NULLS**<br><br>0x00000100 | Treat **NULL** string pointers like empty strings (TEXT("")). |
| **STRSAFE_FILL_ON_FAILURE**<br><br>0x00000400 | If the function fails, the low byte of *dwFlags* (0) is used to fill the entire *pszDest* buffer, and the buffer is null-terminated. In the case of a **STRSAFE_E_INSUFFICIENT_BUFFER** failure, any truncated string returned is overwritten. |
| **STRSAFE_NULL_ON_FAILURE**<br><br>0x00000800 | If the function fails, *pszDest* is set to an empty string (TEXT("")). In the case of a **STRSAFE_E_INSUFFICIENT_BUFFER** failure, any truncated string is overwritten. |
| **STRSAFE_NO_TRUNCATION**<br><br>0x00001000 | As in the case of **STRSAFE_NULL_ON_FAILURE**, if the function fails, *pszDest* is set to an empty string (TEXT("")). In the case of a **STRSAFE_E_INSUFFICIENT_BUFFER** failure, any truncated string is overwritten. |

### `pszFormat` [in]

Type: **LPCTSTR**

The format string. This string must be null-terminated. For more information, see [Format Specification Syntax](https://learn.microsoft.com/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions).

### `...`

The Arguments to be inserted into the *pszFormat* string.

## Return value

Type: **HRESULT**

This function can return one of the following values. It is strongly recommended that you use the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros to test the return value of this function.

| Return code | Description |
| --- | --- |
| **S_OK** | There was sufficient space for the result to be copied to *pszDest* without truncation and the buffer is null-terminated. |
| **STRSAFE_E_INVALID_PARAMETER** | The value in *cchDest* is either 0 or larger than **STRSAFE_MAX_CCH**, or the destination buffer is already full. |
| **STRSAFE_E_INSUFFICIENT_BUFFER** | The copy operation failed due to insufficient buffer space. Depending on the value of *dwFlags*, the destination buffer may contain a truncated, null-terminated version of the intended result. In situations where truncation is acceptable, this may not necessarily be seen as a failure condition. |

Note that this function returns an **HRESULT** value, unlike the functions that it replaces.

## Remarks

Compared to the functions it replaces, **StringCchPrintfEx** provides additional processing for proper buffer handling in your code. Poor buffer handling is implicated in many security issues that involve buffer overruns. **StringCchPrintfEx** always null-terminates a nonzero-length destination buffer.

Behavior is undefined if the strings pointed to by *pszDest*, *pszFormat*, or any argument strings overlap.

Neither *pszFormat* nor *pszDest* should be **NULL** unless the **STRSAFE_IGNORE_NULLS** flag is specified, in which case both may be **NULL**. However, an error due to insufficient space may still be returned even though **NULL** values are ignored.

**StringCchPrintfEx** can be used in its generic form, or in its more specific forms. The data type of the string determines the form of this function that you should use.

| String Data Type | String Literal | Function |
| --- | --- | --- |
| **char** | "string" | **StringCchPrintfExA** |
| **TCHAR** | TEXT("string") | **StringCchPrintfEx** |
| **WCHAR** | L"string" | **StringCchPrintfExW** |

> [!NOTE]
> The strsafe.h header defines StringCchPrintfEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Reference**

[StringCbPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbprintfexa)

[StringCchPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa)

[StringCchVPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchvprintfexa)