# StringCbCopyNW function

## Description

Copies the specified number of bytes from one string to another. The size of the destination buffer is provided to the function to ensure that it does not write past the end of this buffer.

**StringCbCopyN** is a replacement for the following functions:

* [strncpy, wcsncpy, _tcsncpy](https://learn.microsoft.com/cpp/c-runtime-library/reference/strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l)

## Parameters

### `pszDest` [out]

Type: **LPTSTR**

The destination buffer, which receives the copied characters.

### `cbDest` [in]

Type: **size_t**

The size of *pszDest*, in bytes. This value must be large enough to hold the copied bytes (the size of *pszSrc* or the value of *cbSrc*, whichever is smaller) and also account for the terminating null character. The maximum number of characters allowed is `STRSAFE_MAX_CCH * sizeof(TCHAR)`.

### `pszSrc` [in]

Type: **LPCTSTR**

The source string. This string must be null-terminated.

### `cbToCopy` [in]

Type: **size_t**

The maximum number of bytes to be copied from *pszSrc* to *pszDest*.

## Return value

Type: **HRESULT**

This function can return one of the following values. It is strongly recommended that you use the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros to test the return value of this function.

| Return code | Description |
| --- | --- |
| **S_OK** | Source data was present, the data was copied from *pszSrc* without truncation, and the resultant destination buffer is null-terminated. |
| **STRSAFE_E_INVALID_PARAMETER** | The value in *cbDest* is either larger than `STRSAFE_MAX_CCH * sizeof(TCHAR)`, or the destination buffer is already full. |
| **STRSAFE_E_INSUFFICIENT_BUFFER** | The copy operation failed due to insufficient buffer space. The destination buffer contains a truncated, null-terminated version of the intended result. In situations where truncation is acceptable, this may not necessarily be seen as a failure condition. |

Note that this function returns an **HRESULT** value, unlike the functions that it replaces.

## Remarks

**StringCbCopyN** provides additional processing for proper buffer handling in your code. Poor buffer handling is implicated in many security issues that involve buffer overruns. **StringCbCopyN** always null-terminates and never overflows a valid destination buffer, even if the contents of the source string change during the operation.

While this routine is meant as a replacement for [strncpy](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/xdsywd25(v=vs.100)), there are differences in behavior. If *cbSrc* is larger than the number of bytes in *pszSrc*, **StringCbCopyN**—unlike **strncpy**—does not continue to pad *pszDest* with null characters until *cbSrc* bytes have been copied.

Behavior is undefined if the strings pointed to by *pszSrc* and *pszDest* overlap.

Neither *pszSrc* nor *pszDest* should be **NULL**. See [StringCbCopyNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopynexa) if you require the handling of null string pointer values.

**StringCbCopyN** can be used in its generic form, or in its more specific forms. The data type of the string determines the form of this function that you should use, as shown in the following table.

| String Data Type | String Literal | Function |
| --- | --- | --- |
| **char** | "string" | **StringCbCopyNA** |
| **TCHAR** | TEXT("string") | **StringCbCopyN** |
| **WCHAR** | L"string" | **StringCbCopyNW** |

> [!NOTE]
> The strsafe.h header defines StringCbCopyN as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Reference**

[StringCbCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopya)

[StringCbCopyNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopynexa)

[StringCchCopyN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopyna)