## Description

Configures per-application DNS settings. This includes the ability to set per-application DNS servers either as fallback to the system configured servers, or exclusively.

## Parameters

### `cServers`

Type: \_In\_ **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of custom DNS servers present in the *pServers* parameter.

### `pServers`

Type: \_In\_reads\_(cServers) **[DNS_CUSTOM_SERVER](https://learn.microsoft.com/windows/win32/api/windns/ns-windnsdef-dns_custom_server)\***

An array of [DNS_CUSTOM_SERVER](https://learn.microsoft.com/windows/win32/api/windns/ns-windnsdef-dns_custom_server) that contains *cServers* elements. If *cServers* is 0, then this must be **NULL**.

### `pSettings`

Type: \_In\_opt\_ **[DNS_APPLICATION_SETTINGS](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_application_settings)\***

A pointer to a [DNS_APPLICATION_SETTINGS](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_application_settings) object describing additional settings for custom DNS servers.

If this is **NULL**, then the custom DNS servers passed to the API will be used as fallback to the system-configured ones.

If this points to a [DNS_APPLICATION_SETTINGS](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_application_settings) object that has the **DNS_APP_SETTINGS_EXCLUSIVE_SERVERS** flag set in its *Flags* member, then it means use the custom DNS servers exclusively.

## Return value

A **DWORD** containing **ERROR_SUCCESS** on success, or an error code on failure.

## Remarks

## See also