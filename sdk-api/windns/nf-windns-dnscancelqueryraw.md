## Description

Cancels a query that was initiated by calling [DnsQueryRaw](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryraw).

If the query completion callback (see [DNS_QUERY_RAW_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_raw_completion_routine)) hasn't been called by the time **DnsCancelQueryRaw** returns, then the query completion callback will lead to the callback being made with a *queryStatus* of **ERROR_CANCELLED** in the *queryResults* parameter.

## Parameters

### `cancelHandle`

Type: \_In\_ **[DNS_QUERY_RAW_CANCEL](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_query_raw_cancel)\***

The cancel handle that you obtained by calling [DnsQueryRaw](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryraw).

## Return value

A **DNS_STATUS** value indicating success or failure.

## Remarks

## See also