## Description

The **HTTP\_REQUEST\_PROPERTY** enumeration defines the properties that you can configured to be queried or set by the HTTP Server API on a request.

## Constants

### `HttpRequestPropertyIsb`

Action: Query.
PVOID Input/Output value: ULONG64

Retrieve the ideal send backlog size for a request (see [SIO_WSK_QUERY_IDEAL_SEND_BACKLOG](https://learn.microsoft.com/windows-hardware/drivers/network/sio-wsk-query-ideal-send-backlog)).

### `HttpRequestPropertyTcpInfoV0`

Action: Query.
PVOID Input/Output value: [TCP_INFO_v0](https://learn.microsoft.com/windows/win32/api/mstcpip/ns-mstcpip-tcp_info_v0)

Retrieve the **TCP_INFO_v0** statistics for a request. Uses the *Qualifier* parameter.

### `HttpRequestPropertyQuicStats`

Action: Query.
PVOID Input/Output value: [QUIC_STATISTICS](https://github.com/microsoft/msquic/blob/main/src/inc/msquic.h)

Retrieve the **QUIC_STATISTICS** statistics for a request. Uses the *Qualifier* parameter.

### `HttpRequestPropertyTcpInfoV1`

Action: Query.
PVOID Input/Output value: [TCP_INFO_v1](https://learn.microsoft.com/windows/win32/api/mstcpip/ns-mstcpip-tcp_info_v1)

Retrieve the **TCP_INFO_v1** statistics for a request. Uses the *Qualifier* parameter.

### `HttpRequestPropertySni`

Action: Query.
PVOID Input/Output value: [HTTP_REQUEST_PROPERTY_SNI](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_request_property_sni)

Retrieve the Server Name Indication for the request's TLS connection, in a **HTTP_REQUEST_PROPERTY_SNI**.

### `HttpRequestPropertyStreamError`

Action: Set.
PVOID Input/Output value: [HTTP_REQUEST_PROPERTY_STREAM_ERROR](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_request_property_stream_error)

Set an (HTTP/2 or HTTP/3) **HTTP_REQUEST_PROPERTY_STREAM_ERROR** struct on a request. The [HTTP\_REQUEST\_PROPERTY\_STREAM\_ERROR](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_request_property_stream_error) structure contains the configuration data for this property.

### `HttpRequestPropertyWskApiTimings`

Action: Query.
PVOID Input/Output value: [HTTP_WSK_API_TIMINGS](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_wsk_api_timings)

Retrieve the **HTTP_WSK_API_TIMINGS** statistics for a request. Only used for non-QUIC requests (HTTP/1.1, HTTP/2). This property requires additional configuration to enable its use; see Remarks.

### `HttpRequestPropertyQuicApiTimings`

Action: Query.
PVOID Input/Output value: HTTP_QUIC_API_TIMINGS

Retrieve the **HTTP_QUIC_API_TIMINGS** statistics for a request. Used only for HTTP/3 requests. This property requires additional configuration to enable its use; see Remarks.

### `HttpRequestPropertyQuicStatsV2`

Action: Query.
PVOID Input/Output value: [QUIC_STATISTICS_V2](https://github.com/microsoft/msquic/blob/main/src/inc/msquic.h)

Retrieve the **QUIC_STATISTICS_V2** statistics for a request. Uses the *Qualifier* parameter.

### `HttpRequestPropertyQuicStreamStats`

Action: Query.
PVOID Input/Output value: [QUIC_STREAM_STATISTICS](https://github.com/microsoft/msquic/blob/main/src/inc/msquic.h)

Retrieve the **QUIC_STREAM_STATISTICS** statistics for a request.

### `HttpRequestPropertyTcpInfoV2`

Action: Query.
PVOID Input/Output value: [TCP_INFO_v2](https://learn.microsoft.com/windows/win32/api/mstcpip/ns-mstcpip-tcp_info_v2)

Retrieve extended **TCP_INFO_v2** statistics for a request. Uses the *Qualifier* parameter.

### `HttpRequestPropertyTlsClientHello`

Action: Query.
PVOID Input/Output value: BYTE\[\]

Retrieve the contents of the TLS Client Hello message sent by the client at the start of the connection for that request. This property requires additional configuration to enable its use; see Remarks.

### `HttpRequestPropertyTransportIdleConnectionTimeout`

Action: Set.
PVOID Input/Output value: USHORT

Set a timeout in seconds for if this request goes idle.

### `HttpRequestPropertyDscpTag`

Action: Set.
PVOID Input/Output value: BYTE

Set the differentiated services code point (DSCP) tag to the supplied BYTE value on all packets sent in the response to this request. This is a 6-bit value internally, so the maximum value is 0x3F.

### `HttpRequestPropertyTlsCipherInfo`

Action: Query.
PVOID Input/Output value: [SecPkgContext_CipherInfo](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-secpkgcontext_cipherinfo)

Retrieve the cipher suite and parameters selected for this connection in the TLS handshake.

## Remarks

The **HTTP\_REQUEST\_PROPERTY** enumeration types are used to set or query the configurations on a request. A member of this enumeration together with the associated configuration structure is used by [HttpSetRequestProperty](https://learn.microsoft.com/windows/win32/api/http/nf-http-httpsetrequestproperty) to define the configuration parameters.

**HttpRequestPropertyWskApiTimings** and **HttpRequestPropertyQuicApiTimings**. These properties require the `HKLM\System\CurrentControlSet\Services\Http\Parameters:EnableExtendedEvents` registry value to be set to 0x1 before starting or restarting the HTTP service.

**HttpRequestPropertyTlsClientHello**. To confirm the availability of this feature, call [HttpIsFeatureSupported](https://learn.microsoft.com/windows/win32/api/http/nf-http-httpisfeaturesupported) and pass **HttpFeatureCacheTlsClientHello**. Because caching the TLS Client Hello is expensive per-connection, to enable this feature you'll need to call [HttpSetServiceConfiguration](https://learn.microsoft.com/windows/win32/api/http/nf-http-httpsetserviceconfiguration) with an **HTTP_SERVICE_CONFIG_SSL_SET** struct in *pConfigInformation* with **HTTP_SERVICE_CONFIG_SSL_FLAG_ENABLE_CACHE_CLIENT_HELLO** set (see [HTTP_SERVICE_CONFIG_SSL_PARAM](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_service_config_ssl_param)). Since a TLS Client Hello doesn't have a fixed length, this property can be queried with a NULL buffer pointer to determine the size of a buffer you need; see the example in [HttpQueryRequestProperty](https://learn.microsoft.com/windows/win32/http/http/nf-http-httpqueryrequestproperty) for details.

## See also

[HttpSetRequestProperty](https://learn.microsoft.com/windows/win32/api/http/nf-http-httpsetrequestproperty)