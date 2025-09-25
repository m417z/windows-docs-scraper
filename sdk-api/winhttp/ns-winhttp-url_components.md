## Description

The **URL_COMPONENTS** structure contains the constituent parts of a URL. This structure is used with the
[WinHttpCrackUrl](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpcrackurl) and
[WinHttpCreateUrl](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpcreateurl) functions.

## Members

### `dwStructSize`

Size of this structure, in bytes. Used for version checking. The size of this structure must be set to initialize this structure properly.

### `lpszScheme`

Pointer to a string value that contains the scheme name.

### `dwSchemeLength`

Length of the scheme name, in characters.

### `nScheme`

Internet protocol scheme. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INTERNET_SCHEME_HTTP**<br><br>1 | The Internet scheme is the HTTP protocol. See [RFC 2616](https://www.ietf.org/rfc/rfc2616.txt) for more information. |
| **INTERNET_SCHEME_HTTPS**<br><br>2 | The Internet scheme, HTTPS, is an HTTP protocol that uses secure transaction semantics. |

### `lpszHostName`

Pointer to a string value that contains the host name.

### `dwHostNameLength`

Length of the host name, in characters.

### `nPort`

Port number.

### `lpszUserName`

Pointer to a string that contains the user name.

### `dwUserNameLength`

Length of the user name, in characters.

### `lpszPassword`

Pointer to a string that contains the password.

### `dwPasswordLength`

Length of the password, in characters.

### `lpszUrlPath`

Pointer to a string that contains the URL path.

### `dwUrlPathLength`

Length of the URL path, in characters.

### `lpszExtraInfo`

Pointer to a string value that contains the extra information, for example, ?something or #something.

### `dwExtraInfoLength`

Unsigned long integer value that contains the length of the extra information, in characters.

## Remarks

For the
[WinHttpCrackUrl](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpcrackurl) function, if a pointer member and its corresponding length member are both zero, that component of the URL is not returned. If the pointer member is **NULL** but the length member is not zero, both the pointer and length members are returned. If both pointer and corresponding length members are nonzero, the pointer member points to a buffer where the component is copied. All escape sequences can be removed from a component, depending on the
*dwFlags* parameter of
[WinHttpCrackUrl](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpcrackurl).

For the
[WinHttpCreateUrl](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpcreateurl) function, the pointer members should be **NULL** if the component of the URL is not required. If the corresponding length member is zero, the pointer member is the pointer to a zero-terminated string. If the length member is not zero, it is the string length of the corresponding pointer member.

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

## See also

[WinHTTP
Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)