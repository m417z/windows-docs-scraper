## Description

Retrieves one or more cookies associated with the specified URL.

## Parameters

### `pcwszUrl`

The URL for which to retrieve cookies.

### `pcwszCookieName`

The name of the cookie to retrieve. May be NULL.

### `dwFlags`

Flags of the cookie to retrieve. The following flags are available.

| Value | Meaning |
|-------|---------|
| INTERNET_COOKIE_THIRD_PARTY | Retrieve cookies as a third party, causing first-party-only cookies to be excluded. |
| INTERNET_COOKIE_NON_SCRIPT | Indicate that this query was not triggered via JavaScript, allowing retrieval of HTTP-only cookies. |
| INTERNET_COOKIE_SAME_SITE_LEVEL_CROSS_SITE | Retrieve cookies as if in a cross site context, excluding cookies with the SameSite property set. |
| INTERNET_FLAG_RESTRICTED_ZONE | Retrieve only cookies that would be allowed if the specified URL were untrusted; that is, if it belonged to the URLZONE_UNTRUSTED zone. |

### `ppCookies`

Pointer that receives an array of [INTERNET\_COOKIE2](https://learn.microsoft.com/windows/win32/api/wininet/ns-wininet-internet_cookie2) structures. The returned array must be freed by [InternetFreeCookies](https://learn.microsoft.com/windows/win32/api/wininet/nf-wininet-internetfreecookies).

### `pdwCookieCount`

Pointer to a DWORD that receives the number of structures in the array.

## Return value

Returns ERROR_SUCCESS if successful, or a [system error code](https://learn.microsoft.com/windows/desktop/debug/system-error-codes) on failure.

## Remarks

> [!NOTE]
> WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/winhttp/winhttp-start-page).

## See also

[HTTP Cookies](https://learn.microsoft.com/windows/win32/wininet/http-cookies)

[Managing Cookies](https://learn.microsoft.com/windows/win32/wininet/managing-cookies)

[InternetSetCookieEx2](https://learn.microsoft.com/windows/win32/api/wininet/nf-wininet-internetsetcookieex2)

[InternetFreeCookies](https://learn.microsoft.com/windows/win32/api/wininet/nf-wininet-internetfreecookies)

[WinINet Functions](https://learn.microsoft.com/windows/win32/wininet/wininet-functions)