# UrlGetLocationA function

## Description

Retrieves the location from a URL.

## Parameters

### `pszURL` [in]

Type: **PCTSTR**

A null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the location.

## Return value

Type: **LPCTSTR**

Returns a pointer to a null-terminated string with the location, or **NULL** otherwise.

## Remarks

The location is the segment of the URL starting with a ? or # character. If a file URL has a query string, the returned string includes the query string.

> [!NOTE]
> The shlwapi.h header defines UrlGetLocation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).