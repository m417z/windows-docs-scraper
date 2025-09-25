## Description

Frees the array of custom servers that was returned from a previous call to [DnsGetApplicationSettings](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsgetapplicationsettings).

## Parameters

### `pcServers`

Type: \_Inout\_ **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to a **DWORD** that contains the number of servers present in the array pointed to by *ppServers*. This will be set to 0 after the function call.

### `ppServers`

Type: \_Inout\_ **[DNS_CUSTOM_SERVER](https://learn.microsoft.com/windows/win32/api/windns/ns-windnsdef-dns_custom_server)\*\***

A pointer to an array of [DNS_CUSTOM_SERVER](https://learn.microsoft.com/windows/win32/api/windns/ns-windnsdef-dns_custom_server) that contains *pcServers* elements. This will be set to **NULL** after the function call.

## Remarks

To avoid memory leaks, you must call **DnsFreeCustomServers** on the servers returned by [DnsGetApplicationSettings](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsgetapplicationsettings) via its *pSettings* parameter.

## See also

* [DnsGetApplicationSettings](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsgetapplicationsettings)