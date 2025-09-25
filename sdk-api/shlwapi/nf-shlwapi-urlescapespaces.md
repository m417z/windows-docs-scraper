# UrlEscapeSpaces macro

## Description

A macro that converts space characters into their corresponding escape sequence.

## Parameters

### `pszUrl` [in]

Type: **LPCTSTR**

A pointer to a URL string. If it does not refer to a file, it must include a valid scheme such as "http://".

### `pszEscaped` [out]

Type: **LPTSTR**

A pointer to a null-terminated string containing the string pointed to by *pszURL*, with space characters converted to their escape sequence.

### `pcchEscaped` [out]

Type: **LPDWORD**

The number of characters in *pszEscaped*.

## Remarks

**UrlEscapeSpaces** is equivalent to the following:

```

UrlCanonicalize(pszUrl,
                pszEscaped,
                pcchEscaped,
                URL_ESCAPE_SPACES_ONLY | URL_DONT_ESCAPE_EXTRA_INFO )
				
```

## See also

[UrlCanonicalize](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlcanonicalizea)