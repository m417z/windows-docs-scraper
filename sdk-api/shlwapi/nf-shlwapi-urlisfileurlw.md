# UrlIsFileUrlW macro

## Description

Tests a URL to determine if it is a file URL.

## Parameters

### `pszURL`

Type: **LPCTSTR**

A pointer to a null-terminated string containing the URL.

## Remarks

A file URL has the form "File://
*xxx*". **UrlIsFileUrl** is actually one of the following macros, depending on whether ANSI or Unicode is selected.

```

#define  UrlIsFileUrlA(pszURL) UrlIsA(pszURL, URLIS_FILEURL)
#define  UrlIsFileUrlW(pszURL) UrlIsW(pszURL, URLIS_FILEURL)
				
```

> [!NOTE]
> The shlwapi.h header defines UrlIsFileUrl as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[UrlIs](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlisa)