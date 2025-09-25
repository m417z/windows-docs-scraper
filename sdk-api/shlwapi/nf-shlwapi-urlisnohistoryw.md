# UrlIsNoHistoryW function

## Description

Returns whether a URL is a URL that browsers typically do not include in navigation history.

## Parameters

### `pszURL` [in]

Type: **PCTSTR**

A null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the URL.

## Return value

Type: **BOOL**

Returns a nonzero value if the URL is a URL that is not included in navigation history, or zero otherwise.

## Remarks

This function is equivalent to the following:

``` syntax
UrlIs(pszURL, URLIS_NOHISTORY)
```

## See also

[UrlIs](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlisa)