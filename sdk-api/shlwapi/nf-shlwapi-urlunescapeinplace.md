# UrlUnescapeInPlace macro

## Description

Converts escape sequences back into ordinary characters and overwrites the original string.

## Parameters

### `pszUrl` [in, out]

Type: **LPTSTR**

A pointer to a **null**-terminated string that contains the URL. The converted string is returned through this parameter.

### `dwFlags` [in]

Type: **DWORD**

The flags that control which characters are unescaped.

#### URL_DONT_UNESCAPE_EXTRA_INFO

Do not convert the # or ? character, or any characters following them in the string.

## Remarks

**UrlUnescapeInPlace** is equivalent to the following:

```

UrlUnescape(pszUrl, NULL, NULL, dwFlags | URL_UNESCAPE_INPLACE)
				
```

## See also

[UrlUnescape](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlunescapea)