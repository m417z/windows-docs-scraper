## Description

The **DNS_SVCB_DATA** structure represents a DNS SVCB ("Service Binding") record, as specified in RFC 9460.

## Members

### `wSvcPriority`

Type: **[WORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Record priority. A lower value indicates higher priority; 0 indicates Alias Mode, as described in section 2.4.2 of RFC 9460.

### `pszTargetName`

Type: **[PSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A pointer to a null-terminated string representing the domain name of the target or alternative endpoint.

### `cSvcParams`

Type: **[WORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Count of svcb parameters.

### `pSvcParams`

Type: **[DNS_SVCB_PARAM](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_svcb_param)\***

List of SVCB parameters representing the services available at *pszTargetName*.

## Remarks

When calling [DnsQueryEx](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryex) (or any of the DNS query APIs) for [**DNS_TYPE_SVCB**](https://learn.microsoft.com/windows/win32/dns/dns-constants#dns-record-types) or **DNS_TYPE_HTTPS** DNS record types, if you want to get back results in a parsed format—that is, in the form of a **DNS_SVCB_DATA** structure instead of a 'flat' (just a data buffer) format—then you must set DNS_QUERY_PARSE_ALL_RECORDS (in [DNS_QUERY_REQUEST3::QueryOptions](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_query_request3)).

## See also