## Description

The **HTTP_PROPERTY_FLAGS** structure is used by the property configuration structures to enable or disable a property on a configuration object when setting property configurations.

When the configuration structure is used to query property configurations, this structure specifies whether the property is present on the configuration object.

## Members

### `Present`

The **Present** flag enables or disables a property, or determines whether the property is present on the configuration object.

A value of zero indicates the property is not present; a positive value indicates the property is present.

## Remarks

The property configuration structures are used in calls to [HttpSetRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestqueueproperty), [HttpSetServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserversessionproperty), and [HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty) to set properties on the corresponding configuration objects. The configuration structures are also used in calls to [HttpQueryRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryrequestqueueproperty), [HttpQueryServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserversessionproperty), and [HttpQueryUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryurlgroupproperty), to query properties on the corresponding configuration object. When properties are set on the URL Group, server session, or request queue, this structure enables or disables the property. When properties are queried for the URL Group, server session, or request queue, this structure is used by the application to determine if the property is present. For more information, see the list of property configuration structures in the See Also section below.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_BANDWIDTH_LIMIT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_bandwidth_limit_info)

[HTTP_BINDING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_binding_info)

[HTTP_CONNECTION_LIMIT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_connection_limit_info)

[HTTP_LOGGING_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_logging_info)

[HTTP_SERVER_AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_server_authentication_info)

[HTTP_STATE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_state_info)

[HTTP_TIMEOUT_LIMIT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_timeout_limit_info)