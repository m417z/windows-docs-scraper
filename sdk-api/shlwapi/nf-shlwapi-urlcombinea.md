# UrlCombineA function

## Description

When provided with a relative URL and its base, returns a URL in canonical form.

## Parameters

### `pszBase` [in]

Type: **PCTSTR**

A pointer to a null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the base URL.

### `pszRelative` [in]

Type: **PCTSTR**

A pointer to a null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the relative URL.

### `pszCombined` [out, optional]

Type: **PTSTR**

A pointer to a buffer that, when this function returns successfully, receives a null-terminated string that contains the combined URL.

### `pcchCombined` [in, out]

Type: **DWORD***

A pointer to a value that, on entry, is set to the number of characters in the *pszCombined* buffer. When the function returns successfully, the value depends on whether the function is successful or returns E_POINTER. For other return values, the value of this parameter is meaningless.

### `dwFlags`

Type: **DWORD**

Flags that specify how the URL is converted to canonical form. The following flags can be combined.

#### URL_DONT_SIMPLIFY (0x08000000)

Treat '/./' and '/../' in a URL string as literal characters, not as shorthand for navigation. See Remarks for further discussion.

#### URL_ESCAPE_PERCENT (0x00001000)

Convert any occurrence of '%' to its escape sequence.

#### URL_ESCAPE_SPACES_ONLY (0x04000000)

Replace only spaces with escape sequences. This flag takes precedence over **URL_ESCAPE_UNSAFE**, but does not apply to opaque URLs.

#### URL_ESCAPE_UNSAFE (0x20000000)

Replace unsafe characters with their escape sequences. Unsafe characters are those characters that may be altered during transport across the Internet, and include the (<, >, ", #, {, }, |, \, ^, ~, [, ], and ') characters. This flag applies to all URLs, including opaque URLs.

#### URL_NO_META

Defined to be the same as **URL_DONT_SIMPLIFY**.

#### URL_PLUGGABLE_PROTOCOL (0x40000000)

Combine URLs with client-defined pluggable protocols, according to the W3C specification. This flag does not apply to standard protocols such as ftp, http, gopher, and so on. If this flag is set, **UrlCombine** does not simplify URLs, so there is no need to also set **URL_DONT_SIMPLIFY**.

#### URL_UNESCAPE (0x10000000)

Un-escape any escape sequences that the URLs contain, with two exceptions. The escape sequences for '?' and '#' are not un-escaped. If one of the URL_ESCAPE_XXX flags is also set, the two URLs are first un-escaped, then combined, then escaped.

#### URL_ESCAPE_AS_UTF8 (0x00040000)

**Windows 7 and later**. Percent-encode all non-ASCII characters as their UTF-8 equivalents.

## Return value

Type: **HRESULT**

Returns standard COM error codes, including the following.

| Return code | Description |
| --- | --- |
| **S_OK** | *pszCombined* points to a string that contains the combined URLs. The value of *pcchCombined* is set to the number of characters in the string, not counting the terminating **NULL** character. |
| **E_POINTER** | The buffer was too small. The value of *pcchCombined* is set to the minimum number of characters that the buffer must be able to contain, including the terminating **NULL** character. |

## Remarks

Items between slashes are treated as hierarchical identifiers; the last item specifies the document itself. You must enter a slash (/) after the document name to append more items; otherwise, **UrlCombine** exchanges one document for another. For example:

```

hRetVal = UrlCombine(TEXT("http://xyz/test/abc"),
                     TEXT("bar"),
                     lpszCombined,
                     &dwLength, 0);
```

The preceding code returns the URL http://xyz/test/bar. If you want the combined URL to be http://xyz/test/abc/bar, use the following call to **UrlCombine**.

```

hRetVal = UrlCombine(TEXT("http://xyz/test/abc/"),
                     TEXT("bar"),
                     lpszCombined,
                     &dwLength, 0);
```

If a URL string contains '/../' or '/./', **UrlCombine** usually treats the characters as if they indicated navigation in the URL hierarchy. The function simplifies the URLs before combining them. For instance, "/hello/cruel/../world" is simplified to "/hello/world". If the **URL_DONT_SIMPLIFY** flag is set in *dwFlags*, the function does not simplify URLs. In this case, "/hello/cruel/../world" is left as it is.

> [!NOTE]
> The shlwapi.h header defines UrlCombine as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Handling Uniform Resource Locators](https://learn.microsoft.com/windows/desktop/WinInet/handling-uniform-resource-locators)

[UrlCanonicalize](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlcanonicalizea)