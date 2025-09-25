# WinHttpGetIEProxyConfigForCurrentUser function

## Description

The **WinHttpGetIEProxyConfigForCurrentUser** function retrieves the Internet Explorer proxy configuration for the current user.

## Parameters

### `pProxyConfig` [in, out]

A pointer, on input, to a [WINHTTP_CURRENT_USER_IE_PROXY_CONFIG](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_current_user_ie_proxy_config) structure. On output, the structure contains the Internet Explorer proxy settings for the current active network connection (for example, LAN, dial-up, or VPN connection).

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | No Internet Explorer proxy settings can be found. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

In Internet Explorer, the proxy settings are found on the **Connections** tab of the **Tools** / **Internet Options** menu option. Proxy settings are configured on a per-connection basis; that is, the proxy settings for a LAN connection are separate from those for a dial-up or VPN connection. **WinHttpGetIEProxyConfigForCurrentUser** returns the proxy settings for the current active connection.

This function is useful in client applications running in network environments in which the Web Proxy Auto-Discovery (WPAD) protocol is not implemented (meaning that no Proxy Auto-Configuration file is available). If a PAC file is not available, then the [WinHttpGetProxyForUrl](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurl) function fails. The **WinHttpGetIEProxyConfigForCurrentUser** function can be used as a fall-back mechanism to discover a workable proxy configuration by retrieving the user's proxy configuration in Internet Explorer.

This function should not be used in a service process that does not impersonate a logged-on user.If the caller does not impersonate a logged on user, WinHTTP attempts to retrieve the Internet Explorer settings for the current service process: for example, the local service or the network service. If the Internet Explorer settings are not configured for these system accounts, the call to **WinHttpGetIEProxyConfigForCurrentUser** will fail.

The caller must free the **lpszProxy**, **lpszProxyBypass** and **lpszAutoConfigUrl** strings in the [WINHTTP_CURRENT_USER_IE_PROXY_CONFIG](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_current_user_ie_proxy_config) structure if they are non-**NULL**. Use [GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree) to free the strings.

## See also

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)