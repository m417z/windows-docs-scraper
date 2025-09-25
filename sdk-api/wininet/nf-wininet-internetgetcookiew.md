# InternetGetCookieW function

## Description

Retrieves the cookie for the specified URL.

## Parameters

### `lpszUrl` [in]

A pointer to a **null**-terminated string that specifies the URL for which cookies are to be retrieved.

### `lpszCookieName` [in]

Not implemented.

### `lpszCookieData` [out]

A pointer to a buffer that receives the cookie data. This parameter can be **NULL**.

### `lpdwSize` [in, out]

A pointer to a variable that specifies the size of the
*lpszCookieData* parameter buffer, in TCHARs. If the function succeeds, the buffer receives the amount of data copied to the
*lpszCookieData* buffer. If
*lpszCookieData* is **NULL**, this parameter receives a value that specifies the size of the buffer necessary to copy all the cookie data, expressed as a byte count.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error data, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error values apply to
**InternetGetCookie**.

| Return code | Description |
| --- | --- |
| **ERROR_NO_MORE_ITEMS** | There is no cookie for the specified URL and all its parents. |
| **ERROR_INSUFFICIENT_BUFFER** | The value passed in *lpdwSize* is insufficient to copy all the cookie data. The value returned in *lpdwSize* is the size of the buffer necessary to get all the data. |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is invalid.<br><br>The *lpszUrl* parameter is **NULL**. |

## Remarks

**InternetGetCookie** does not require a call to
[InternetOpen](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopena).
**InternetGetCookie** checks in the windows\cookies directory for persistent cookies that have an expiration date set sometime in the future.
**InternetGetCookie** also searches memory for any session cookies, that is, cookies that do not have an expiration date that were created in the same process by
[InternetSetCookie](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetcookiea), because these cookies are not written to any files. Rules for creating cookie files are internal to the system and can change in the future.

As noted in [HTTP Cookies](https://learn.microsoft.com/windows/desktop/WinInet/http-cookies), **InternetGetCookie** does not return cookies that the server marked as non-scriptable with the "HttpOnly" attribute in the Set-Cookie header.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetGetCookie as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HTTP Cookies](https://learn.microsoft.com/windows/desktop/WinInet/http-cookies)

[InternetGetCookieEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetcookieexa)

[InternetSetCookie](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetcookiea)

[InternetSetCookieEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetcookieexa)

[Managing Cookies](https://learn.microsoft.com/windows/desktop/WinInet/managing-cookies)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)