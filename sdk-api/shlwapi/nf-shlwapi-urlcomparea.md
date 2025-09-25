# UrlCompareA function

## Description

Makes a case-sensitive comparison of two URL strings.

## Parameters

### `psz1` [in]

Type: **PCTSTR**

A null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the first URL.

### `psz2` [in]

Type: **PCTSTR**

A null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the second URL.

### `fIgnoreSlash`

Type: **BOOL**

A value that is set to **TRUE** to have **UrlCompare** ignore a trailing '/' character on either or both URLs.

## Return value

Type: **int**

Returns zero if the two strings are equal. The function will also return zero if *fIgnoreSlash* is set to **TRUE** and one of the strings has a trailing '\' character. The function returns a negative integer if the string pointed to by *psz1* is less than the string pointed to by *psz2*. Otherwise, it returns a positive integer.

## Remarks

For best results, you should first canonicalize the URLs with [UrlCanonicalize](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlcanonicalizea). Then, compare the canonicalized URLs with **UrlCompare**.

> [!NOTE]
> The shlwapi.h header defines UrlCompare as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[StrCmp](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strcmpw)