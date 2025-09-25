# DnsGetProxyInformation function

## Description

The
**DnsGetProxyInformation** function returns the proxy information for a DNS server's name resolution policy table.

## Parameters

### `hostName` [in]

A pointer to a string that represents the name of the DNS server whose proxy information is returned.

### `proxyInformation` [in, out]

A pointer to a [DNS_PROXY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_proxy_information) structure that contains the proxy information for *hostName*.

### `defaultProxyInformation` [in, out, optional]

A pointer to a [DNS_PROXY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_proxy_information) structure that contains the default proxy information for *hostName*. This proxy information is for the wildcard DNS policy.

### `completionRoutine` [in, optional]

Reserved. Do not use.

### `completionContext` [in, optional]

Reserved. Do not use.

## Return value

The
**DnsGetProxyInformation** function returns the appropriate DNS-specific error code as defined in Winerror.h. The following are possible return values:

## See also

[DNS Functions](https://learn.microsoft.com/windows/desktop/DNS/dns-functions)