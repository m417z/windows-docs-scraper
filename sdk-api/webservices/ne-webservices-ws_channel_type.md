# WS_CHANNEL_TYPE enumeration

## Description

Indicates the basic characteristics of the channel, such as whether it is
sessionful, and what directions of communication are supported.

## Constants

### `WS_CHANNEL_TYPE_INPUT:0x1`

Input channels support Receive operations. They are used on the sender side.

The [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) supports this channel type
when used with [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener).

### `WS_CHANNEL_TYPE_OUTPUT:0x2`

Output channels support Send operations.

This channel type is not currently supported by any channel bindings.

### `WS_CHANNEL_TYPE_SESSION:0x4`

Sessionful channels provide channel-level correlation of all messages sent or received.

This is a flag used to build [WS_CHANNEL_TYPE_INPUT_SESSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type),
**WS_CHANNEL_TYPE_OUTPUT_SESSION**, and **WS_CHANNEL_TYPE_DUPLEX_SESSION**,
but cannot be used alone.

### `WS_CHANNEL_TYPE_INPUT_SESSION`

An input channel that supports a session.

This channel type is not currently supported by any channel bindings.

### `WS_CHANNEL_TYPE_OUTPUT_SESSION`

An output channel that supports a session.

This channel type is not currently supported by any channel bindings.

### `WS_CHANNEL_TYPE_DUPLEX`

An input/output channel.

The [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) supports this channel type
when used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel).

### `WS_CHANNEL_TYPE_DUPLEX_SESSION`

An input/output channel that supports a session.

The [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) supports this channel type when
used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener).

### `WS_CHANNEL_TYPE_REQUEST:0x8`

Request channels support Send followed by Receive. They are used on the client
side for channels that support request-reply operations.

The [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) supports this channel type when
used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel).

Note that request channels provide built-in correlation of request replies.
It is possible to do request-reply correlation on other channel types using the
addressing headers (RelatesTo and MessageID).

### `WS_CHANNEL_TYPE_REPLY:0x10`

Reply channels support Receive followed by Send. They are used on the service
side for channels that support request-reply operations (for example, HTTP).

The [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) supports this channel type when
used with [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener).

Note that reply channels provide built-in correlation of request replies.
It is possible to do request-reply correlation on other channel types using the
addressing headers (RelatesTo and MessageID).