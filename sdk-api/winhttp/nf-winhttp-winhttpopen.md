# WinHttpOpen function

## Description

The **WinHttpOpen** function initializes, for an application, the use of WinHTTP functions and returns a WinHTTP-session handle.

## Parameters

### `pszAgentW` [in, optional]

A pointer to a string variable that contains the name of the application or entity calling the WinHTTP functions. This name is used as the [user agent](https://learn.microsoft.com/windows/desktop/WinHttp/glossary) in the HTTP protocol.

### `dwAccessType` [in]

Type of access required. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WINHTTP_ACCESS_TYPE_NO_PROXY** | Resolves all host names directly without a proxy. |
| **WINHTTP_ACCESS_TYPE_DEFAULT_PROXY** | **Important** Use of this option is deprecated on Windows 8.1 and newer. Use WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY instead.<br><br>Retrieves the static proxy or direct configuration from the registry. **WINHTTP_ACCESS_TYPE_DEFAULT_PROXY** does not inherit browser proxy settings.<br><br>The WinHTTP proxy configuration is set by one of these mechanisms.<br><br>* The [Netsh.exe commands](https://learn.microsoft.com/windows/win32/winhttp/netsh-exe-commands) on Windows Vista and Windows Server 2008 or later.<br>* The [proxycfg.exe](https://learn.microsoft.com/windows/desktop/WinHttp/proxycfg-exe--a-proxy-configuration-tool) utility on Windows XP and Windows Server 2003 or earlier.<br>* [WinHttpSetDefaultProxyConfiguration](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetdefaultproxyconfiguration) on all platforms. |
| **WINHTTP_ACCESS_TYPE_NAMED_PROXY** | Passes requests to the proxy unless a proxy bypass list is supplied and the name to be resolved bypasses the proxy. In this case, this function uses the values passed for *pwszProxyName* and *pwszProxyBypass*. |
| **WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY** | Uses system and per-user proxy settings (including the Internet Explorer proxy configuration) to determine which proxy/proxies to use. Automatically attempts to handle failover between multiple proxies, different proxy configurations per interface, and authentication. Supported in Windows 8.1 and newer. |

### `pszProxyW` [in]

A pointer to a string variable that contains the name of the proxy server to use when proxy access is specified by setting
*dwAccessType* to
**WINHTTP_ACCESS_TYPE_NAMED_PROXY**. The WinHTTP functions recognize only CERN type proxies for HTTP. If
*dwAccessType* is not set to
**WINHTTP_ACCESS_TYPE_NAMED_PROXY**, this parameter must be set to **WINHTTP_NO_PROXY_NAME**.

### `pszProxyBypassW` [in]

A pointer to a string variable that contains an optional semicolon delimited list of host names or IP addresses, or both, that should not be routed through the proxy when
*dwAccessType* is set to
**WINHTTP_ACCESS_TYPE_NAMED_PROXY**. The list can contain wildcard characters. Do not use an empty string, because the
**WinHttpOpen** function uses it as the proxy bypass list. If this parameter specifies the "<local>" macro in the list as the only entry, this function bypasses any host name that does not contain a period. If
*dwAccessType* is not set to
**WINHTTP_ACCESS_TYPE_NAMED_PROXY**, this parameter must be set to **WINHTTP_NO_PROXY_BYPASS**.

### `dwFlags` [in]

Unsigned long integer value that contains the flags that indicate various options affecting the behavior of this function. This parameter can have the following value.

| Value | Meaning |
| --- | --- |
| **WINHTTP_FLAG_ASYNC** | Use the WinHTTP functions asynchronously. By default, all WinHTTP functions that use the returned [HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle are performed synchronously. When this flag is set, the caller needs to specify a callback function through [WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback). |
| **WINHTTP_FLAG_SECURE_DEFAULTS** | When this flag is set, WinHttp will require use of TLS 1.2 or newer. If the caller attempts to enable older TLS versions by setting **WINHTTP_OPTION_SECURE_PROTOCOLS**, it will fail with **ERROR_ACCESS_DENIED**. Additionally, TLS fallback will be disabled. Note that setting this flag also sets flag **WINHTTP_FLAG_ASYNC**. |

## Return value

Returns a valid session handle if successful, or **NULL** otherwise. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

We strongly recommend that you use WinHTTP in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in **WinHttpOpen**, so that usage of the returned [HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) become asynchronous). The return value indicates success or failure. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The
**WinHttpOpen** function is the first of the WinHTTP functions called by an application. It initializes internal WinHTTP data structures and prepares for future calls from the application. When the application finishes using the WinHTTP functions, it must call
[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle) to free the session handle and any associated resources.

The application can make any number of calls to
**WinHttpOpen**, though a single call is normally sufficient. Each call to
**WinHttpOpen** opens a new session context. Because user data is not shared between multiple session contexts, an application that makes requests on behalf of multiple users should create a separate session for each user, so as not to share user-specific cookies and authentication state. The application should define separate behaviors for each
**WinHttpOpen** instance, such as different proxy servers configured for each.

After the calling application has finished using the
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle returned by
**WinHttpOpen**, it must be closed using the
[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle) function.

**Note** For Windows XP and Windows 2000, see [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

#### Examples

The following example code shows how to retrieve the default connection time-out value.

```cpp

    DWORD data;
    DWORD dwSize = sizeof(DWORD);

    // Use WinHttpOpen to obtain an HINTERNET handle.
    HINTERNET hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
                                    WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                    WINHTTP_NO_PROXY_NAME,
                                    WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession)
    {

        // Use WinHttpQueryOption to retrieve internet options.
        if (WinHttpQueryOption( hSession,
                                WINHTTP_OPTION_CONNECT_TIMEOUT,
                                &data, &dwSize))
        {
            printf("Connection timeout: %u ms\n\n",data);
        }
        else
        {
            printf( "Error %u in WinHttpQueryOption.\n",
                    GetLastError());
        }

        // When finished, release the HINTERNET handle.
        WinHttpCloseHandle(hSession);
    }
    else
    {
        printf("Error %u in WinHttpOpen.\n", GetLastError());
    }

```

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle)