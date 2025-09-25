# HTTP_BANDWIDTH_LIMIT_INFO structure

## Description

The **HTTP_BANDWIDTH_LIMIT_INFO** structure is used to set or query the bandwidth throttling limit.

This structure must be used when setting or querying the [HttpServerBandwidthProperty](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) on a URL Group or server session.

## Members

### `Flags`

The [HTTP_PROPERTY_FLAGS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_property_flags) structure specifying whether the property is present.

### `MaxBandwidth`

The maximum allowed bandwidth rate in bytesper second. Setting the value to HTTP_LIMIT_INFINITE allows unlimited bandwidth rate. The value cannot be smaller than HTTP_MIN_ALLOWED_BANDWIDTH_THROTTLING_RATE.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property)

[HttpQueryServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserversessionproperty)

[HttpQueryUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryurlgroupproperty)

[HttpSetServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserversessionproperty)

[HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty)