## Description

**DNS_QUERY_RAW_COMPLETION_ROUTINE** is the function signature of an asynchronous callback function that you implement. The system calls your implementation with the results of a query that you initiated by calling [DnsQueryRaw](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryraw). The results contain both the parsed records and the raw result packet, to be passed on to later systems as desired. The result provides information about the server that provided the results.

The system calls this callback on query completion if **DnsQueryRaw** returns **DNS_REQUEST_PENDING**; and it will indicate the results of the query if successful, or any failures or cancellations.

## Parameters

### `queryContext`

Type: \_In\_ **[VOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to the query context that was passed into [DnsQueryRaw](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryraw) through the *queryContext* field of [DNS_QUERY_RAW_REQUEST](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_query_raw_request).

### `queryResults`

Type: \_Inout\_ **[DNS_QUERY_RAW_RESULT](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_query_raw_result)\***

A pointer to the results of the query. If this callback is made because of a query cancellation through [DnsCancelQueryRaw](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnscancelqueryraw), then the *queryStatus* field in *queryResults* will be set to **ERROR_CANCELLED**.

If it's not `NULL`, then you must free the *queryResults* pointer by using [DnsQueryRawResultFree](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryrawresultfree).

## Remarks

## See also