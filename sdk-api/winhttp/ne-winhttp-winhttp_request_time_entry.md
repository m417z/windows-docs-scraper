# WINHTTP_REQUEST_TIME_ENTRY enumeration

## Description

The **WINHTTP\_REQUEST\_TIME\_ENTRY** enumeration lists the available types of request timing information.

## Constants

### `WinHttpProxyDetectionStart:0`

Start of proxy detection.

### `WinHttpProxyDetectionEnd`

End of proxy detection.

### `WinHttpConnectionAcquireStart`

Start of connection acquisition.

### `WinHttpConnectionAcquireWaitEnd`

End waiting for an available connection.

### `WinHttpConnectionAcquireEnd`

End of connection acquisition.

### `WinHttpNameResolutionStart`

Start of name resolution.

### `WinHttpNameResolutionEnd`

End of name resolution.

### `WinHttpConnectionEstablishmentStart`

Start of connection establishment.

### `WinHttpConnectionEstablishmentEnd`

End of connection establishment.

### `WinHttpTlsHandshakeClientLeg1Start`

Start of the first leg of the TLS handshake.

### `WinHttpTlsHandshakeClientLeg1End`

End of the first leg of the TLS handshake.

### `WinHttpTlsHandshakeClientLeg2Start`

Start of the second leg of the TLS handshake.

### `WinHttpTlsHandshakeClientLeg2End`

End of the second leg of the TLS handshake.

### `WinHttpTlsHandshakeClientLeg3Start`

Start of the third leg of the TLS handshake.

### `WinHttpTlsHandshakeClientLeg3End`

End of the third leg of the TLS handshake.

### `WinHttpStreamWaitStart`

Start waiting for an available stream.

### `WinHttpStreamWaitEnd`

End waiting for an available stream.

### `WinHttpSendRequestStart`

Start sending a request.

### `WinHttpSendRequestHeadersCompressionStart`

Start of request header compression.

### `WinHttpSendRequestHeadersCompressionEnd`

End of request header compression.

### `WinHttpSendRequestHeadersEnd`

End sending request headers.

### `WinHttpSendRequestEnd`

End sending a request.

### `WinHttpReceiveResponseStart`

Start receiving a response.

### `WinHttpReceiveResponseHeadersDecompressionStart`

Start of response header decompression.

### `WinHttpReceiveResponseHeadersDecompressionEnd`

End of response header decompression.

### `WinHttpReceiveResponseHeadersEnd`

End receiving response headers.

### `WinHttpReceiveResponseBodyDecompressionDelta`

Delta between start and end times for response body decompression.

### `WinHttpReceiveResponseEnd`

End receiving a response.

### `WinHttpProxyTunnelStart`

Start establishing a proxy tunnel.

### `WinHttpProxyTunnelEnd`

End establishing a proxy tunnel.

### `WinHttpProxyTlsHandshakeClientLeg1Start`

Start of the first leg of the proxy TLS handshake.

### `WinHttpProxyTlsHandshakeClientLeg1End`

End of the first leg of the proxy TLS handshake.

### `WinHttpProxyTlsHandshakeClientLeg2Start`

Start of the second leg of the proxy TLS handshake.

### `WinHttpProxyTlsHandshakeClientLeg2End`

End of the second leg of the proxy TLS handshake.

### `WinHttpProxyTlsHandshakeClientLeg3Start`

Start of the third leg of the proxy TLS handshake.

### `WinHttpProxyTlsHandshakeClientLeg3End`

End of the third leg of the proxy TLS handshake.

### `WinHttpRequestTimeLast`

Marker for the end of the list of available timings.

### `WinHttpRequestTimeMax:64`

The maximum number of timings available.

## Remarks

This structure is used with [WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption) to retrieve timing information for a request by specifying the **WINHTTP\_OPTION\_REQUEST\_TIMES** flag.

## See also

[WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption)

[WINHTTP\_REQUEST\_TIMES](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_request_times)