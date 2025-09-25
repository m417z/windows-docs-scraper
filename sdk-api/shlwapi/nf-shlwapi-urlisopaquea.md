# UrlIsOpaqueA function

## Description

Returns whether a URL is opaque.

## Parameters

### `pszURL` [in]

Type: **PCTSTR**

A null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the URL.

## Return value

Type: **BOOL**

Returns a nonzero value if the URL is opaque, or zero otherwise.

## Remarks

A URL that has a scheme that is not followed by two slashes (//) is opaque. For example, mailto:xyz@litwareinc.com is an opaque URL. Opaque URLs cannot be separated into the standard URL hierarchy. **UrlIsOpaque** is equivalent to the following:

``` syntax
UrlIs(pszURL, URLIS_OPAQUE)
```

> [!NOTE]
> The shlwapi.h header defines UrlIsOpaque as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[UrlIs](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlisa)