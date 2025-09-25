# HTTP_TIMEOUT_LIMIT_INFO structure

## Description

The **HTTP_TIMEOUT_LIMIT_INFO** structure defines the application-specific connection timeout limits.

This structure must be used when setting or querying the [HttpServerTimeoutsProperty](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property) on a URL Group, server session, or request queue.

## Members

### `Flags`

The [HTTP_PROPERTY_FLAGS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_property_flags) structure that specifies whether the property is present.

### `EntityBody`

The time, in seconds, allowed for the request entity body to arrive.

 The HTTP Server API turns on this timer when the request has an entity body. The timer expiration is initially set to the configured value. When the HTTP Server API receives additional data indications on the request, it resets the timer to give the connection another interval.

### `DrainEntityBody`

The time, in seconds, allowed for the HTTP Server API to drain the entity body on a Keep-Alive connection.

On a Keep-Alive connection, after the application has sent a response for a request and before the request entity body has completely arrived, the HTTP Server API starts draining the remainder of the entity body to reach another potentially pipelined request from the client. If the time to drain the remaining entity body exceeds the allowed period the connection is timed out.

### `RequestQueue`

The time, in seconds, allowed for the request to remain in the request queue before the application picks it up.

### `IdleConnection`

The time, in seconds, allowed for an idle connection.

This timeout is only enforced after the first request on the connection is routed to the application. For more information, see the Remarks section.

### `HeaderWait`

The time, in seconds, allowed for the HTTP Server API to parse the request header.

This timeout is only enforced after the first request on the connection is routed to the application. For more information, see the Remarks section.

### `MinSendRate`

The minimum send rate, in bytes-per-second, for the response. The default response send rate is 150 bytes-per-second.

To disable this timer, set **MinSendRate** to **MAXULONG**.

## Remarks

This structure is used in the [HttpQueryServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserversessionproperty), and [HttpSetServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserversessionproperty) functions to set or query the connection timeouts. The following table lists the default timeouts.

| Timer | HTTP Server API Default | HTTP Server API Wide Configuration | Application Specific Configuration |
| --- | --- | --- | --- |
| EntityBody | 2 Minutes | No | Yes |
| DrainEntityBody | 2 Minutes | No | Yes |
| RequestQueue | 2 Minutes | No | Yes |
| IdleConnection | 2 Minutes | Yes | Limited |
| HeaderWait | 2 Minutes | Yes | Limited |
| MinSendRate | 150 bytes/second | No | Yes |

Calling [HttpSetServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserversessionproperty) or [HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty) to configure a connection timeout affects only the calling application and does not set driver wide timeout limits. The idle connection and header wait timers can be configured for all HTTP applications by calling [HttpSetServiceConfiguration](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserviceconfiguration). Administrative privileges are required to configure HTTP Server API wide timeouts. HTTP Server API wide configurations affect all HTTP applications on the computer and persist when the computer is shut down.

The application-specific **IdleConnection** and **HeaderWait** timers are set on a limited basis. The HTTP Server API cannot determine the request queue or URL group that the request is associated with until the headers have been parsed. Therefore, the HTTP Server API enforces the default **IdleConnection** and **HeaderWait** timers for the first request on a connection. Subsequent requests on a Keep-Alive connection will use the application specific timeouts.

Setting a timeout on a server session affects all the URL Groups under the server session. However, if the URL Group has configured a timeout, the setting for the URL Group takes precedence over the server session configuration.

Setting a timeout to zero on a server session causes the HTTP Server API to revert to the default value for that timer. For timers set on a URL Group, the server session timeout is used if present, otherwise the HTTP Server API default is used.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_SERVER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_server_property)

[HttpQueryRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryrequestqueueproperty)

[HttpQueryServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryserversessionproperty)

[HttpQueryUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpqueryurlgroupproperty)

[HttpSetRequestQueueProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestqueueproperty)

[HttpSetServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserversessionproperty)

[HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty)