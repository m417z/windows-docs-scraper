# DNS_QUERY_COMPLETION_ROUTINE callback function

## Description

The **DNS_QUERY_COMPLETION_ROUTINE** callback is used to asynchronously return the results of a DNS query.

## Parameters

### `pQueryContext` [in]

A pointer to a user context.

### `pQueryResults` [in, out]

A pointer to a [DNS_QUERY_RESULT](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_result) structure that contains the DNS query results from a call to [DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex).

## See also

[DNS_QUERY_CANCEL](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_cancel)

[DNS_QUERY_REQUEST](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_request)

[DNS_QUERY_RESULT](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_result)

[DnsCancelQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnscancelquery)

[DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex)