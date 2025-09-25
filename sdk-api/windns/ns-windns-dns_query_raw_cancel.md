## Description

Represents a DNS raw query cancel handle (see [DnsQueryRaw](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryraw) and [DnsCancelQueryRaw](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnscancelqueryraw)).

This structure must persist until the query completion callback is made (see [DNS_QUERY_RAW_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_raw_completion_routine)), and it can't be copied elsewhere after it's been passed into [DnsQueryRaw](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryraw). If the query completion callback hasn't been called by the time [DnsCancelQueryRaw](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnscancelqueryraw) returns, then the query completion callback will lead to the callback being made with a *queryStatus* of **ERROR_CANCELLED** in the *queryResults* parameter. No special cleanup is required for this structure once the query is complete. Similar to the cancel structure used for [DnsQueryEx](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsqueryex); for more details, see [DNS_QUERY_CANCEL](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_query_cancel).

## Members

### `reserved`

Type: **[CHAR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\[\]**

Opaque handle structure used for cancel.

## Remarks

## See also