## Description

Uses the
[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure to return data associated with a specific request.

Do not use **HTTP_REQUEST_V1** directly in your code; using [HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) instead ensures that the proper version, based on the operating system the code is compiled under, is used.

## Members

### `Flags`

A combination of zero or more of the following flag values may be combined, with OR, as appropriate.

| Value | Meaning |
| --- | --- |
| **HTTP_REQUEST_FLAG_MORE_ENTITY_BODY_EXISTS** | There is more entity body to be read for this request. This applies only to incoming requests that span multiple reads. <br><br>If this value is not set, either the whole entity body was copied into the buffer specified by **pEntityChunks** or the request did not include an entity body. |
| **HTTP_REQUEST_FLAG_IP_ROUTED** | The request was routed based on host and IP binding. The application should reflect the local IP while flushing kernel cache entries for this request.<br><br>**Windows Server 2003 with SP1 and Windows XP with SP2:** This flag is not supported. |
| **HTTP_REQUEST_FLAG_HTTP2** | Indicates the request was received over HTTP/2. |

### `ConnectionId`

An identifier for the connection on which the request was received. Use this value when calling
[HttpWaitForDisconnect](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpwaitfordisconnect) or
[HttpReceiveClientCertificate](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceiveclientcertificate).

### `RequestId`

A value used to identify the request when calling
[HttpReceiveRequestEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceiverequestentitybody),
[HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse), and/or
[HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody).

### `UrlContext`

The context that is associated with the URL in the *pRawUrl* parameter.

**Windows Server 2003 with SP1 and Windows XP with SP2:**

### `Version`

An
[HTTP_VERSION](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_version) structure that contains the version of HTTP specified by this request.

### `Verb`

An HTTP verb associated with this request. This member can be one of the values from the
[HTTP_VERB](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_verb) enumeration.

### `UnknownVerbLength`

If the **Verb** member contains a value equal to **HttpVerbUnknown**, the **UnknownVerbLength** member contains the size, in bytes, of the string pointed to by the **pUnknownVerb** member, not including the terminating null character. If **Verb** is not equal to **HttpVerbUnknown**, **UnknownVerbLength** is equal to zero.

### `RawUrlLength`

The size, in bytes, of the unprocessed URL string pointed to by the **pRawUrl** member, not including the terminating null character.

### `pUnknownVerb`

If the **Verb** member is equal to **HttpVerbUnknown**, **pUnknownVerb**, points to a null-terminated string of octets that contains the HTTP verb for this request; otherwise, the application ignores this parameter.

### `pRawUrl`

A pointer to a string of octets that contains the original, unprocessed URL targeted by this request. Use this unprocessed URL only for tracking or statistical purposes; the **CookedUrl** member contains the canonical form of the URL for general use.

### `CookedUrl`

An
[HTTP_COOKED_URL](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_cooked_url) structure that contains a parsed canonical wide-character version of the URL targeted by this request. This is the version of the URL HTTP Listeners should act upon, rather than the raw URL.

### `Address`

An
[HTTP_TRANSPORT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_transport_address) structure that contains the transport addresses for the connection for this request.

### `Headers`

An
[HTTP_REQUEST_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_headers) structure that contains the headers specified in this request.

### `BytesReceived`

The total number of bytes received from the network comprising this request.

### `EntityChunkCount`

The number of elements in the **pEntityChunks** array. If no entity body was copied, this value is zero.

### `pEntityChunks`

A pointer to an array of
[HTTP_DATA_CHUNK](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_data_chunk) structures that contains the data blocks making up the entity body.
[HttpReceiveHttpRequest](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceivehttprequest) does not copy the entity body unless called with the HTTP_RECEIVE_REQUEST_FLAG_COPY_BODY flag set.

### `RawConnectionId`

Raw connection ID for an Secure Sockets Layer (SSL) request.

### `pSslInfo`

A pointer to an
[HTTP_SSL_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_ssl_info) structure that contains Secure Sockets Layer (SSL) information about the connection on which the request was received.

## Remarks

The unprocessed URL contained in the **pRawUrl** member is for tracking and statistical purposes only. For other purposes, use the processed, canonical URL contained in the **CookedUrl** member.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_COOKED_URL](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_cooked_url)

[HTTP_DATA_CHUNK](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_data_chunk)

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))

[HTTP_REQUEST_V2](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_v2)

[HTTP_RESPONSE](https://learn.microsoft.com/windows/desktop/Http/http-response)

[HTTP_SSL_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_ssl_info)

[HTTP_TRANSPORT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_transport_address)

[HTTP_VERB](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_verb)

[HttpReceiveHttpRequest](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceivehttprequest)

[HttpReceiveRequestEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceiverequestentitybody)

[HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse)

[HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody)