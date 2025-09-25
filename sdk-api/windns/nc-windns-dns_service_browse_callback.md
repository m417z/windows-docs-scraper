## Description

Used to asynchronously return the results of a DNS-SD query.

## Parameters

### `Status`

A value that contains the status associated with this particular set of results.

### `pQueryContext`

A pointer to the user context that was passed to [DnsServiceBrowse](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsservicebrowse).

### `pDnsRecord`

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windns/ns-windnsdef-dns_recordw) structure that contains a list of records describing a discovered service on the network. If not `nullptr`, then you are responsible for freeing the returned RR sets using [DnsRecordListFree](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordlistfree).

## Remarks

## See also