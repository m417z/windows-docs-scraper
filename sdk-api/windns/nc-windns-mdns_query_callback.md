## Description

Used to asynchronously return the results of an mDNS query.

## Parameters

 _In_ PVOID pQueryContext,
_Inout_ PMDNS_QUERY_HANDLE pQueryHandle,
_Inout_ PDNS_QUERY_RESULT pQueryResults

### `pQueryContext`

A pointer to the user context that was passed to [DnsStartMulticastQuery](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsstartmulticastquery).

### `pQueryHandle`

A pointer to the [MDNS_QUERY_HANDLE](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-mdns_query_handle) structure that was passed to [DnsStartMulticastQuery](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsstartmulticastquery).

### `pQueryResults`

A pointer to a [DNS_QUERY_RESULT](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_result) structure that contains the query results. Your application is responsible for freeing the `pQueryRecords` contained in this structure using [DnsRecordListFree](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordlistfree).

## Remarks

## See also