## Description

The **INTERNET\_COOKIE2** contains the constituent parts of a cookie. This structure is used with the [InternetGetCookieEx2](https://learn.microsoft.com/windows/win32/api/wininet/nf-wininet-internetgetcookieex2) and [InternetSetCookieEx2](https://learn.microsoft.com/windows/win32/api/wininet/nf-wininet-internetsetcookieex2) functions.

## Members

### `pwszName`

Pointer to a string containing the cookie name. May be NULL if value is not NULL.

### `pwszValue`

Pointer to a string containing the cookie value. May be NULL if name is not NULL.

### `pwszDomain`

Pointer to a string containing the cookie domain. May be NULL.

### `pwszPath`

Pointer to a string containing the cookie path. May be NULL.

### `dwFlags`

Flags for additional cookie details. The following flags are available.

| Value | Meaning |
|-------|---------|
| INTERNET_COOKIE_IS_SECURE | This is a secure cookie. |
| INTERNET_COOKIE_IS_SESSION | This is a session cookie. |
| INTERNET_COOKIE_IS_RESTRICTED | This cookie is restricted to first-party contexts. |
| INTERNET_COOKIE_HTTPONLY | This is an HTTP-only cookie. |
| INTERNET_COOKIE_HOST_ONLY | This is a host-only cookie. |
| INTERNET_COOKIE_HOST_ONLY_APPLIED | The host-only setting has been applied to this cookie. |
| INTERNET_COOKIE_SAME_SITE_STRICT | The SameSite security level for this cookie is "strict". |
| INTERNET_COOKIE_SAME_SITE_LAX | The SameSite security level for this cookie is "lax". |

### `ftExpires`

The expiry time of the cookie.

### `fExpiresSet`

Whether or not the expiry time is set.

## Remarks

> [!NOTE]
> WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/winhttp/winhttp-start-page).

## See also

[InternetGetCookieEx2](https://learn.microsoft.com/windows/win32/api/wininet/nf-wininet-internetgetcookieex2)

[InternetSetCookieEx2](https://learn.microsoft.com/windows/win32/api/wininet/nf-wininet-internetsetcookieex2)

[InternetFreeCookies](https://learn.microsoft.com/windows/win32/api/wininet/nf-wininet-internetfreecookies)