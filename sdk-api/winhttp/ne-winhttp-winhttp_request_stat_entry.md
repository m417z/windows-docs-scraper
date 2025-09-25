# WINHTTP_REQUEST_STAT_ENTRY enumeration

## Description

The **WINHTTP\_REQUEST\_STAT\_ENTRY** enumeration lists the available types of request statistics.

## Constants

### `WinHttpConnectFailureCount:0`

The number of connection failures during connection establishment.

### `WinHttpProxyFailureCount`

The number of proxy connection failures during connection establishment.

### `WinHttpTlsHandshakeClientLeg1Size`

The size of the client data for the first leg of the TLS handshake.

### `WinHttpTlsHandshakeServerLeg1Size`

The size of the server data for the first leg of the TLS handshake.

### `WinHttpTlsHandshakeClientLeg2Size`

The size of the client data for the second leg of the TLS handshake.

### `WinHttpTlsHandshakeServerLeg2Size`

The size of the server data for the second leg of the TLS handshake.

### `WinHttpRequestHeadersSize`

The size of the request headers.

### `WinHttpRequestHeadersCompressedSize`

The compressed size of the request headers.

### `WinHttpResponseHeadersSize`

The size of the response headers.

### `WinHttpResponseHeadersCompressedSize`

The compressed size of the response headers.

### `WinHttpResponseBodySize`

The size of the response body.

### `WinHttpResponseBodyCompressedSize`

The compressed size of the response body.

### `WinHttpProxyTlsHandshakeClientLeg1Size`

The size of the client data for the first leg of the proxy TLS handshake.

### `WinHttpProxyTlsHandshakeServerLeg1Size`

The size of the server data for the first leg of the proxy TLS handshake.

### `WinHttpProxyTlsHandshakeClientLeg2Size`

The size of the client data for the second leg of the proxy TLS handshake.

### `WinHttpProxyTlsHandshakeServerLeg2Size`

The size of the server data for the second leg of the proxy TLS handshake.

### `WinHttpRequestStatLast`

Marker for the end of the list of available statistics.

### `WinHttpRequestStatMax:32`

The maximum number of statistics available.

## Remarks

This structure is used with [WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption) to retrieve statistics for a request by specifying the **WINHTTP\_OPTION\_REQUEST\_STATS** flag.

## See also

[WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption)

[WINHTTP\_REQUEST\_STATS](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_request_stats)