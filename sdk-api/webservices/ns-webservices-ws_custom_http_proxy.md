# WS_CUSTOM_HTTP_PROXY structure

## Description

A structure that is used to specify the custom proxy for the channel, using
the [WS_CHANNEL_PROPERTY_CUSTOM_HTTP_PROXY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id).

## Members

### `servers`

A semicolon-separated list of the proxy servers to be used by the channel. Each
entry must follow the following EBNF.

``` syntax
<server>[":"<port>]
```

* server=Address of the server
* port=TCP port number

### `bypass`

A semicolon separated list of servers which must be bypassed by the proxy.
The bypass list can contain the string <local> to indicate that
all local machine servers are bypassed.