# HTTP_CONNECTION_LIMIT_INFO structure

## Description

The **HTTP_CONNECTION_LIMIT_INFO** structure is used to set or query the limit on the maximum number of outstanding connections for a URL Group.

 This structure must be used when setting or querying the [HttpServerConnectionsProperty](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) on a URL Group.

## Members

### `Flags`

The [HTTP_PROPERTY_FLAGS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_property_flags) structure specifying whether the property is present.

### `MaxConnections`

The number of connections allowed. Setting this value to HTTP_LIMIT_INFINITE allows an unlimited number of connections.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property)

[HttpQueryUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryurlgroupproperty)

[HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty)