# InternetSetCookieA function

## Description

Creates a cookie associated with the specified URL.

## Parameters

### `lpszUrl` [in]

Pointer to a **null**-terminated string that specifies the URL for which the cookie should be set.

### `lpszCookieName` [in]

Pointer to a **null**-terminated string that specifies the name to be associated with the cookie data. If this parameter is **NULL**, no name is associated with the cookie.

### `lpszCookieData` [in]

Pointer to the actual data to be associated with the URL.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get a specific error message, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Cookies created by
**InternetSetCookie** without an expiration date are stored in memory and are available only in the same process that created them. Cookies that include an expiration date are stored in the windows\cookies directory.

Creating a new cookie might cause a dialog box to appear on the screen asking the user if they want to allow or disallow cookies from this site based on the privacy settings for the user.

**Caution** **InternetSetCookie** will unconditionally create a cookie even if “Block all cookies” is set in Internet Explorer. This behavior can be viewed as a breach of privacy even though such cookies are not subsequently sent back to servers while the “Block all cookies” setting is active. Applications should use [InternetSetCookieEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetcookieexa) to correctly honor the user's privacy settings.

For more cookie internals, see [http://blogs.msdn.com/ieinternals/archive/2009/08/20/WinINET-IE-Cookie-Internals-FAQ.aspx](https://learn.microsoft.com/archive/blogs/ieinternals/).

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetSetCookie as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HTTP Cookies](https://learn.microsoft.com/windows/desktop/WinInet/http-cookies)

[InternetGetCookie](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetcookiea)

[InternetGetCookieEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetcookieexa)

[InternetSetCookieEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetcookieexa)

[Managing Cookies](https://learn.microsoft.com/windows/desktop/WinInet/managing-cookies)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)