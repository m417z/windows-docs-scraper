# DNS_QUERY_RESULT structure

## Description

A **DNS_QUERY_RESULT** structure contains the DNS query results returned from a call to [DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex).

## Members

### `Version`

The structure version must be one of the following:

#### DNS_QUERY_REQUEST_VERSION1 (1)

### `QueryStatus`

The return status of the call to [DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex).

If the query was completed asynchronously and this structure was returned directly from [DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex), **QueryStatus** contains **DNS_REQUEST_PENDING**.

If the query was completed synchronously or if this structure was returned by the [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/desktop/api/windns/nc-windns-dns_query_completion_routine) DNS callback, **QueryStatus** contains ERROR_SUCCESS if successful or the appropriate DNS-specific error code as defined in Winerror.h.

### `QueryOptions`

A value that contains a bitmap of [DNS Query Options](https://learn.microsoft.com/windows/desktop/DNS/dns-constants) that were used in the DNS query. Options can be combined and all options override **DNS_QUERY_STANDARD**

### `pQueryRecords`

A pointer to a [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure.

If the query was completed asynchronously and this structure was returned directly from [DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex), **pQueryRecords** is NULL.

If the query was completed synchronously or if this structure was returned by the [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/desktop/api/windns/nc-windns-dns_query_completion_routine) DNS callback, **pQueryRecords** contains a list of Resource Records (RR) that comprise the response.

**Note** Applications must free returned RR sets with the [DnsRecordListFree](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordlistfree) function.

### `Reserved`

### `reserved`

This value is reserved for future use and must be **NULL**.

## See also

[DNS_QUERY_CANCEL](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_cancel)

[DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/desktop/api/windns/nc-windns-dns_query_completion_routine)

[DNS_QUERY_REQUEST](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_request)