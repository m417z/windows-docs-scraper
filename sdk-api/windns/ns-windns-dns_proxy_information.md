# DNS_PROXY_INFORMATION structure

## Description

The **DNS_PROXY_INFORMATION** structure contains the proxy information for a DNS server's name resolution policy table.

## Members

### `version`

A value that specifies the structure version. This value must be 1.

### `proxyInformationType`

A [DNS_PROXY_INFORMATION_TYPE](https://learn.microsoft.com/windows/desktop/api/windns/ne-windns-dns_proxy_information_type) enumeration that contains the proxy information type.

### `proxyName`

A pointer to a string that contains the proxy server name if **proxyInformationType** is **DNS_PROXY_INFORMATION_PROXY_NAME**. Otherwise, this member is ignored.

**Note** To free this string, use the
[DnsFreeProxyName](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsfreeproxyname) function.

## See also

[DNS Structures](https://learn.microsoft.com/windows/desktop/DNS/dns-structures)

[DnsGetProxyInformation](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsgetproxyinformation)