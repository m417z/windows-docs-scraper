## Description

The **DnsQueryEx** function is the asynchronous generic query interface to the DNS namespace. It provides application developers with a DNS query resolution interface.

Like [DnsQuery](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsquery_a), **DnsQueryEx** can be used to make synchronous queries to the DNS namespace as well.

## Parameters

### `pQueryRequest` [in]

A pointer to a [DNS_QUERY_REQUEST](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_query_request) or [DNS_QUERY_REQUEST3](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_query_request3) structure that contains the query request information.

**Note** By omitting the [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_completion_routine) callback from the **pQueryCompleteCallback** member of this structure, **DnsQueryEx** is called synchronously.

### `pQueryResults` [in, out]

A pointer to a [DNS_QUERY_RESULT](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_query_result) structure that contains the results of the query. On input, the **version** member of *pQueryResults* must be **DNS_QUERY_RESULTS_VERSION1** and all other members should be **NULL**. On output, the remaining members will be filled as part of the query complete.

**Note** For asynchronous queries, an application should not free
this structure until the [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_completion_routine) callback is invoked. When the query completes, the [DNS_QUERY_RESULT](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_query_result) structure contains a pointer to a list of
[DNS_RECORDS](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) that should be freed using [DnsRecordListFree](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsrecordlistfree).

### `pCancelHandle` [in, out, optional]

A pointer to a [DNS_QUERY_CANCEL](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_query_cancel) structure that can be used to cancel a
pending asynchronous query.

**Note** An application should not free
this structure until the [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_completion_routine) callback is invoked.

## Return value

The
**DnsQueryEx** function has the following possible return values:

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The call was successful. |
| **ERROR_INVALID_PARAMETER** | Either the *pQueryRequest* or *pQueryResults* parameters are uninitialized or contain the wrong version. |
| **DNS RCODE** | The call resulted in an [RCODE](https://learn.microsoft.com/windows/desktop/DNS/dns-constants) error. |
| **DNS_INFO_NO_RECORDS** | No records in the response. |
| **DNS_REQUEST_PENDING** | The query will be completed asynchronously. |

## Remarks

If a call to **DnsQueryEx** completes synchronously (i.e., the function return value is not **DNS_REQUEST_PENDING**), the **pQueryRecords** member of *pQueryResults* contains a pointer to a list of [DNS_RECORDS](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) and **DnsQueryEx** will return either error or success.

The following conditions invoke a synchronous call to **DnsQueryEx** and do not utilize the DNS callback:

* The [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_completion_routine) callback is omitted from the **pQueryCompleteCallback** member of *pQueryRequest*.
* A query is for the local machine name and [A](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsquery_a) or [AAAA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_aaaa_data) type Resource Records (RR).
* A call to **DnsQueryEx** queries an IPv4 or IPv6 address.
* A call to **DnsQueryEx** returns in error.

If a call to **DnsQueryEx** completes asynchronously, the results of the query are returned by the [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_completion_routine) callback in *pQueryRequest*, the **QueryStatus** member of *pQueryResults* contains **DNS_REQUEST_PENDING**, and **DnsQueryEx** returns **DNS_REQUEST_PENDING**. Applications should track the *pQueryResults* structure that is passed into **DnsQueryEx** until the DNS callback succeeds. Applications can cancel an asynchronous query using the *pCancelHandle* handle returned by **DnsQueryEx**.

*pCancelHandle* returned from an asynchronous call to **DnsQueryEx** and *pQueryContext* is valid until the [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_completion_routine) DNS callback is invoked.

**Note** Applications are notified of asynchronous **DnsQueryEx** completion through the [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_completion_routine) callback within the same process context.

## See also

* [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_completion_routine)
* [DnsCancelQuery](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnscancelquery)
* [DnsQuery](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsquery_a)