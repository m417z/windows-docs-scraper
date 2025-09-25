## Description

Represents a DNS raw query request (see [DnsQueryRaw](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryraw)).

## Members

### `version`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The version of this structure. Currently only **DNS_QUERY_RAW_REQUEST_VERSION1** (0x1) exists.

### `resultsVersion`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The requested version of the **DNS_QUERY_RAW_RESULT** structure returned in the completion callback. Currently only **DNS_QUERY_RAW_RESULT_VERSION1** (0x1) exists.

### `dnsQueryRawSize`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the DNS raw query buffer, in bytes, pointed to by *dnsQueryRaw*.

### `dnsQueryRaw`

Type: **[BYTE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to the buffer containing the DNS raw query. This buffer contains the wire representation of a DNS query—a 12-byte header followed by the question section. This buffer is owned by the caller, and needs to persist only until [DnsQueryRaw](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryraw) returns.

### `dnsQueryName`

Type: **[PWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to a string that represents the DNS name to query, used in conjunction with *dnsQueryType*. If this value is present, then it will be used instead of *dnsQueryRaw*.

### `dnsQueryType`

Type: **[USHORT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Value that represents the DNS record type of the query, used in conjunction with *dnsQueryName*. These values are documented in [DNS record types](https://learn.microsoft.com/windows/win32/dns/dns-constants#dns-record-types).

### `queryOptions`

Type: **[ULONG64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Query options to be used. Makes use of the same query options from [DnsQueryEx](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryex), as documented in [DNS query options](https://learn.microsoft.com/windows/win32/dns/dns-constants#dns-query-options).

### `interfaceIndex`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The interface index to send the query over. If 0, then all interfaces will be used.

### `queryCompletionCallback`

Type: **[DNS_QUERY_RAW_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_raw_completion_routine)**

Pointer to a callback function that will be called when the query finishes. This field is required.

### `queryContext`

Type: **[VOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Pointer to a user context. This will be provided as a parameter in the *queryCompletionCallback* call. This field is required.

### `queryRawOptions`

Type: **[ULONG64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Additional options to modify the raw query.

**DNS_QUERY_RAW_OPTION_BEST_EFFORT_PARSE** (0x1). Specifies that the raw query should be parsed in a best-effort fashion. That means that [DnsQueryRaw](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryraw) won't fail in case of an input raw query that is formatted differently from expected (such as including new record types or header bits that the implementation isn't aware of) if it can extract out the necessary information including the query name and type. This will cause the query sent to the server to effectively be a subset of the caller's query with respect to the configuration.

### `customServersSize`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of custom servers pointed to by *customServers*.

### `customServers`

Type: **[DNS_CUSTOM_SERVER](https://learn.microsoft.com/windows/win32/api/windns/ns-windnsdef-dns_custom_server)\***

Pointer to an array of custom servers of size *customServersSize*. This pointer can be `NULL`, in which case *customServersSize* must be 0. If not `NULL`, then this pointer must persist until the [DnsQueryRaw](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryraw) call returns.

### `protocol`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The DNS protocol used for the source query in *dnsQueryRaw*, and what the caller expects the response to be in. You can use this to change a DNS query response to match the original query, regardless of what protocol is used by the DNS system underneath. For example, if the caller specifies UDP, and the DNS systems decides to use DNS over HTTPS (DoH), and gets a response larger than UDP allows, then the API will truncate the packet as appropriate to match the behavior of what a UDP server responds with if the result is too large. If TCP is requested by the caller, then the packet must be prefixed with the 2-byte length, as specified in section 4.2.2 of [RFC 1035](https://www.rfc-editor.org/rfc/rfc1035.html).

The allowed values are **DNS_PROTOCOL_UDP** (0x1) and **DNS_PROTOCOL_TCP** (0x2).

### `sourceAddr`

Type: **[SOCKADDR_INET](https://learn.microsoft.com/windows/win32/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)**

The address of the source of the DNS raw query.

### `maxSa`

Type: **[CHAR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\[\]**

The address of the source of the DNS raw query. You can use the *maxSa* array in code that doesn't have the [SOCKADDR_INET](https://learn.microsoft.com/windows/win32/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet) type defined.

## Remarks

## See also