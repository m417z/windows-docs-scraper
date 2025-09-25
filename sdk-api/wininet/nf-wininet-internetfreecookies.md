## Description

Frees an array of [INTERNET\_COOKIE2](https://learn.microsoft.com/windows/win32/api/wininet/ns-wininet-internet_cookie2) structures returned by [InternetGetCookieEx2](https://learn.microsoft.com/windows/win32/api/wininet/nf-wininet-internetgetcookieex2).

## Parameters

### `pCookies`

Pointer to an array of [**INTERNET\_COOKIE2**](https://learn.microsoft.com/windows/win32/api/wininet/ns-wininet-internet_cookie2) structures.

### `dwCookieCount`

The number of structures in the array.

## Remarks

> [!NOTE]
> WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/winhttp/winhttp-start-page).

## See also

[HTTP Cookies](https://learn.microsoft.com/windows/win32/wininet/http-cookies)

[Managing Cookies](https://learn.microsoft.com/windows/win32/wininet/managing-cookies)

[InternetGetCookieEx2](https://learn.microsoft.com/windows/win32/api/wininet/nf-wininet-internetgetcookieex2)

[InternetSetCookieEx2](https://learn.microsoft.com/windows/win32/api/wininet/nf-wininet-internetsetcookieex2)

[WinINet Functions](https://learn.microsoft.com/windows/win32/wininet/wininet-functions)