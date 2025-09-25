# DnsCancelQuery function

## Description

The **DnsCancelQuery** function can be used to cancel a pending query to the DNS namespace.

## Parameters

### `pCancelHandle` [in]

A pointer to a [DNS_QUERY_CANCEL](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_cancel) structure used to cancel an asynchronous DNS query. The structure must have been returned in the *pCancelHandle* parameter of a previous call to [DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex).

## Return value

Returns success confirmation upon successful completion. Otherwise, it returns the appropriate DNS-specific error code as defined in Winerror.h.

## Remarks

**DnsCancelQuery** does not wait for a query to complete before cancelling. Therefore,
applications should track pending queries through their [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/desktop/api/windns/nc-windns-dns_query_completion_routine) DNS callbacks.

*pCancelHandle* is valid until the [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/desktop/api/windns/nc-windns-dns_query_completion_routine) DNS callback is invoked and **DnsCancelQuery** completes.

## See also

[DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/desktop/api/windns/nc-windns-dns_query_completion_routine)

[DNS_QUERY_REQUEST](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_request)

[DNS_QUERY_RESULT](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_result)

[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a)

[DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex)