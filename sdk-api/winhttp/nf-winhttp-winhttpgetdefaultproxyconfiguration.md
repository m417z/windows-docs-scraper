# WinHttpGetDefaultProxyConfiguration function

## Description

The **WinHttpGetDefaultProxyConfiguration** function retrieves the default WinHTTP proxy configuration from the registry.

## Parameters

### `pProxyInfo` [in, out]

A pointer to a variable of type
[WINHTTP_PROXY_INFO](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_proxy_info) that receives the default proxy configuration.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise. To retrieve a specific error message, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Error codes returned include the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

**WinHttpGetDefaultProxyConfiguration** retrieves the proxy configuration set by
[WinHttpSetDefaultProxyConfiguration](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetdefaultproxyconfiguration) or
[ProxyCfg.exe](https://learn.microsoft.com/windows/desktop/WinHttp/proxycfg-exe--a-proxy-configuration-tool).

The default proxy configuration can be overridden for a WinHTTP session by calling
[WinHttpSetOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetoption) and specifying the
[WINHTTP_OPTION_PROXY](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags) flag.
**WinHttpGetDefaultProxyConfiguration** does not retrieve the configuration for the current session. It retrieves the configuration specified in the registry.

If the registry contains a list of proxy servers, the
**dwAccessType** member of
*pProxyInfo* is set to
**WINHTTP_ACCESS_TYPE_NAMED_PROXY**. Otherwise, it is set to
**WINHTTP_ACCESS_TYPE_NO_PROXY**.

**WinHttpGetDefaultProxyConfiguration** allocates memory for the string members of
*pProxyInfo*. To free this memory, call [GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree).

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHTTP Start Page.

#### Examples

The following code example shows how to retrieve the default proxy configuration from the registry.

```cpp
    WINHTTP_PROXY_INFO proxyInfo;

    // Retrieve the default proxy configuration.
    WinHttpGetDefaultProxyConfiguration( &proxyInfo );

    // Display the proxy servers and free memory
    // allocated to this string.
    if (proxyInfo.lpszProxy != NULL)
    {
        printf("Proxy server list: %S\n", proxyInfo.lpszProxy);
        GlobalFree( proxyInfo.lpszProxy );
    }

    // Display the bypass list and free memory
    // allocated to this string.
    if (proxyInfo.lpszProxyBypass != NULL)
    {
        printf("Proxy bypass list: %S\n", proxyInfo.lpszProxyBypass);
        GlobalFree( proxyInfo.lpszProxyBypass );
    }

```

## See also

[ProxyCfg.exe, a Proxy Configuration Tool](https://learn.microsoft.com/windows/desktop/WinHttp/proxycfg-exe--a-proxy-configuration-tool)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpSetDefaultProxyConfiguration](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetdefaultproxyconfiguration)