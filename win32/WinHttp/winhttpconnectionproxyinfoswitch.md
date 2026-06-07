# WINHTTP_CONNECTION_PROXY_INFO_SWITCH enumeration

Specifies the configuration mode for a per-connection proxy entry. Determines which member of the **WINHTTP_CONNECTION_PROXY_INFO** union is active.

## Constants

| Constant | Value | Description |
|----------|-------|-------------|
| **WINHTTP_CONNECTION_PROXY_INFO_SWITCH_CONFIG** | 0 | Manual proxy configuration. The **Config** member of the [WINHTTP_CONNECTION_PROXY_INFO](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionproxyinfo) union is used, providing a server address, port, credentials, exception list, and extra info. |
| **WINHTTP_CONNECTION_PROXY_INFO_SWITCH_SCRIPT** | 1 | Automatic proxy configuration via PAC script URL. The **Script** member of the union is used, providing a script URL and optional credentials. |
| **WINHTTP_CONNECTION_PROXY_INFO_SWITCH_WPAD** | 2 | Automatic proxy configuration via WPAD auto-discovery. The **Script** member of the union is used, providing a WPAD URL and optional credentials. |

## Remarks

> [!NOTE]
> This type is not currently included in an SDK header file. You must declare it yourself in your code.

## Requirements

| Requirement | Value |
|---|---|
| Header | N/A |

## See also

- [WINHTTP_CONNECTION_PROXY_INFO](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionproxyinfo)
- [WinHttpConnectionSetProxyInfo](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionsetproxyinfo)