# StringCbCatNExW function

## Description

Concatenates the specified number of bytes from one string to another string. The size of the destination buffer is provided to the function to ensure that it does not write past the end of this buffer.

**StringCbCatNEx** is a replacement for the following functions:

* [strncat](https://learn.microsoft.com/cpp/c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l)
* [StrNCat](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strncata)

**StringCbCatNEx** adds to the functionality of [StringCbCatN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatna) by returning a pointer to the end of the destination string as well as the number of bytes left unused in that string. Flags may also be passed to the function for additional control.

## Parameters

### `pszDest` [in, out]

Type: **LPTSTR**

The destination buffer, which contains the string that is to be concatenated with *pszSrc*, and will receive the entire resultant string. The string at *pszSrc* is added to the end of the string at *pszDest*.

### `cbDest` [in]

Type: **size_t**

The size of the destination buffer, in bytes. This value must consider the length of *pszSrc* plus the length of *pszDest* plus the bytes used for the terminating null character. The maximum number of bytes allowed is `STRSAFE_MAX_CCH * sizeof(TCHAR)`.

### `pszSrc` [in]

Type: **LPCTSTR**

The source string that is to be concatenated to the end of *pszDest*. This string must be null-terminated.

### `cbToAppend` [in]

Type: **size_t**

The maximum number of bytes to append to *pszDest*.

### `ppszDestEnd` [out, optional]

Type: **LPTSTR***

The address of a pointer to the end of *pszDest*. If *ppszDestEnd* is non-**NULL** and any data is appended to the destination buffer, this points to the terminating null character at the end of the string.

### `pcbRemaining` [out, optional]

Type: **size_t***

The number of unused bytes in *pszDest*, including those used for the terminating null character. If *pcbRemaining* is **NULL**, the count is not kept or returned.

### `dwFlags` [in]

Type: **DWORD**

One or more of the following values.

| Value | Meaning |
| --- | --- |
| **STRSAFE_FILL_BEHIND_NULL**<br><br>0x00000200 | If the function succeeds, the low byte of *dwFlags* (0) is used to fill the uninitialized portion of *pszDest* following the terminating null character. |
| **STRSAFE_IGNORE_NULLS**<br><br>0x00000100 | Treat **NULL** string pointers like empty strings (TEXT("")). |
| **STRSAFE_FILL_ON_FAILURE**<br><br>0x00000400 | If the function fails, the low byte of *dwFlags* (0) is used to fill the entire *pszDest* buffer, and the buffer is null-terminated. In the case of a **STRSAFE_E_INSUFFICIENT_BUFFER** failure, any pre-existing or truncated string in the destination buffer is overwritten. |
| **STRSAFE_NULL_ON_FAILURE**<br><br>0x00000800 | If the function fails, *pszDest* is set to an empty string (TEXT("")). In the case of a **STRSAFE_E_INSUFFICIENT_BUFFER** failure, any pre-existing or truncated string in the destination buffer is overwritten. |
| **STRSAFE_NO_TRUNCATION**<br><br>0x00001000 | If the function fails, *pszDest* is untouched. Nothing is added to the original contents. |

## Return value

Type: **HRESULT**

This function can return one of the following values. It is strongly recommended that you use the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros to test the return value of this function.

| Return code | Description |
| --- | --- |
| **S_OK** | Source data was present, the strings were concatenated without truncation, and the resultant destination buffer is null-terminated. |
| **STRSAFE_E_INVALID_PARAMETER** | The value in *cbDest* is larger than `STRSAFE_MAX_CCH * sizeof(TCHAR)`, an invalid flag was passed, or there are discrepancies between the size of the *pszDest*, *cbDest*, and the amount of material to append in *pszSrc*. |
| **STRSAFE_E_INSUFFICIENT_BUFFER** | The copy operation failed due to insufficient buffer space. Depending on the value of *dwFlags*, the destination buffer may contain a truncated, null-terminated version of the intended result. In situations where truncation is acceptable, this may not necessarily be seen as a failure condition. |

Note that this function returns an **HRESULT** value, unlike the functions that it replaces.

## Remarks

Compared to the functions it replaces, **StringCbCatNEx** provides additional processing for proper buffer handling in your code. Poor buffer handling is implicated in many security issues that involve buffer overruns. **StringCbCatNEx** always null-terminates and never overflows a valid destination buffer, even if the contents of the source string change during the operation.

Behavior is undefined if the strings pointed to by *pszSrc* and *pszDest* overlap.

Neither *pszSrc* nor *pszDest* should be **NULL** unless the **STRSAFE_IGNORE_NULLS** flag is specified, in which case both may be **NULL**. However, an error due to insufficient space may still be returned even though **NULL** values are ignored.

**StringCbCatNEx** can be used in its generic form, or in its more specific forms. The data type of the string determines the form of this function that you should use.

| String Data Type | String Literal | Function |
| --- | --- | --- |
| **char** | "string" | **StringCbCatNExA** |
| **TCHAR** | TEXT("string") | **StringCbCatNEx** |
| **WCHAR** | L"string" | **StringCbCatNExW** |

> [!NOTE]
> The strsafe.h header defines StringCbCatNEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Reference**

[StringCbCatEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatexa)

[StringCbCatN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatna)

[StringCchCatNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatnexa)