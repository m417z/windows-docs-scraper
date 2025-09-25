## Description

> [!IMPORTANT]
> Use of **WinHttpSetDefaultProxyConfiguration** is deprecated on Windows 8.1 and newer. Most proxy configurations are not supported by **WinHttpSetDefaultProxyConfiguration**, nor does it support proxy authentication. Instead, use **WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY** with [WinHttpOpen](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpopen).

The **WinHttpSetDefaultProxyConfiguration** function sets the default WinHTTP proxy configuration in the registry.

## Parameters

### `pProxyInfo` [in]

A pointer to a variable of type
[WINHTTP_PROXY_INFO](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_proxy_info) that specifies the default proxy configuration.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

The default proxy configuration set by **WinHttpSetDefaultProxyConfiguration** can be overridden for an existing WinHTTP session by calling
[WinHttpSetOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetoption) and specifying the
[WINHTTP_OPTION_PROXY](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags) flag. The default proxy configuration can be overridden for a new session by specifying the configuration with the
[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen) function.

The *dwAccessType* member of
the [WINHTTP_PROXY_INFO](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_proxy_info) structure pointed to by *pProxyInfo* should be set to
**WINHTTP_ACCESS_TYPE_NAMED_PROXY** if a proxy is specified. Otherwise, it should be set to
**WINHTTP_ACCESS_TYPE_DEFAULT_PROXY**.

Any new sessions created after calling this function use the new default proxy configuration.

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHTTP start page.

## Examples

The following code example shows how to set the default proxy configuration in the registry.

```cpp
WINHTTP_PROXY_INFO proxyInfo;

// Allocate memory for string members.
proxyInfo.lpszProxy = new WCHAR[25];
proxyInfo.lpszProxyBypass = new WCHAR[25];

// Set the members of the proxy info structure.
proxyInfo.dwAccessType = WINHTTP_ACCESS_TYPE_NAMED_PROXY;
swprintf_s(proxyInfo.lpszProxy, 25, L"proxy_server");
swprintf_s(proxyInfo.lpszProxyBypass, 25, L"<local>");

// Set the default proxy configuration.
if (WinHttpSetDefaultProxyConfiguration( &proxyInfo ))
    printf("Proxy Configuration Set.\n");

// Free memory allocated to the strings.
delete [] proxyInfo.lpszProxy;
delete [] proxyInfo.lpszProxyBypass;
```

## See also

[WinHTTP versions](https://learn.microsoft.com/windows/desktop/winhttp/winhttp-versions)

[WinHttpGetDefaultProxyConfiguration](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetdefaultproxyconfiguration)