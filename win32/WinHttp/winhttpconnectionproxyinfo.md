# WINHTTP_CONNECTION_PROXY_INFO structure

Contains proxy configuration for a named network connection. The structure uses a union to support both manual proxy configuration and automatic (PAC script / WPAD) configuration.

## Members

### Version

Structure version. Must be set to **WINHTTP_CONNECTION_PROXY_INFO_CURRENT_VERSION** (1).

### pwszFriendlyName

A unique display name for the proxy configuration entry. If set to **NULL** or an empty string, a unique name is auto-generated.

Maximum length: **WINHTTP_CONNECTION_PROXY_INFO_FRIENDLY_NAME_MAX_LENGTH** (64 characters).

### Flags

A combination of the following flags.

| Flag | Value | Description |
|------|-------|-------------|
| **WINHTTP_CONNECTION_PROXY_INFO_FLAG_DISABLED** | 0x1 | The proxy entry is disabled. |
| **WINHTTP_CONNECTION_PROXY_INFO_FLAG_BYPASSLOCAL** | 0x2 | Bypass the proxy for local addresses. |

### Switch

A [WINHTTP_CONNECTION_PROXY_INFO_SWITCH](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionproxyinfoswitch) value that determines which union member is active.

### Config

Used when **Switch** is **WINHTTP_CONNECTION_PROXY_INFO_SWITCH_CONFIG**. Contains manual proxy configuration.

| Member | Description |
|--------|-------------|
| **pwszServer** | Proxy server address. Maximum length: **WINHTTP_CONNECTION_PROXY_INFO_SERVER_MAX_LENGTH** (256 characters). |
| **pwszUsername** | Authentication username. Maximum length: **WINHTTP_CONNECTION_PROXY_INFO_USERNAME_MAX_LENGTH** (128 characters). |
| **pwszPassword** | Authentication password. Maximum length: **WINHTTP_CONNECTION_PROXY_INFO_PASSWORD_MAX_LENGTH** (128 characters). |
| **pwszException** | Bypass/exception list. Maximum length: **WINHTTP_CONNECTION_PROXY_INFO_EXCEPTION_MAX_LENGTH** (1024 characters). |
| **pwszExtraInfo** | Additional provider-specific info. Maximum length: **WINHTTP_CONNECTION_PROXY_INFO_EXTRA_INFO_MAX_LENGTH** (1024 characters). |
| **Port** | Proxy port number. |

### Script

Used when **Switch** is **WINHTTP_CONNECTION_PROXY_INFO_SWITCH_SCRIPT** or **WINHTTP_CONNECTION_PROXY_INFO_SWITCH_WPAD**. Contains automatic proxy configuration.

| Member | Description |
|--------|-------------|
| **pwszScript** | PAC script URL or WPAD URL. |
| **pwszUsername** | Authentication username. |
| **pwszPassword** | Authentication password. |

## Remarks

> [!NOTE]
> This type is not currently included in an SDK header file. You must declare it yourself in your code.

## Requirements

| Requirement | Value |
|---|---|
| Header | N/A |

## See also

- [WINHTTP_CONNECTION_PROXY_INFO_SWITCH](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionproxyinfoswitch)
- [WINHTTP_CONNECTION_PROXY_TYPE](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionproxytype)
- [WinHttpConnectionSetProxyInfo](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionsetproxyinfo)
- [WinHttpConnectionDeleteProxyInfo](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectiondeleteproxyinfo)