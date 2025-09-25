# INTERNET_SCHEME enumeration

## Description

Defines the flags used with the
**nScheme** member of the
[URL_COMPONENTS](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-url_componentsa) structure.

## Constants

### `INTERNET_SCHEME_PARTIAL:-2`

Partial URL.

### `INTERNET_SCHEME_UNKNOWN:-1`

Unknown URL scheme.

### `INTERNET_SCHEME_DEFAULT:0`

Default URL scheme.

### `INTERNET_SCHEME_FTP`

FTP URL scheme (ftp:).

### `INTERNET_SCHEME_GOPHER`

Gopher URL scheme (gopher:).

**Note** Windows XP and Windows Server 2003 R2 and earlier only.

### `INTERNET_SCHEME_HTTP`

HTTP URL scheme (http:).

### `INTERNET_SCHEME_HTTPS`

HTTPS URL scheme (https:).

### `INTERNET_SCHEME_FILE`

File URL scheme (file:).

### `INTERNET_SCHEME_NEWS`

News URL scheme (news:).

### `INTERNET_SCHEME_MAILTO`

Mail URL scheme (mailto:).

### `INTERNET_SCHEME_SOCKS`

Socks URL scheme (socks:).

### `INTERNET_SCHEME_JAVASCRIPT`

JScript URL scheme (javascript:).

### `INTERNET_SCHEME_VBSCRIPT`

VBScript URL scheme (vbscript:).

### `INTERNET_SCHEME_RES`

Resource URL scheme (res:).

### `INTERNET_SCHEME_FIRST`

Lowest known scheme value.

### `INTERNET_SCHEME_LAST`

Highest known scheme value.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[URL_COMPONENTS](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-url_componentsa)