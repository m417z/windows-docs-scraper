# HTTP_BINDING_INFO structure

## Description

The **HTTP_BINDING_INFO** structure is used to associate a URL Group with a request queue.

This structure must be used when setting or querying the [HttpServerBindingProperty](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) on a URL Group.

## Members

### `Flags`

The [HTTP_PROPERTY_FLAGS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_property_flags) structure specifying whether the property is present.

### `RequestQueueHandle`

The request queue that is associated with the URL group. The structure can be used to remove an existing binding by setting this parameter to **NULL**.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property)

[HttpQueryUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryurlgroupproperty)

[HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty)