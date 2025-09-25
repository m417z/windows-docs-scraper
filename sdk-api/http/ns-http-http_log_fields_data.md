# HTTP_LOG_FIELDS_DATA structure

## Description

The **HTTP_LOG_FIELDS_DATA** structure is used to pass the fields that are logged for an HTTP response when WC3 logging is enabled.

## Members

### `Base`

Initialize this member to the **HttpLogDataTypeFields** value of the [HTTP_LOG_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_log_data_type) enumeration.

### `UserNameLength`

The size, in bytes, of the user name member.

### `UriStemLength`

The size, in bytes, of the URI stem member.

### `ClientIpLength`

The size, in bytes, of the client IP address member.

### `ServerNameLength`

The size, in bytes, of the server name member.

### `ServiceNameLength`

### `ServerIpLength`

The size, in bytes, of the server IP address member.

### `MethodLength`

The size, in bytes, of the HTTP method member.

### `UriQueryLength`

The size, in bytes, of the URI query member.

### `HostLength`

The size, in bytes, of the host name member.

### `UserAgentLength`

The size, in bytes, of the user agent member.

### `CookieLength`

The size, in bytes, of the cookie member.

### `ReferrerLength`

The size, in bytes, of the referrer member.

### `UserName`

The name of the user.

### `UriStem`

The URI stem.

### `ClientIp`

The IP address of the client.

### `ServerName`

The name of the server.

### `ServiceName`

The name of the service.

### `ServerIp`

The IP address of the server.

### `Method`

The HTTP method.

### `UriQuery`

The URI query.

### `Host`

The host information from the request.

### `UserAgent`

The user agent name.

### `Cookie`

The cookie provided by the application.

### `Referrer`

The referrer.

### `ServerPort`

The port for the server.

### `ProtocolStatus`

The protocol status.

### `Win32Status`

The win32 status.

### `MethodNum`

The method number.

### `SubStatus`

The sub status.

## Remarks

The **HTTP_LOG_FIELDS_DATA** structure is an optional parameter (pLogData) in the [HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody) and [HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse) functions starting with the HTTP version 2.0 API. The **HTTP_LOG_FIELDS_DATA** structure specifies which fields are logged in the response.

Unless this structure is passed, the response will not be logged, even when the server logging property is set on a URL group or a server session. Requests will not be logged unless the application passes the **HTTP_LOG_FIELDS_DATA** structure with each response and the logging property is set on the server session or URL Group. Most of the fields in the **HTTP_LOG_FIELDS_DATA** structure can be initialized from the corresponding field in the [HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure, however, some of the log fields are only known to the application; for example, Win32Status and SubStatus. This structure enables applications to alter the fields that are logged. The application passes a **NULL** pointer and a zero length for the corresponding member to disable logging for that field.

 Applications must provide the **HTTP_LOG_FIELDS_DATA** structure with the last send call. If a response is sent with a single call to [HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse), the log data must be provided in this call. If the response is sent over multiple send calls, the data must be provided with the last call to [HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody).

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_RESPONSE_V1](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_v1)

[HTTP_RESPONSE_V2](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_v2)

[HttpSendHttpResponse](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendhttpresponse)

[HttpSendResponseEntityBody](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsendresponseentitybody)