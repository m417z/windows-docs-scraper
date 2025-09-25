# UrlCanonicalizeW function

## Description

Converts a URL string into canonical form.

## Parameters

### `pszUrl` [in]

Type: **PCTSTR**

A pointer to a null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains a URL string. If the string does not refer to a file, it must include a valid scheme such as "http://".

### `pszCanonicalized` [out]

Type: **PTSTR**

A pointer to a buffer that, when this function returns successfully, receives the converted URL as a null-terminated string.

### `pcchCanonicalized` [in, out]

Type: **DWORD***

A pointer to a value that, on entry, is set to the number of characters in the *pszCanonicalized* buffer.

### `dwFlags`

Type: **DWORD**

The flags that specify how the URL is converted to canonical form. The following flags can be combined.

#### URL_UNESCAPE (0x10000000)

Un-escape any escape sequences that the URLs contain, with two exceptions. The escape sequences for "?" and "#" are not un-escaped. If one of the URL_ESCAPE_XXX flags is also set, the two URLs are first un-escaped, then combined, then escaped.

#### URL_ESCAPE_UNSAFE (0x20000000)

Replace unsafe characters with their escape sequences. Unsafe characters are those characters that may be altered during transport across the Internet, and include the (<, >, ", #, {, }, |, \, ^, [, ], and ') characters. This flag applies to all URLs, including opaque URLs.

#### URL_PLUGGABLE_PROTOCOL (0x40000000)

Combine URLs with client-defined pluggable protocols, according to the W3C specification. This flag does not apply to standard protocols such as ftp, http, gopher, and so on. If this flag is set, [UrlCombine](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlcombinea) does not simplify URLs, so there is no need to also set **URL_DONT_SIMPLIFY**.

#### URL_ESCAPE_SPACES_ONLY (0x04000000)

Replace only spaces with escape sequences. This flag takes precedence over **URL_ESCAPE_UNSAFE**, but does not apply to opaque URLs.

#### URL_DONT_SIMPLIFY (0x08000000)

Treat "/./" and "/../" in a URL string as literal characters, not as shorthand for navigation. See Remarks for further discussion.

#### URL_NO_META (0x08000000)

Defined to be the same as **URL_DONT_SIMPLIFY**.

#### URL_ESCAPE_PERCENT (0x00001000)

Convert any occurrence of "%" to its escape sequence.

#### URL_ESCAPE_AS_UTF8 (0x00040000)

**Windows 7 and later**. Percent-encode all non-ASCII characters as their UTF-8 equivalents.

##### - dwFlags.URL_DONT_SIMPLIFY (0x08000000)

Treat "/./" and "/../" in a URL string as literal characters, not as shorthand for navigation. See Remarks for further discussion.

##### - dwFlags.URL_ESCAPE_AS_UTF8 (0x00040000)

**Windows 7 and later**. Percent-encode all non-ASCII characters as their UTF-8 equivalents.

##### - dwFlags.URL_ESCAPE_PERCENT (0x00001000)

Convert any occurrence of "%" to its escape sequence.

##### - dwFlags.URL_ESCAPE_SPACES_ONLY (0x04000000)

Replace only spaces with escape sequences. This flag takes precedence over **URL_ESCAPE_UNSAFE**, but does not apply to opaque URLs.

##### - dwFlags.URL_ESCAPE_UNSAFE (0x20000000)

Replace unsafe characters with their escape sequences. Unsafe characters are those characters that may be altered during transport across the Internet, and include the (<, >, ", #, {, }, |, \, ^, [, ], and ') characters. This flag applies to all URLs, including opaque URLs.

##### - dwFlags.URL_NO_META (0x08000000)

Defined to be the same as **URL_DONT_SIMPLIFY**.

##### - dwFlags.URL_PLUGGABLE_PROTOCOL (0x40000000)

Combine URLs with client-defined pluggable protocols, according to the W3C specification. This flag does not apply to standard protocols such as ftp, http, gopher, and so on. If this flag is set, [UrlCombine](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlcombinea) does not simplify URLs, so there is no need to also set **URL_DONT_SIMPLIFY**.

##### - dwFlags.URL_UNESCAPE (0x10000000)

Un-escape any escape sequences that the URLs contain, with two exceptions. The escape sequences for "?" and "#" are not un-escaped. If one of the URL_ESCAPE_XXX flags is also set, the two URLs are first un-escaped, then combined, then escaped.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function performs such tasks as replacing unsafe characters with their escape sequences and collapsing sequences like "..\...".

If a URL string contains "/../" or "/./", **UrlCanonicalize** treats the characters as indicating navigation in the URL hierarchy. The function simplifies the URLs before combining them. For instance "/hello/cruel/../world" is simplified to "/hello/world". Exceptions to this default behavior occur in these cases:

* If the **URL_DONT_SIMPLIFY** flag is set in *dwFlags*, the function does not simplify URLs. In this case, "/hello/cruel/../world" is left as it is.
* If "/../" or "/./" is the first segment in the path (for example, "http://domain/../path1/path2/file.htm"), **UrlCanonicalize** outputs the path exactly as it was input.

> [!NOTE]
> The shlwapi.h header defines UrlCanonicalize as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Handling Uniform Resource Locators](https://learn.microsoft.com/windows/desktop/WinInet/handling-uniform-resource-locators)