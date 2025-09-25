# InternetGetCookieExA function

## Description

The **InternetGetCookieEx** function retrieves data stored in cookies associated with a specified URL. Unlike [InternetGetCookie](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetcookiea), **InternetGetCookieEx** can be used to restrict data retrieved to a single cookie name or, by policy, associated with untrusted sites or third-party cookies.

## Parameters

### `lpszUrl` [in]

A pointer to a **null**-terminated string that contains the URL with which the cookie to retrieve is associated. This parameter cannot be **NULL** or **InternetGetCookieEx** fails and returns an **ERROR_INVALID_PARAMETER** error.

### `lpszCookieName` [in]

A pointer to a **null**-terminated string that contains the name of the cookie to retrieve. This name is case-sensitive.

### `lpszCookieData` [in, out, optional]

A pointer to a buffer to receive the cookie data.

### `lpdwSize` [in, out]

A pointer to a DWORD variable.

On entry, the variable must contain the size, in TCHARs, of the buffer pointed to by the *pchCookieData* parameter.

On exit, if the function is successful, this variable contains the number of TCHARs of cookie data copied into the buffer. If **NULL** was passed as the *lpszCookieData* parameter, or if the function fails with an error of **ERROR_INSUFFICIENT_BUFFER**, the variable contains the size, in BYTEs, of buffer required to receive the cookie data.

This parameter cannot be **NULL** or **InternetGetCookieEx** fails and returns an **ERROR_INVALID_PARAMETER** error.

### `dwFlags` [in]

A flag that controls how the function retrieves cookie data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INTERNET_COOKIE_HTTPONLY** | Enables the retrieval of cookies that are marked as "HTTPOnly". <br><br>Do not use this flag if you expose a scriptable interface, because this has security implications. It is imperative that you use this flag only if you can guarantee that you will never expose the cookie to third-party code by way of an extensibility mechanism you provide.<br><br>**Version:** Requires Internet Explorer 8.0 or later. |
| **INTERNET_COOKIE_THIRD_PARTY** | Retrieves only third-party cookies if policy explicitly allows all cookies for the specified URL to be retrieved. |
| **INTERNET_FLAG_RESTRICTED_ZONE** | Retrieves only cookies that would be allowed if the specified URL were untrusted; that is, if it belonged to the URLZONE_UNTRUSTED zone. |

### `lpReserved` [in]

Reserved for future use. Set to **NULL**.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. To get a specific error value, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If **NULL** is passed to *lpszCookieData*, the call will succeed and the function will not set **ERROR_INSUFFICIENT_BUFFER**.

The following error codes may be set by this function.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | Returned if cookie data retrieved is larger than the buffer size pointed to by the *pcchCookieData* parameter or if that parameter is **NULL**. |
| **ERROR_INVALID_PARAMETER** | Returned if either the *pchURL* or the *pcchCookieData* parameter is **NULL**. |
| **ERROR_NO_MORE_ITEMS** | Returned if no cookied data as specified could be retrieved. |

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetGetCookieEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HTTP Cookies](https://learn.microsoft.com/windows/desktop/WinInet/http-cookies)

[InternetGetCookie](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetcookiea)

[InternetSetCookie](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetcookiea)

[InternetSetCookieEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetcookieexa)

[Managing Cookies](https://learn.microsoft.com/windows/desktop/WinInet/managing-cookies)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)