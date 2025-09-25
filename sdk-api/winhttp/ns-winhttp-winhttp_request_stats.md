## Description

The **WINHTTP\_REQUEST\_STATS** structure contains a variety of statistics for a request.

## Members

### `ullFlags`

Flags containing details on how the request was made. The following flags are available.

| Value | Meaning |
|-|-|
| WINHTTP_REQUEST_STAT_FLAG_TCP_FAST_OPEN | TCP Fast Open occurred. |
| WINHTTP_REQUEST_STAT_FLAG_TLS_SESSION_RESUMPTION | TLS Session Resumption occurred. |
| WINHTTP_REQUEST_STAT_FLAG_TLS_FALSE_START | TLS False Start occurred. |
| WINHTTP_REQUEST_STAT_FLAG_PROXY_TLS_SESSION_RESUMPTION | TLS Session Resumption occurred for the proxy connection. |
| WINHTTP_REQUEST_STAT_FLAG_PROXY_TLS_FALSE_START | TLS False Start occurred for the proxy connection. |
| WINHTTP_REQUEST_STAT_FLAG_FIRST_REQUEST | This is the first request on the connection. |

### `ulIndex`

The index of the request on the connection. This indicates how many prior requests were sent over the shared connection.

### `cStats`

Unsigned long integer value that contains the number of statistics to retrieve. This should generally be set to **WinHttpRequestStatLast**.

### `rgullStats`

Array of unsigned long long integer values that will contain the returned statistics, indexed by [**WINHTTP\_REQUEST\_STAT\_ENTRY**](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_request_stat_entry).

## Remarks

This structure is used with [WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption) to retrieve statistics for a request by specifying the **WINHTTP\_OPTION\_REQUEST\_STATS** flag.

## See also

[WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption)