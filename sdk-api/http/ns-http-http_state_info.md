# HTTP_STATE_INFO structure

## Description

The **HTTP_STATE_INFO** structure is used to enable or disable a Server Session or URL Group.

This structure must be used when setting or querying the [HttpServerStateProperty](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) on a URL Group or Server Session.

## Members

### `Flags`

The [HTTP_PROPERTY_FLAGS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_property_flags) structure specifying whether the property is present.

### `State`

A member of the [HTTP_ENABLED_STATE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_enabled_state) enumeration specifying the whether the configuration object is enabled or disabled.

This can be used to disable a URL Group or Server Session.

## Remarks

When the **HttpServerStateProperty** is set on a server session or a URL group, the **HTTP_STATE_INFO** structure must be used. Server Sessions, and URL Groups represent a configuration for a part of the namespace where inheritance is involved. When traversing the namespace for a request, the HTTP Server API may encounter multiple applicable URL Groups. The property configuration structures must carry information identifying if it is present in a specific URL group.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property)

[HttpQueryRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryrequestqueueproperty)

[HttpQueryServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserversessionproperty)

[HttpQueryUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryurlgroupproperty)

[HttpSetRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestqueueproperty)

[HttpSetServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserversessionproperty)

[HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty)