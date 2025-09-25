# WS_CHANNEL_BINDING enumeration

## Description

Indicates the protocol stack to use for the channel.

## Constants

### `WS_HTTP_CHANNEL_BINDING:0`

SOAP over HTTP.

### `WS_TCP_CHANNEL_BINDING:1`

SOAP over TCP.

### `WS_UDP_CHANNEL_BINDING:2`

SOAP over UDP.

### `WS_CUSTOM_CHANNEL_BINDING:3`

A custom channel or listen implementation. For more information, see [WS_CUSTOM_CHANNEL_CALLBACKS](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_custom_channel_callbacks) and [WS_CUSTOM_LISTENER_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_custom_listener_callbacks).

### `WS_NAMEDPIPE_CHANNEL_BINDING:4`

Windows 8 or later:
SOAP over named pipes.