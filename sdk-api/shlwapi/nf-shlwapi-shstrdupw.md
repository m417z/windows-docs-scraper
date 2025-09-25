# SHStrDupW function

## Description

Makes a copy of a string in newly allocated memory.

## Parameters

### `psz` [in]

Type: **LPCTSTR**

A pointer to the null-terminated string to be copied.

### `ppwsz` [out]

Type: **LPTSTR***

A pointer to an allocated Unicode string that contains the result. **SHStrDup** allocates memory for this string with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). You should free the string with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) when it is no longer needed.

In the case of failure, this value is NULL.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error value otherwise.

## Remarks

This function will take either Unicode or ANSI strings as input, but the copied string is always Unicode.

This function uses [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) to allocate memory for the copied string. You must free this memory with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) when it is no longer needed.

> [!NOTE]
> The shlwapi.h header defines SHStrDup as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[StrDup](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strdupa)