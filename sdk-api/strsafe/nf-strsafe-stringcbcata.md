# StringCbCatA function

## Description

Concatenates one string to another string. The size of the destination buffer is provided to the function to ensure that it does not write past the end of this buffer.

**StringCbCat** is a replacement for the following functions:

* [strcat, wcscat, _tcsat](https://learn.microsoft.com/cpp/c-runtime-library/reference/strcat-wcscat-mbscat)
* [lstrcat](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcata)
* [StrCat](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strcatw)
* [StrCatBuff](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strcatbuffa)

## Parameters

### `pszDest` [in, out]

Type: **LPTSTR**

The string to which *pszSrc* is to be concatenated, and that will receive the entire resultant string. The string at *pszSrc* is added to the end of the string at *pszDest*.

### `cbDest` [in]

Type: **size_t**

The size of the destination buffer, in bytes. This value must consider the length of *pszSrc* plus the length of *pszDest* plus the terminating null character. The maximum number of bytes allowed is `STRSAFE_MAX_CCH * sizeof(TCHAR)`.

### `pszSrc` [in]

Type: **LPCTSTR**

The source string that is to be concatenated to the end of *pszDest*. This string must be null-terminated.

## Return value

Type: **HRESULT**

This function can return one of the following values. It is strongly recommended that you use the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros to test the return value of this function.

| Return code | Description |
| --- | --- |
| **S_OK** | Source data was present, the strings were fully concatenated without truncation, and the resultant destination buffer is null-terminated. |
| **STRSAFE_E_INVALID_PARAMETER** | The value in *cbDest* is either less than `sizeof(TCHAR)` or larger than the maximum allowed value. |
| **STRSAFE_E_INSUFFICIENT_BUFFER** | The concatenation operation failed due to insufficient buffer space. The destination buffer contains a truncated, null-terminated version of the intended result. In situations where truncation is acceptable, this may not necessarily be seen as a failure condition. |

Note that this function returns an **HRESULT** value, unlike the functions that it replaces.

## Remarks

**StringCbCat** provides additional processing for proper buffer handling in your code. Poor buffer handling is implicated in many security issues that involve buffer overruns. It always null-terminates and never overflows a valid destination buffer, even if the contents of the source string change during the operation.

**StringCbCat** can be used in its generic form, or in its more specific forms. The data type of the string determines the form of this function that you should use, as shown in the following table.

| String Data Type | String Literal | Function |
| --- | --- | --- |
| **char** | "string" | **StringCbCatA** |
| **TCHAR** | TEXT("string") | **StringCbCat** |
| **WCHAR** | L"string" | **StringCbCatW** |

Behavior is undefined if the strings pointed to by *pszSrc* and *pszDest* overlap.

Neither *pszSrc* nor *pszDest* should be **NULL**. See [StringCbCatEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatexa) if you require the handling of null string pointer values.

> [!NOTE]
> The strsafe.h header defines StringCbCat as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Reference**

[StringCbCatEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatexa)

[StringCbCatN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatna)

[StringCchCat](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcata)