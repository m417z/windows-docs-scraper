# StringCbLengthW function

## Description

Determines whether a string exceeds the specified length, in bytes.

**StringCbLength** is a replacement for the following functions:

* [strlen, wcslen, _tcslen](https://learn.microsoft.com/cpp/c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l)

## Parameters

### `psz` [in]

Type: **LPCTSTR**

The string whose length is to be checked.

### `cbMax` [in]

Type: **size_t**

The maximum number of bytes allowed in *psz*, including those used for the terminating null character. This value cannot exceed `STRSAFE_MAX_CCH * sizeof(TCHAR)`.

### `pcbLength` [out]

Type: **size_t***

The number of bytes in *psz*, excluding those used for the terminating null character. This value is valid only if *pcb* is not **NULL** and the function succeeds.

## Return value

Type: **HRESULT**

This function can return one of the following values. It is strongly recommended that you use the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros to test the return value of this function.

| Return code | Description |
| --- | --- |
| **S_OK** | The string at *psz* was not **NULL**, and the length of the string (including the terminating null character) is less than or equal to *cbMax* characters. |
| **STRSAFE_E_INVALID_PARAMETER** | The value in *psz* is **NULL**, *cbMax* is larger than `STRSAFE_MAX_CCH * sizeof(TCHAR)`, or *psz* is longer than *cbMax*. |

Note that this function returns an **HRESULT** value, unlike the functions that it replaces.

## Remarks

Compared to the functions it replaces, **StringCbLength** is an additional tool for proper buffer handling in your code. Poor buffer handling is implicated in many security issues that involve buffer overruns.

**StringCbLength** can be used in its generic form, or in its more specific forms. The data type of the string determines the form of this function that you should use.

| String Data Type | String Literal | Function |
| --- | --- | --- |
| **char** | "string" | **StringCbLengthA** |
| **TCHAR** | TEXT("string") | **StringCbLength** |
| **WCHAR** | L"string" | **StringCbLengthW** |

[UnalignedStringCbLength](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh305643(v=vs.85)) is an alias for this function.

> [!NOTE]
> The strsafe.h header defines StringCbLength as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[StringCchLength](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchlengtha)