# DNS_QUERY_CANCEL structure

## Description

A **DNS_QUERY_CANCEL** structure can be used to cancel an asynchronous DNS query.

## Members

### `Reserved`

Contains a handle to the asynchronous query to cancel. Applications must not modify this value.

## Remarks

This structure is returned in the *pCancelHandle* parameter from a previous call to [DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex).

## See also

[DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/desktop/api/windns/nc-windns-dns_query_completion_routine)

[DNS_QUERY_REQUEST](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_request)

[DNS_QUERY_RESULT](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_result)