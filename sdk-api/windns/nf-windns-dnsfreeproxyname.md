# DnsFreeProxyName function

## Description

The
**DnsFreeProxyName** function frees memory allocated for the **proxyName** member of a [DNS_PROXY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_proxy_information) structure obtained using the
[DnsGetProxyInformation](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsgetproxyinformation) function.

## Parameters

### `proxyName` [in, out]

A pointer to the **proxyName** string to be freed.

## See also

[DNS Functions](https://learn.microsoft.com/windows/desktop/DNS/dns-functions)