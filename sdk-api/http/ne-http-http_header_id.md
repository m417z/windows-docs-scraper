# HTTP_HEADER_ID enumeration

## Description

The
**HTTP_HEADER_ID** enumeration type lists *known headers* for HTTP requests and responses, and associates an array index with each such header. It is used to size and access the **KnownHeaders** array members of the
[HTTP_REQUEST_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_headers) and
[HTTP_RESPONSE_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_headers) structures.

## Constants

### `HttpHeaderCacheControl:0`

Used to specify caching behavior along the request or response chain, overriding the default caching algorithm.

### `HttpHeaderConnection:1`

Allows the sender to specify options that are desired for that particular connection. These are used for a single connection only and must not be communicated by proxies over further connections.

### `HttpHeaderDate:2`

The Date is a general header field that indicates the time that the request or response was sent.

### `HttpHeaderKeepAlive:3`

Based on the keepalive XML element (see [RFC 2518](https://www.ietf.org/rfc/rfc2518.txt), section 12.12.1, page 66); a list of URIs included in the KeepAlive
header must be "live" after they are copied
(moved) to the destination.

### `HttpHeaderPragma:4`

Used to include optional, implementation-specific directives that might apply to any recipient along the request/response chain.

### `HttpHeaderTrailer:5`

Indicates that specified header fields are present in the trailer of a message encoded with chunked transfer-coding.

### `HttpHeaderTransferEncoding:6`

Indicates what, if any, transformations have been applied to the message body in transit.

### `HttpHeaderUpgrade:7`

Allows the client to specify one or more other communication protocols it would prefer to use if the server can comply.

### `HttpHeaderVia:8`

The Via header field indicates the path taken by the request.

### `HttpHeaderWarning:9`

This is a response header that contains the 3-digit warn code along with the reason phrase.

### `HttpHeaderAllow:10`

Lists the set of methods supported by the resource identified by the Request-URI.

### `HttpHeaderContentLength:11`

The size of the message body in decimal bytes.

### `HttpHeaderContentType:12`

The media type of the message body.

### `HttpHeaderContentEncoding:13`

The encoding scheme for the message body.

### `HttpHeaderContentLanguage:14`

Provides the natural language of the intended audience.

### `HttpHeaderContentLocation:15`

Location of the resource for the entity enclosed in the message when that entity is accessible from a location separate from the requested resource's URI.

### `HttpHeaderContentMd5:16`

An MD5 digest of the entity-body used to provide end-to-end message integrity check (MIC) of the entity-body.

### `HttpHeaderContentRange:17`

The content range header is sent with a partial entity body to specify where in the full entity body the partial body should be applied.

### `HttpHeaderExpires:18`

The date and time after which the message content expires.

### `HttpHeaderLastModified:19`

Indicates the date and time at which the origin server believes the variant was last modified.

### `HttpHeaderAccept:20`

Used with the INVITE, OPTIONS, and REGISTER methods to indicate what media types are acceptable in the response.

### `HttpHeaderAcceptCharset:21`

Indicates the character sets that are acceptable for the response.

### `HttpHeaderAcceptEncoding:22`

The content encodings that are acceptable in the response.

### `HttpHeaderAcceptLanguage:23`

Used by the client to indicate to the server which language it would prefer to receive reason phrases, session descriptions, or status responses.

### `HttpHeaderAuthorization:24`

The user-agent can authenticate itself with a server by sending the Authorization request header field with the request. The field contains the credentials for the domain that the user is requesting.

### `HttpHeaderCookie:25`

The cookie request header contains data used to maintain client state with the server. Cookie data is obtained from a response sent with **HttpHeaderSetCookie**.

### `HttpHeaderExpect:26`

Indicates the specific server behaviors that are required by the client.

### `HttpHeaderFrom:27`

The From header field specifies the initiator of the SIP request or response message.

### `HttpHeaderHost:28`

Specifies the Internet host and port number of the requested resource. This is obtained from the original URI given by the user or referring resource.

### `HttpHeaderIfMatch:29`

The If-Match request header field is used with a method to make it conditional. A client that has one or more entities previously obtained from the resource can verify that one of those entities is current by including a list of their associated entity tags in the If-Match header field.

### `HttpHeaderIfModifiedSince:30`

The If-Modified-Since request header field is used with a method to make it conditional. If the requested variant has not been modified since the time specified in this field, an entity is not returned from the server; instead, a 304 (not modified) response is returned without any message-body.

### `HttpHeaderIfNoneMatch:31`

The If-None-Match request-header field is used with a method to make
it conditional. When a client has obtained one or more entities from a resource, it can verify that none of those entities is
current by including a list of their associated entity tags in the
If-None-Match header field. The purpose of this feature is to allow
efficient updates of cached information with a minimum amount of
transaction overhead, and to prevent a method such as PUT
from inadvertently modifying an existing resource when the client
believes that the resource does not exist.

### `HttpHeaderIfRange:32`

If a client has a partial copy of an entity in its cache, and wishes
to obtain an up-to-date copy of the entire entity, it
can use the If-Range header. Informally, its meaning is, "if the entity is unchanged, send
me the part(s) I am missing; otherwise, send me the entire new
entity."

### `HttpHeaderIfUnmodifiedSince:33`

The If-Unmodified-Since request-header field is used with a method to
make it conditional. If the requested resource has not been modified
since the time specified in this field, the server performs the
requested operation as if the If-Unmodified-Since header were not
present, but

 if the requested resource has been modified,
the server returns
a 412 error (Precondition Failed).

### `HttpHeaderMaxForwards:34`

The maximum number of proxies or gateways that can forward the request.

### `HttpHeaderProxyAuthorization:35`

This header field is used by the client to identify itself with a proxy.

### `HttpHeaderReferer:36`

Allows the client to specify, for the server's benefit, the address (URI) of the resource from which the Request-URI was obtained.

### `HttpHeaderRange:37`

Allows a client to request a part of an entity instead of the whole.

### `HttpHeaderTe:38`

This header field contains the recipient of the SIP request or response message.

### `HttpHeaderTranslate:39`

Allows the client to specify whether it wants the source representation or programmatic interpretation of the requested content.

### `HttpHeaderUserAgent:40`

Indicates what extension transfer-codings the client accepts in the response and whether or not the client accepts trailer fields in a chunked transfer-coding.

### `HttpHeaderRequestMaximum:41`

Not a value that actually designates a header; instead, it is used to count the enumerated Request headers.

### `HttpHeaderAcceptRanges:20`

Allows the server to indicate its acceptance of range requests for a resource.

### `HttpHeaderAge:21`

Conveys the sender's estimate of the amount of time since the response (or its revalidation) was generated at the origin server.

### `HttpHeaderEtag:22`

Provides the current value of the entity tag for the requested variant.

### `HttpHeaderLocation:23`

Used to redirect the recipient to a location other than the Request-URI for completion of the request or identification of a new resource.

### `HttpHeaderProxyAuthenticate:24`

The response field that must be included as a part of the 407 response. The field includes the authentication scheme and parameters that apply to the proxy for this Request-URI.

### `HttpHeaderRetryAfter:25`

The length of time that the service is expected to be unavailable to the requesting client.

### `HttpHeaderServer:26`

This is a response header field that contains information about the server that is handling the request.

### `HttpHeaderSetCookie:27`

The **set-cookie** response header contains data used to maintain client state in future requests sent with **HttpHeaderCookie**.

### `HttpHeaderVary:28`

Indicates the set of request header fields that fully determines, while the response is fresh, whether a cache is permitted to use the response to reply to a subsequent request without revalidation.

### `HttpHeaderWwwAuthenticate:29`

The WWW_Authenticate header field contains the authentication schemes and parameters applicable to the Request-URI.

### `HttpHeaderResponseMaximum:30`

Not a value that actually designates a header; instead, it is used to count the enumerated Response headers.

### `HttpHeaderMaximum:41`

Not a value that actually designates a header; instead, it is used to count all the enumerated headers.

## See also

[HTTP_REQUEST_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_headers)

[HTTP_RESPONSE_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_headers)