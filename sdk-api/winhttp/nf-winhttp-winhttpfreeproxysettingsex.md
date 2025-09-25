## Description

Frees the data retrieved from a previous call to [WinHttpGetProxySettingsResultEx](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpgetproxysettingsresultex).

## Parameters

### `ProxySettingsType`

Type: \_In\_ **[WINHTTP_PROXY_SETTINGS_TYPE](https://learn.microsoft.com/windows/win32/api/winhttp/ne-winhttp-winhttp_proxy_settings_type)**

A proxy settings type.

### `pProxySettingsEx`

Type: \_In\_ **[PVOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A pointer to a [WINHTTP_PROXY_SETTINGS_EX](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_proxy_settings_ex) structure that was retrieved from a previous call to [WinHttpGetProxySettingsResultEx](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpgetproxysettingsresultex).

## Return value

This function does not return a value.

## Remarks

## See also