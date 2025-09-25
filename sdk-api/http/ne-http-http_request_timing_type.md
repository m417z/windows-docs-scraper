## Description

Defines constants that specify possible request timings for which information will be returned in [HTTP_REQUEST_TIMING_INFO](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_request_timing_info). Not all timings apply for every request.

## Constants

### `HttpRequestTimingTypeConnectionStart`

Time the connection started.

### `HttpRequestTimingTypeDataStart`

Time the first HTTP byte is received.

### `HttpRequestTimingTypeTlsCertificateLoadStart`

Time TLS certificate loading starts.

### `HttpRequestTimingTypeTlsCertificateLoadEnd`

Time TLS certificate loading ends.

### `HttpRequestTimingTypeTlsHandshakeLeg1Start`

Time TLS leg one handshake starts.

### `HttpRequestTimingTypeTlsHandshakeLeg1End`

Time TLS leg one handshake ends.

### `HttpRequestTimingTypeTlsHandshakeLeg2Start`

Time TLS leg two handshake starts.

### `HttpRequestTimingTypeTlsHandshakeLeg2End`

Time TLS leg two handshake ends.

### `HttpRequestTimingTypeTlsAttributesQueryStart`

Time TLS attribute query starts.

### `HttpRequestTimingTypeTlsAttributesQueryEnd`

Time TLS attribute query ends.

### `HttpRequestTimingTypeTlsClientCertQueryStart`

Time TLS client certificate query starts.

### `HttpRequestTimingTypeTlsClientCertQueryEnd`

Time TLS client certificate query ends.

### `HttpRequestTimingTypeHttp2StreamStart`

Time HTTP2 streaming starts.

### `HttpRequestTimingTypeHttp2HeaderDecodeStart`

Time HTTP2 header decoding starts.

### `HttpRequestTimingTypeHttp2HeaderDecodeEnd`

Time HTTP2 header decoding ends.

### `HttpRequestTimingTypeRequestHeaderParseStart`

Time HTTP header parsing starts. For most requests, this is a good timestamp to use as a per-request starting timestamp.

### `HttpRequestTimingTypeRequestHeaderParseEnd`

Time HTTP header parsing ends.

### `HttpRequestTimingTypeRequestRoutingStart`

Time `Http.Sys` starts to determine which request queue to route the request to.

### `HttpRequestTimingTypeRequestRoutingEnd`

Time `Http.Sys` has determined which request queue to route the request to.

### `HttpRequestTimingTypeRequestQueuedForInspection`

Time the request is queued for inspection.

### `HttpRequestTimingTypeRequestDeliveredForInspection`

Time the request is delivered for inspection.

### `HttpRequestTimingTypeRequestReturnedAfterInspection`

Time the request has finished being inspected.

### `HttpRequestTimingTypeRequestQueuedForDelegation`

Time the request is queued for delegation.

### `HttpRequestTimingTypeRequestDeliveredForDelegation`

Time the request is delivered for delegation.

### `HttpRequestTimingTypeRequestReturnedAfterDelegation`

Time the request was delegated.

### `HttpRequestTimingTypeRequestQueuedForIO`

Time the request was queued to the final request queue for processing.

### `HttpRequestTimingTypeRequestDeliveredForIO`

Time the request was delivered to the final request queue for processing.

### `HttpRequestTimingTypeHttp3StreamStart`

Time HTTP3 streaming starts.

### `HttpRequestTimingTypeHttp3HeaderDecodeStart`

Time HTTP3 header decoding starts.

### `HttpRequestTimingTypeHttp3HeaderDecodeEnd`

Time HTTP3 header decoding ends.

### `HttpRequestTimingTypeMax`

## Remarks

## See also