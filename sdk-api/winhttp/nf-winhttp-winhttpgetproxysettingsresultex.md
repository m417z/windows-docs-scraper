## Description

Retrieves the results of a call to [WinHttpGetProxySettingsEx](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpgetproxysettingsex).

## Parameters

### `hResolver`

Type: \_In\_ **[HINTERNET](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The resolver handle used to issue a previously completed call to [WinHttpGetProxySettingsEx](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpgetproxysettingsex).

### `pProxySettingsEx`

A pointer to a [WINHTTP_PROXY_SETTINGS_EX](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_proxy_settings_ex) structure. The memory occupied by the structure is allocated by **WinHttpGetProxySettingsResultEx**, so you need to free that memory by passing this pointer to [WinHttpFreeProxySettingsEx](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpfreeproxysettingsex).

## Return value

## Remarks

## See also