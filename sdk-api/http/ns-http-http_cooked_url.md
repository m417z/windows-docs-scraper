# HTTP_COOKED_URL structure

## Description

The
**HTTP_COOKED_URL** structure contains a validated, canonical, UTF-16 Unicode-encoded URL request string together with pointers into it and element lengths. This is the string that the HTTP Server API matches against registered
[UrlPrefix strings](https://learn.microsoft.com/windows/desktop/Http/urlprefix-strings) in order to route the request appropriately.

## Members

### `FullUrlLength`

Size, in bytes, of the data pointed to by the **pFullUrl** member, not including a terminating null character.

### `HostLength`

Size, in bytes, of the data pointed to by the **pHost** member.

### `AbsPathLength`

Size, in bytes, of the data pointed to by the **pAbsPath** member.

### `QueryStringLength`

Size, in bytes, of the data pointed to by the **pQueryString** member.

### `pFullUrl`

Pointer to the scheme element at the beginning of the URL (must be either "http://..." or "https://...").

### `pHost`

Pointer to the first character in the host element, immediately following the double slashes at the end of the scheme element.

### `pAbsPath`

Pointer to the third forward slash ("/") in the string. In a UrlPrefix string, this is the slash immediately preceding the relativeUri element.

### `pQueryString`

Pointer to the first question mark (?) in the string, or **NULL** if there is none.

## Remarks

For example, if **pFullUrl** is "http://www.fabrikam.com/path1/path2/file.ext?n1=v1&n2=v2", then **pHost** points to "www.fabrikam", **pAbsPath** points to "/path1/…" and **pQueryString** points to "?n1=v1…".

## See also

[HTTP Server API Version 1.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-structures)

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))