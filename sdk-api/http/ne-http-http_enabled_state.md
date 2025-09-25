# HTTP_ENABLED_STATE enumeration

## Description

The **HTTP_ENABLED_STATE** enumeration defines the state of a request queue, server session, or URL Group.

This enumeration is used in the [HTTP_STATE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_state_info) struct

## Constants

### `HttpEnabledStateActive`

The HTTP Server API object is enabled.

### `HttpEnabledStateInactive`

The HTTP Server API object is disabled.

## Remarks

 The default state of a request queue is enabled. Typically this enumeration is used to temporarily disable a request queue.

## See also

[HTTP Server API Version 2.0 Enumeration Types](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-enumeration-types)

[HTTP_STATE_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_state_info)