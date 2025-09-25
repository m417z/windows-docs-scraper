## Description

Contains the DNS query parameters used in a call to [DnsQueryEx](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryex).

## Members

### `Version`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The structure version must be the **DNS_QUERY_REQUEST_VERSION3**; which has a value of 3.

### `QueryName`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A pointer to a string that represents the DNS name to query.

> [!NOTE]
> If *QueryName* is **NULL**, then the query is for the local machine name.

### `QueryType`

Type: **[WORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A value that represents the Resource Record (RR) [DNS Record Type](https://learn.microsoft.com/windows/win32/dns/dns-constants#dns-record-types) that is queried. *QueryType* determines the format of data pointed to by *pQueryRecords* returned in the [DNS_QUERY_RESULT](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_query_result) structure. For example, if the value of *wType* is [DNS_TYPE_A](https://learn.microsoft.com/windows/win32/dns/dns-constants), then the format of data pointed to by *pQueryRecords* is [DNS_A_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_a_data).

### `QueryOptions`

Type: **[ULONG64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A value that contains a bitmap of [DNS Query Options](https://learn.microsoft.com/windows/win32/dns/dns-constants#dns-query-options) to use in the DNS query. Options can be combined, and all options override **DNS_QUERY_STANDARD**.

### `pDnsServerList`

Type: **[PDNS_ADDR_ARRAY](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_addr_array)**

A pointer to a [DNS_ADDR_ARRAY](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_addr_array) structure that contains a list of DNS servers to use in the query.

### `InterfaceIndex`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A value that contains the interface index over which the query is sent. If *InterfaceIndex* is 0, then all interfaces will be considered.

### `pQueryCompletionCallback`

Type: **[PDNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_completion_routine)**

A pointer to a [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_completion_routine) callback that is used to return the results of an asynchronous query from a call to [DnsQueryEx](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryex).

> [!NOTE]
> If **NULL**, then [DnsQueryEx](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryex) is called synchronously.

### `pQueryContext`

Type: **[PVOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A pointer to a user context.

### `IsNetworkQueryRequired`

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Reserved.

### `RequiredNetworkIndex`

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Reserved.

### `cCustomServers`

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of custom servers pointed to by the *pCustomServers* member.

### `pCustomServers`

Type: \_Field\_size\_(cCustomServers) **[DNS_CUSTOM_SERVER](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_custom_server)\***

A pointer to an array of N (where N is given in the *cCustomServers* field) [DNS_CUSTOM_SERVER](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_custom_server) objects.

If *cCustomServers* is 0, then *pCustomServers* must be **NULL**.

> [!NOTE]
> At least one of *pCustomServers* and *pDnsServerList* must be **NULL**. Both set to non-**NULL** values at the same time is not supported.

## Remarks

The custom servers specified in *pCustomServers* bypass the system-configured DNS servers.

If the query name matches a rule in the **Name Resolution Policy Table (NRPT)**, then the custom servers are ignored, and only the servers from the **NRPT** rule are used.

## See also

* [DNS_ADDR_ARRAY](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_addr_array)
* [DNS constants](https://learn.microsoft.com/windows/win32/dns/dns-constants)
* [DNS_CUSTOM_SERVER](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_custom_server)
* [DnsQueryEx function](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryex)
* [DNS_QUERY_RESULT](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_query_result)