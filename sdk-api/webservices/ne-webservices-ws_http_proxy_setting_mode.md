# WS_HTTP_PROXY_SETTING_MODE enumeration

## Description

Proxy setting indicates HTTP proxy setting for the channel with binding [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).
This is specified as part of [WS_CHANNEL_PROPERTY_HTTP_PROXY_SETTING_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) channel property.

## Constants

### `WS_HTTP_PROXY_SETTING_MODE_AUTO:0x1`

The channel will automatically detect the proxy setting based on the IE configuration for the
user at the point the channel is opened. This is the default setting for the [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

### `WS_HTTP_PROXY_SETTING_MODE_NONE:0x2`

No proxy will be used to service the request on the channel.

### `WS_HTTP_PROXY_SETTING_MODE_CUSTOM:0x3`

If an application chooses to explicitly control the HTTP proxy it can use this setting.
The [WS_CHANNEL_PROPERTY_CUSTOM_HTTP_PROXY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) property specifies the custom proxy to be used
with the channel and must be set on the channel if this setting is used.