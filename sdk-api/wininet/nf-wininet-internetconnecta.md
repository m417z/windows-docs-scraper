# InternetConnectA function

## Description

Opens an File Transfer Protocol (FTP) or HTTP session for a given site.

## Parameters

### `hInternet` [in]

Handle returned by a previous call to
[InternetOpen](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopena).

### `lpszServerName` [in]

Pointer to a **null**-terminated string that specifies the host name of an Internet server. Alternately, the string can contain the IP number of the site, in ASCII dotted-decimal format (for example, 11.0.1.45).

### `nServerPort` [in]

Transmission Control Protocol/Internet Protocol (TCP/IP) port on the server. These flags set only the port that is used. The service is set by the value of
*dwService*. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| INTERNET_DEFAULT_FTP_PORT | Uses the default port for FTP servers (port 21). |
| INTERNET_DEFAULT_GOPHER_PORT | Uses the default port for Gopher servers (port 70).<br><br>**Note** Windows XP and Windows Server 2003 R2 and earlier only. |
| INTERNET_DEFAULT_HTTP_PORT | Uses the default port for HTTP servers (port 80). |
| INTERNET_DEFAULT_HTTPS_PORT | Uses the default port for Secure Hypertext Transfer Protocol (HTTPS) servers (port 443). |
| INTERNET_DEFAULT_SOCKS_PORT | Uses the default port for SOCKS firewall servers (port 1080). |
| INTERNET_INVALID_PORT_NUMBER | Uses the default port for the service specified by *dwService*. |

### `lpszUserName` [in]

Pointer to a **null**-terminated string that specifies the name of the user to log on. If this parameter is **NULL**, the function uses an appropriate default. For the FTP protocol, the default is "anonymous".

### `lpszPassword` [in]

Pointer to a **null**-terminated string that contains the password to use to log on. If both
*lpszPassword* and
*lpszUsername* are **NULL**, the function uses the default "anonymous" password. In the case of FTP, the default password is the user's email name. If
*lpszPassword* is **NULL**, but
*lpszUsername* is not **NULL**, the function uses a blank password.

### `dwService` [in]

Type of service to access. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| INTERNET_SERVICE_FTP | FTP service. |
| INTERNET_SERVICE_GOPHER | Gopher service.<br><br>**Note** Windows XP and Windows Server 2003 R2 and earlier only. |
| INTERNET_SERVICE_HTTP | HTTP service. |

### `dwFlags` [in]

Options specific to the service used. If
*dwService* is INTERNET_SERVICE_FTP,
[INTERNET_FLAG_PASSIVE](https://learn.microsoft.com/windows/desktop/WinInet/api-flags) causes the application to use passive FTP semantics.

### `dwContext` [in]

Pointer to a variable that contains an application-defined value that is used to identify the application context for the returned handle in callbacks.

## Return value

Returns a valid handle to the session if the connection is successful, or **NULL** otherwise. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). An application can also use
[InternetGetLastResponseInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetlastresponseinfoa) to determine why access to the service was denied.

## Remarks

The following table describes the behavior for the four possible settings of
*lpszUsername* and
*lpszPassword*.

| *lpszUsername* | *lpszPassword* | User name sent to FTP server | Password sent to FTP server |
| --- | --- | --- | --- |
| **NULL** | **NULL** | "anonymous" | User's email name |
| Non-**NULL** string | **NULL** | *lpszUsername* | "" |
| **NULL** | Non-**NULL** string | ERROR | ERROR |
| Non-**NULL** string | Non-**NULL** string | *lpszUsername* | *lpszPassword* |

For FTP sites,
**InternetConnect** actually establishes a connection with the server; for others, the actual connection is not established until the application requests a specific transaction.

For maximum efficiency, applications using the HTTP protocols should try to minimize calls to
**InternetConnect** and avoid calling this function for every transaction requested by the user. One way to accomplish this is to keep a small cache of handles returned from
**InternetConnect**; when the user makes a request to a previously accessed server, that session handle is still available.

After the calling application has finished using the
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinInet/appendix-a-hinternet-handles) handle returned by
**InternetConnect**, it must be closed using the
[InternetCloseHandle](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclosehandle) function.

**Note** When a request is sent asynchronous mode (the *dwFlags* parameter of [InternetOpen](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopena) specifies **INTERNET_FLAG_ASYNC**), and the *dwContext* parameter is zero (**INTERNET_NO_CALLBACK**), the callback function set with [InternetSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetstatuscallback) on the connection handle will not be called, however, the call will still be performed in asynchronous mode.

Examples of **InternetConnect** usage can be found in the following topics.

* [Handling Authentication](https://learn.microsoft.com/windows/desktop/WinInet/handling-authentication)
* [Asynchronous Example Application](https://learn.microsoft.com/windows/desktop/WinInet/asynchronous-example-application)

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetConnect as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Enabling Internet Functionality](https://learn.microsoft.com/windows/desktop/WinInet/enabling-internet-functionality)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)