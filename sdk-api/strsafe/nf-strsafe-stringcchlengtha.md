# StringCchLengthA function

## Description

Determines whether a string exceeds the specified length, in characters.

**StringCchLength** is a replacement for the following functions:

* [strlen, wcslen, _tcslen](https://learn.microsoft.com/cpp/c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l)

## Parameters

### `psz` [in]

Type: **LPCTSTR**

The string whose length is to be checked.

### `cchMax` [in]

Type: **size_t**

The maximum number of characters allowed in *psz*, including the terminating null character. This value cannot exceed **STRSAFE_MAX_CCH**.

### `pcchLength` [out]

Type: **size_t***

The number of characters in *psz*, not including the terminating null character. This value is valid only if *pcch* is not **NULL** and the function succeeds.

## Return value

Type: **HRESULT**

This function can return one of the following values. It is strongly recommended that you use the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros to test the return value of this function.

| Return code | Description |
| --- | --- |
| **S_OK** | The string at *psz* was not **NULL**, and the length of the string (including the terminating null character) is less than or equal to *cchMax* characters. |
| **STRSAFE_E_INVALID_PARAMETER** | The value in *psz* is **NULL**, *cchMax* is larger than **STRSAFE_MAX_CCH**, or *psz* is longer than *cchMax*. |

Note that this function returns an **HRESULT** value, unlike the functions that it replaces.

## Remarks

Compared to the functions it replaces, **StringCchLength** is an additional tool for proper buffer handling in your code. Poor buffer handling is implicated in many security issues that involve buffer overruns.

**StringCchLength** can be used in its generic form, or in its more specific forms. The data type of the string determines the form of this function that you should use.

| String Data Type | String Literal | Function |
| --- | --- | --- |
| **char** | "string" | **StringCchLengthA** |
| **TCHAR** | TEXT("string") | **StringCchLength** |
| **WCHAR** | L"string" | **StringCchLengthW** |

[UnalignedStringCchLength](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh305644(v=vs.85)) is an alias for this function.

> [!NOTE]
> The strsafe.h header defines StringCchLength as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[StringCbLength](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcblengtha)