# DnsQuery_A function

## Description

The
**DnsQuery** function type is the generic query interface to the DNS namespace, and provides application developers with a DNS query resolution interface. Like many DNS functions, the
**DnsQuery** function type is implemented in multiple forms to facilitate different character encoding.
Based on the character encoding involved, use one of the following functions:

* **DnsQuery_A** (for ANSI encoding)
* **DnsQuery_W** (for Unicode encoding)
* **DnsQuery_UTF8** (for UTF-8 encoding)

Windows 8: The [DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex) function should be used if an application requires asynchronous queries to the DNS namespace.

## Parameters

### `pszName` [in]

A pointer to a string that represents the DNS name to query.

### `wType` [in]

A value that represents the Resource Record (RR)[DNS Record Type](https://learn.microsoft.com/windows/desktop/DNS/dns-constants) that is queried. **wType** determines the format of data pointed to by **ppQueryResultsSet**. For example, if the value of **wType** is **DNS_TYPE_A**, the format of data pointed to by **ppQueryResultsSet** is [DNS_A_DATA](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsquery_a).

### `Options` [in]

A value that contains a bitmap of [DNS Query Options](https://learn.microsoft.com/windows/desktop/DNS/dns-constants) to use in the DNS query. Options can be combined and all options override **DNS_QUERY_STANDARD**.

### `pExtra` [in, out, optional]

This parameter is reserved for future use and must be set to **NULL**.

### `ppQueryResults` [out, optional]

Optional. A pointer to a pointer that points to the list of RRs that comprise the response. For more information, see the Remarks section.

### `pReserved` [out, optional]

This parameter is reserved for future use and must be set to **NULL**.

## Return value

Returns success confirmation upon successful completion. Otherwise, returns the appropriate DNS-specific error code as defined in Winerror.h.

## Remarks

Applications that call the
**DnsQuery** function build a query using a fully qualified DNS name and Resource Record (RR) type, and set query options depending on the type of service desired. When the **DNS_QUERY_STANDARD** option is set, DNS uses the resolver cache, queries first with UDP, then retries with TCP if the response is truncated, and requests that the server to perform recursive resolution on behalf of the client to resolve the query.

Applications must free returned RR sets with the [DnsRecordListFree](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordlistfree) function.

**Note** When calling one of the
**DnsQuery** function types, be aware that a DNS server may return multiple records in response to a query. A computer that is multihomed, for example, will receive multiple A records for the same IP address. The caller must use as many of the returned records as necessary.

Consider the following scenario, in which multiple returned records require additional activity on behalf of the application: A **DnsQuery_A** function call is made for a multihomed computer and the application finds that the address associated with the first A record is not responding. The application should then attempt to use other IP addresses specified in the (additional) A records returned from the **DnsQuery_A** function call.

 If the *lpstrName*  parameter is set to **NULL**, the **DnsQuery** function fails with the error **INVALID_PARAMETER**.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsQueryEx](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsqueryex)

[DnsRecordListFree](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsrecordlistfree)