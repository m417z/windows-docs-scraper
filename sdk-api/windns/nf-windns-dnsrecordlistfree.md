# DnsRecordListFree macro

## Description

The
**DnsRecordListFree** function frees memory allocated for DNS records obtained using the
[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a) function.

## Parameters

### `p` [in, out, optional]

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the list of DNS records to be freed.

### `t` [in]

A specifier of how the record list should be freed. The only type currently supported is a deep freeing of the entire record list. For more information and a list of values, see the [DNS_FREE_TYPE](https://learn.microsoft.com/windows/win32/api/windns/ne-windns-dns_free_type) enumeration.

## Remarks

The
**DnsRecordListFree** function can be used to free memory allocated from query results obtained using a
[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a) function call; it cannot free memory allocated for DNS record lists created manually.

## See also

[DNS_FREE_TYPE](https://learn.microsoft.com/windows/win32/api/windns/ne-windns-dns_free_type)