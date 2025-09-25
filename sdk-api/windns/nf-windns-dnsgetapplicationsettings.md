## Description

Retrieves the per-application DNS settings.

## Parameters

### `pcServers`

Type: \_Out\_ **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

After the function call, this will point to the number of custom DNS servers that the application has configured. If there are no custom servers configured, or if the function fails, then this will be set to 0.

### `ppDefaultServers`

Type: \_Outptr\_result\_buffer\_(*pcServers) **[DNS_CUSTOM_SERVER](https://learn.microsoft.com/windows/win32/api/windns/ns-windnsdef-dns_custom_server)\*\***

After the function call, this will point to the array of DNS custom servers that are configured for the application. If the application has no servers configured, or if the function fails, then this will be set to **NULL**.

### `pSettings`

Type: \_Out\_opt\_ **[DNS_APPLICATION_SETTINGS](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_application_settings)\***

A pointer to a [DNS_APPLICATION_SETTINGS](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_application_settings) object, populated with the application settings.

## Return value

A **DWORD** containing **ERROR_SUCCESS** on success, or an error code on failure.

## Remarks

To avoid memory leaks, you must call [DnsFreeCustomServers](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsfreecustomservers) on the servers returned by **DnsGetApplicationSettings** via its *pSettings* parameter.

## See also

* [DnsFreeCustomServers](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsfreecustomservers)