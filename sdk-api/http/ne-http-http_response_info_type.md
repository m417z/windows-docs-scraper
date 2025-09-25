## Description

The **HTTP_RESPONSE_INFO_TYPE** enumeration defines the type of information contained in the [HTTP_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_info) structure.

This enumeration is used in the [HTTP_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_info) structure.

## Constants

### `HttpResponseInfoTypeMultipleKnownHeaders`

The response information type is authentication.

The **pInfo** member of the [HTTP_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_info) structure points to a [HTTP_MULTIPLE_KNOWN_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_multiple_known_headers) structure.

### `HttpResponseInfoTypeAuthenticationProperty`

Reserved for future use.

### `HttpResponseInfoTypeQoSProperty`

Pointer to an [HTTP_QOS_SETTING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_qos_setting_info) structure that contains information about a QOS setting.

### `HttpResponseInfoTypeChannelBind`

Pointer to an [HTTP_CHANNEL_BIND_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_channel_bind_info) structure that contains information on the channel binding token.

## See also

[HTTP Server API Version 2.0 Enumeration Types](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-enumeration-types)

[HTTP_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_info)