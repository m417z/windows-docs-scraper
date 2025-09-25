# InternetOpenA function

## Description

Initializes an application's use of the WinINet functions.

## Parameters

### `lpszAgent` [in]

Pointer to a **null**-terminated string that specifies the name of the application or entity calling the WinINet functions. This name is used as the user agent in the HTTP protocol.

### `dwAccessType` [in]

Type of access required. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| INTERNET_OPEN_TYPE_DIRECT | Resolves all host names locally. |
| INTERNET_OPEN_TYPE_PRECONFIG | Retrieves the proxy or direct configuration from the registry. |
| INTERNET_OPEN_TYPE_PRECONFIG_WITH_NO_AUTOPROXY | Retrieves the proxy or direct configuration from the registry and prevents the use of a startup Microsoft JScript or Internet Setup (INS) file. |
| INTERNET_OPEN_TYPE_PROXY | Passes requests to the proxy unless a proxy bypass list is supplied and the name to be resolved bypasses the proxy. In this case, the function uses **INTERNET_OPEN_TYPE_DIRECT**. |

### `lpszProxy` [in]

Pointer to a **null**-terminated string that specifies the name of the proxy server(s) to use when proxy access is specified by setting
*dwAccessType* to
**INTERNET_OPEN_TYPE_PROXY**. Do not use an empty string, because
**InternetOpen** will use it as the proxy name. The WinINet functions recognize only CERN type proxies (HTTP only) and the TIS FTP gateway (FTP only). If Microsoft Internet Explorer is installed, these functions also support SOCKS proxies. FTP requests can be made through a CERN type proxy either by changing them to an HTTP request or by using
[InternetOpenUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopenurla). If
*dwAccessType* is not set to
**INTERNET_OPEN_TYPE_PROXY**, this parameter is ignored and should be **NULL**. For more information about listing proxy servers, see the
[Listing Proxy Servers](https://learn.microsoft.com/windows/desktop/WinInet/enabling-internet-functionality) section of
[Enabling Internet Functionality](https://learn.microsoft.com/windows/desktop/WinInet/enabling-internet-functionality).

### `lpszProxyBypass` [in]

Pointer to a **null**-terminated string that specifies an optional list of host names or IP addresses, or both, that should not be routed through the proxy when
*dwAccessType* is set to
**INTERNET_OPEN_TYPE_PROXY**. The list can contain wildcards. Do not use an empty string, because
**InternetOpen** will use it as the proxy bypass list. If this parameter specifies the "<local>" macro, the function bypasses the proxy for any host name that does not contain a period.

By default, WinINet will bypass the proxy for requests that use the host names "localhost", "loopback", "127.0.0.1", or "[::1]". This behavior exists because a remote proxy server typically will not resolve these addresses properly.**Internet Explorer 9:** You can remove the local computer from the proxy bypass list using the "<-loopback>" macro.

If
*dwAccessType* is not set to
**INTERNET_OPEN_TYPE_PROXY**, this parameter is ignored and should be **NULL**.

### `dwFlags` [in]

Options. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| INTERNET_FLAG_ASYNC | Makes only asynchronous requests on handles descended from the handle returned from this function. |
| INTERNET_FLAG_FROM_CACHE | Does not make network requests. All entities are returned from the cache. If the requested item is not in the cache, a suitable error, such as ERROR_FILE_NOT_FOUND, is returned. |
| INTERNET_FLAG_OFFLINE | Identical to **INTERNET_FLAG_FROM_CACHE**. Does not make network requests. All entities are returned from the cache. If the requested item is not in the cache, a suitable error, such as ERROR_FILE_NOT_FOUND, is returned. |

## Return value

Returns a valid handle that the application passes to subsequent WinINet functions. If
**InternetOpen** fails, it returns **NULL**. To retrieve a specific error message, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**InternetOpen** is the first WinINet function called by an application. It tells the Internet DLL to initialize internal data structures and prepare for future calls from the application. When the application finishes using the Internet functions, it should call
[InternetCloseHandle](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclosehandle) to free the handle and any associated resources.

The application can make any number of calls to
**InternetOpen**, though a single call is normally sufficient. The application might need to define separate behaviors for each
**InternetOpen** instance, such as different proxy servers configured for each.

After the calling application has finished using the
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinInet/appendix-a-hinternet-handles) handle returned by
**InternetOpen**, it must be closed using the
[InternetCloseHandle](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclosehandle) function.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetOpen as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Enabling Internet Functionality](https://learn.microsoft.com/windows/desktop/WinInet/enabling-internet-functionality)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)