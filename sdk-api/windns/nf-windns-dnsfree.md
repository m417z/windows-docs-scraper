# DnsFree function

## Description

The **DnsFree** function frees memory allocated for DNS records that was obtained using the
[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a) function.

## Parameters

### `pData` [in, out]

A pointer to the DNS data to be freed.

### `FreeType` [in]

A value that specifies the type of DNS data in *pData*. For more information and a list of values, see the [DNS_FREE_TYPE](https://learn.microsoft.com/windows/win32/api/windns/ne-windns-dns_free_type) enumeration.

## See also

[DNS_FREE_TYPE](https://learn.microsoft.com/windows/win32/api/windns/ne-windns-dns_free_type)