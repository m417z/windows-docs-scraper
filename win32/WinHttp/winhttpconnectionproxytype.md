# WINHTTP_CONNECTION_PROXY_TYPE enumeration

Specifies the type of proxy protocol for a per-connection proxy configuration.

## Constants

| Constant | Value | Description |
|----------|-------|-------------|
| **WINHTTP_CONNECTION_PROXY_TYPE_NULL** | 0 | No proxy / placeholder. |
| **WINHTTP_CONNECTION_PROXY_TYPE_HTTP** | 1 | HTTP/HTTPS proxy. |

## Remarks

> [!NOTE]
> This type is not currently included in an SDK header file. You must declare it yourself in your code.

## Requirements

| Requirement | Value |
|---|---|
| Header | N/A |

## See also

- [WinHttpConnectionSetProxyInfo](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionsetproxyinfo)
- [WinHttpConnectionDeleteProxyInfo](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectiondeleteproxyinfo)
- [WINHTTP_CONNECTION_PROXY_INFO](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionproxyinfo)