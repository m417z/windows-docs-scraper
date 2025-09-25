# HttpOpenRequestA function

## Description

Creates an HTTP request handle.

## Parameters

### `hConnect` [in]

A handle to an HTTP session returned by
[InternetConnect](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetconnecta).

### `lpszVerb` [in]

A pointer to a **null**-terminated string that contains the HTTP verb to use in the request. If this parameter is **NULL**, the function uses GET as the HTTP verb.

### `lpszObjectName` [in]

A pointer to a **null**-terminated string that contains the name of the target object of the specified HTTP verb. This is generally a file name, an executable module, or a search specifier.

### `lpszVersion` [in]

A pointer to a **null**-terminated string that contains the HTTP version to use in the request. Settings in Internet Explorer will override the value specified in this parameter.

If this parameter is **NULL**, the function uses an HTTP version of 1.1 or 1.0, depending on the value of the Internet Explorer settings.

| Value | Meaning |
| --- | --- |
| **HTTP/1.0** | HTTP version 1.0 |
| **HTTP/1.1** | HTTP version 1.1 |

### `lpszReferrer` [in]

A pointer to a **null**-terminated string that specifies the URL of the document from which the URL in the request (*lpszObjectName*) was obtained. If this parameter is **NULL**, no referrer is specified.

### `lplpszAcceptTypes` [in]

A pointer to a **null**-terminated array of strings that indicates media types accepted by the client. Here is an example.

`PCTSTR rgpszAcceptTypes[] = {_T("text/*"), NULL};`

 Failing to properly terminate the array with a NULL pointer will cause a crash.

If this parameter is **NULL**, no types are accepted by the client. Servers generally interpret a lack of accept types to indicate that the client accepts only documents of type "text/*" (that is, only text documents—no pictures or other binary files).

### `dwFlags` [in]

Internet options. This parameter can be any of the following values.

| Value | Meaning |
| --- | --- |
| INTERNET_FLAG_CACHE_IF_NET_FAIL | Returns the resource from the cache if the network request for the resource fails due to an ERROR_INTERNET_CONNECTION_RESET (the connection with the server has been reset) or ERROR_INTERNET_CANNOT_CONNECT (the attempt to connect to the server failed). |
| INTERNET_FLAG_HYPERLINK | Forces a reload if there was no Expires time and no LastModified time returned from the server when determining whether to reload the item from the network. |
| INTERNET_FLAG_IGNORE_CERT_CN_INVALID | Disables checking of SSL/PCT-based certificates that are returned from the server against the host name given in the request. WinINet functions use a simple check against certificates by comparing for matching host names and simple wildcarding rules. |
| INTERNET_FLAG_IGNORE_CERT_DATE_INVALID | Disables checking of SSL/PCT-based certificates for proper validity dates. |
| INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP | Disables detection of this special type of redirect. When this flag is used, WinINet functions transparently allow redirects from HTTPS to HTTP URLs. |
| INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS | Disables detection of this special type of redirect. When this flag is used, WinINet functions transparently allow redirects from HTTP to HTTPS URLs. |
| INTERNET_FLAG_KEEP_CONNECTION | Uses keep-alive semantics, if available, for the connection. This flag is required for Microsoft Network (MSN), NT LAN Manager (NTLM), and other types of authentication. |
| INTERNET_FLAG_NEED_FILE | Causes a temporary file to be created if the file cannot be cached. |
| INTERNET_FLAG_NO_AUTH | Does not attempt authentication automatically. |
| INTERNET_FLAG_NO_AUTO_REDIRECT | Does not automatically handle redirection in [HttpSendRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequesta). |
| INTERNET_FLAG_NO_CACHE_WRITE | Does not add the returned entity to the cache. |
| INTERNET_FLAG_NO_COOKIES | Does not automatically add cookie headers to requests, and does not automatically add returned cookies to the cookie database. |
| INTERNET_FLAG_NO_UI | Disables the cookie dialog box. |
| INTERNET_FLAG_PRAGMA_NOCACHE | Forces the request to be resolved by the origin server, even if a cached copy exists on the proxy. |
| INTERNET_FLAG_RELOAD | Forces a download of the requested file, object, or directory listing from the origin server, not from the cache. |
| INTERNET_FLAG_RESYNCHRONIZE | Reloads HTTP resources if the resource has been modified since the last time it was downloaded. All FTP resources are reloaded.<br><br>**Windows XP and Windows Server 2003 R2 and earlier:** Gopher resources are also reloaded. |
| INTERNET_FLAG_SECURE | Uses secure transaction semantics. This translates to using Secure Sockets Layer/Private Communications Technology (SSL/PCT) and is only meaningful in HTTP requests. |

### `dwContext` [in]

 A pointer to a variable that contains the application-defined value that associates this operation with any application data.

## Return value

Returns an HTTP request handle if successful, or **NULL** otherwise. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **HttpOpenRequest** function creates a new HTTP request handle and stores the specified parameters in that handle. An HTTP request handle holds a request to be sent to an HTTP server and contains all RFC822/MIME/HTTP headers to be sent as part of the request.

If a verb other than "GET" or "POST" is specified, **HttpOpenRequest** automatically sets INTERNET_FLAG_NO_CACHE_WRITE and INTERNET_FLAG_RELOAD for the request.

With Microsoft Internet Explorer 5 and later, if
*lpszVerb* is set to "HEAD", the Content-Length header is ignored on responses from HTTP/1.1 servers.

On Windows 7, Windows Server 2008 R2, and later, the *lpszVersion* parameter is overridden by Internet Explorer settings. The **EnableHttp1_1** is a registry value under **HKLM\Software\Microsoft\InternetExplorer\AdvacnedOptions\HTTP\GENABLE** controlled by Internet Options set in Internet Explorer for the system. The **EnableHttp1_1** value defaults to 1. The **HttpOpenRequest** function upgrades any HTTP version less than 1.1 to HTTP version 1.1 if **EnableHttp1_1** is set to 1.

After the calling application has finished using the
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinInet/appendix-a-hinternet-handles) handle returned by
**HttpOpenRequest**, it must be closed using the
[InternetCloseHandle](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclosehandle) function.

**Note** When a request is sent in asynchronous mode (the *dwFlags* parameter of [InternetOpen](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopena) specifies **INTERNET_FLAG_ASYNC**), and the *dwContext* parameter is zero (**INTERNET_NO_CALLBACK**), the callback function set with [InternetSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetstatuscallback) on the request handle will not be invoked, however, the call will still be performed in asynchronous mode.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines HttpOpenRequest as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HTTP Sessions](https://learn.microsoft.com/windows/desktop/WinInet/http-sessions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)