# DNS_QUERY_REQUEST structure

## Description

The **DNS_QUERY_REQUEST** structure contains the DNS query parameters used in a call to [DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex).

## Members

### `Version`

The structure version must be one of the following:

#### DNS_QUERY_REQUEST_VERSION1 (1)

### `QueryName`

A pointer to a string that represents the DNS name to query.

**Note** If **QueryName** is NULL, the query is for the local machine name.

### `QueryType`

A value that represents the Resource Record (RR) [DNS Record Type](https://learn.microsoft.com/windows/desktop/DNS/dns-constants) that is queried. **QueryType** determines the format of data pointed to by **pQueryRecords** returned in the [DNS_QUERY_RESULT](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_result) structure. For example, if the value of **wType** is **DNS_TYPE_A**, the format of data pointed to by **pQueryRecords** is [DNS_A_DATA](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsquery_a).

### `QueryOptions`

A value that contains a bitmap of [DNS Query Options](https://learn.microsoft.com/windows/desktop/DNS/dns-constants) to use in the DNS query. Options can be combined and all options override **DNS_QUERY_STANDARD**

### `pDnsServerList`

A pointer to a [DNS_ADDR_ARRAY](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_addr_array) structure that contains a list of DNS servers to use in the query.

### `InterfaceIndex`

A value that contains the interface index over which the query is sent. If **InterfaceIndex** is 0, all interfaces will be considered.

### `pQueryCompletionCallback`

A pointer to a [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/desktop/api/windns/nc-windns-dns_query_completion_routine) callback that is used to return the results of an asynchronous query from a call to [DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex).

**Note** If NULL, [DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex) is called synchronously.

### `pQueryContext`

A pointer to a user context.

## See also

[DNS_QUERY_CANCEL](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_cancel)

[DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/desktop/api/windns/nc-windns-dns_query_completion_routine)

[DNS_QUERY_RESULT](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_query_result)

[DnsCancelQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnscancelquery)

[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a)

[DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex)