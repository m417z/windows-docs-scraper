# InternetSetCookieExA function

## Description

The **InternetSetCookieEx** function
creates a cookie with a specified name that is associated with a specified URL. This function differs from
the [InternetSetCookie](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetcookiea) function by being able
to create third-party cookies.

## Parameters

### `lpszUrl` [in]

Pointer to a **null**-terminated string that contains the URL for which the cookie should be set.

If this pointer is **NULL**, **InternetSetCookieEx** fails with an **ERROR_INVALID_PARAMETER** error.

### `lpszCookieName` [in]

Pointer to a **null**-terminated string that contains the name to associate with this cookie.
If this pointer is **NULL**, then no name is associated with the cookie.

### `lpszCookieData` [in]

Pointer to a **null**-terminated string that contains the data to be associated with the new cookie.

If this pointer is **NULL**, **InternetSetCookieEx** fails with an **ERROR_INVALID_PARAMETER** error.

### `dwFlags` [in]

Flags that control how the function retrieves cookie data:

| Value | Meaning |
| --- | --- |
| **INTERNET_COOKIE_EVALUATE_P3P** | If this flag is set and the *dwReserved* parameter is not **NULL**, then the *dwReserved* parameter is cast to an **LPCTSTR** that points to a Platform-for-Privacy-Protection (P3P) header for the cookie in question. |
| **INTERNET_COOKIE_HTTPONLY** | Enables the retrieval of cookies that are marked as "HTTPOnly". <br><br>Do not use this flag if you expose a scriptable interface, because this has security implications. If you expose a scriptable interface, you can become an attack vector for cross-site scripting attacks. It is utterly imperative that you use this flag only if they can guarantee that you will never permit third-party code to set a cookie using this flag by way of an extensibility mechanism you provide.<br><br> <br><br>**Version:** Requires Internet Explorer 8.0 or later. |
| **INTERNET_COOKIE_THIRD_PARTY** | Indicates that the cookie being set is a third-party cookie. |
| **INTERNET_FLAG_RESTRICTED_ZONE** | Indicates that the cookie being set is associated with an untrusted site. |

### `dwReserved` [in]

**NULL**, or contains a pointer to a Platform-for-Privacy-Protection (P3P) header to be associated with the cookie.

## Return value

Returns a member of the [InternetCookieState](https://learn.microsoft.com/windows/win32/api/wininet/ne-wininet-internet_scheme) enumeration if successful, or **FALSE** if the function fails. On failure, if a call to
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_NOT_ENOUGH_MEMORY, insufficient system memory was available.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetSetCookieEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HTTP Cookies](https://learn.microsoft.com/windows/desktop/WinInet/http-cookies)

[InternetGetCookie](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetcookiea)

[InternetGetCookieEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetcookieexa)

[InternetSetCookie](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetcookiea)

[Managing Cookies](https://learn.microsoft.com/windows/desktop/WinInet/managing-cookies)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)