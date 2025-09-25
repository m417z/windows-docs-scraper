## Description

Creates a cookie associated with the specified URL.

## Parameters

### `pcwszUrl`

The URL for which to set the cookie.

### `pCookie`

Pointer to an [INTERNET\_COOKIE2](https://learn.microsoft.com/windows/win32/api/wininet/ns-wininet-internet_cookie2) structure containing the cookie data.

### `pcwszP3PPolicy`

String containing the Platform-for-Privacy-Protection (P3P) policy for the cookie. May be NULL.

### `dwFlags`

Flags for the cookie to be set. The following flags are available.

| Value | Meaning |
|-------|---------|
| INTERNET_COOKIE_THIRD_PARTY | Set this cookie in a third-party context. |
| INTERNET_COOKIE_PROMPT_REQUIRED | Show a UI prompt for the user to accept or reject this cookie. |
| INTERNET_COOKIE_EVALUATE_P3P | Evaluate the provided P3P policy for this cookie. This will evaluate default policy when *pcwszP3PPolicy* is NULL. |
| INTERNET_COOKIE_NON_SCRIPT | Indicate that this cookie is not being set via JavaScript, allowing HTTP-only cookies to be set. |
| INTERNET_COOKIE_APPLY_HOST_ONLY | Apply host-only policy to this cookie. If the domain attribute is not set, then this cookie will be marked host-only. |

### `pdwCookieState`

Pointer to a DWORD that receives the result of setting the cookie. For a list of possible values, see [InternetCookieState](https://learn.microsoft.com/windows/win32/api/wininet/ne-wininet-internetcookiestate).

## Return value

Returns ERROR_SUCCESS if successful, or a [system error code](https://learn.microsoft.com/windows/desktop/debug/system-error-codes) on failure.

## Remarks

> [!NOTE]
> WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/winhttp/winhttp-start-page).

## See also

[HTTP Cookies](https://learn.microsoft.com/windows/win32/wininet/http-cookies)

[Managing Cookies](https://learn.microsoft.com/windows/win32/wininet/managing-cookies)

[InternetGetCookieEx2](https://learn.microsoft.com/windows/win32/api/wininet/nf-wininet-internetgetcookieex2)

[InternetFreeCookies](https://learn.microsoft.com/windows/win32/api/wininet/nf-wininet-internetfreecookies)

[WinINet Functions](https://learn.microsoft.com/windows/win32/wininet/wininet-functions)