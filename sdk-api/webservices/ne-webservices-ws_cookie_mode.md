# WS_COOKIE_MODE enumeration

## Description

An enumeration used to specify how to handle HTTP cookies.

## Constants

### `WS_MANUAL_COOKIE_MODE:1`

In this mode, cookies are not processed by the client channel.

If a server sends a cookie to the client, the client
channel will ignore the cookie (it will not include
the cookie value in subsequent requests).

An application can use the [WS_HTTP_HEADER_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_header_mapping) feature to handle cookies manually, if desired.

### `WS_AUTO_COOKIE_MODE:2`

In this mode, cookies are automatically tracked by
the channel.

If a server sends a cookie to the client,
the channel will automatically track the cookie and
will include the cookie in subsequent requests.