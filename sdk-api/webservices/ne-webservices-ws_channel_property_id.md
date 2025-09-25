# WS_CHANNEL_PROPERTY_ID enumeration

## Description

Each channel property is identified by an ID and has an associated
value. If a property is not specified when the channel is created,
then its default value is used.

## Constants

### `WS_CHANNEL_PROPERTY_MAX_BUFFERED_MESSAGE_SIZE:0`

A **ULONG**
used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) or
[WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding),
**WS_HTTP_CHANNEL_BINDING**, or **WS_NAMEDPIPE_CHANNEL_BINDING**. This value is a limit as to how big of a
message may be received or sent by the channel. The limit specifies the maximum size
of the envelope in bytes as it appears in its encoded wire form.
The minimum value is 1.

This property limits the amount of memory
that the channel will allocate in order to receive or send a buffered message.
When receiving with buffered input, the entire message is read into a
buffer before the application has access to it. When sending with buffered output,
the entire message is accumulated in a buffer before being sent.

This property may only be specified when buffered input or output has been
specified (either [WS_STREAMED_INPUT_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode) or
**WS_STREAMED_OUTPUT_TRANSFER_MODE** have not been set).

The default value is 65536.

The [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) always uses the value 65536.

### `WS_CHANNEL_PROPERTY_MAX_STREAMED_MESSAGE_SIZE:1`

An **unsigned __int64** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) or
[WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty)
[WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding). This
value is a limit as to how big of a streamed message may be received or sent
for the channel.
The limit specifies the maximum size of the envelope in bytes as it appears
in its encoded wire form. The minimum value is 1.

This property may only be specified when streamed input or output has been selected
([WS_STREAMED_INPUT_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode) or **WS_STREAMED_OUTPUT_TRANSFER_MODE** has been set).

The default value is 4194304.

### `WS_CHANNEL_PROPERTY_MAX_STREAMED_START_SIZE:2`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) or
[WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).
This value is a limit as to how big the start of a message may be.
The start of a message consists of the envelope tag, the headers, and the body tag.
The limit specifies the maximum size of the data in bytes as it appears in
its encoded wire form. The minimum value is 1.

This property may only be specified when streamed input has been selected
([WS_STREAMED_INPUT_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode)).

This property limits the amount of memory that the channel will allocate
in order to read the start of the message. For streaming input, the
entire start of the message will be read into a buffer before the application
is notified that the start of the message has been read.

The default value is 16384.

### `WS_CHANNEL_PROPERTY_MAX_STREAMED_FLUSH_SIZE:3`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) or
[WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).
This value is a limit as to how many bytes will be accumulated
before [WsFlushBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsflushbody) is called.

This property may only be specified when streamed output has been selected
([WS_STREAMED_OUTPUT_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode)).

This property limits the amount of memory that the channel will allocate
in order to accumulated buffered data. For streaming output, the
channel will accumulate data in a buffer until [WsFlushBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsflushbody) is called.

The default value is 65536.

### `WS_CHANNEL_PROPERTY_ENCODING:4`

A [WS_ENCODING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_encoding) value
used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) or **WS_HTTP_CHANNEL_BINDING**.
This value specifies what encoding to use for the channel.

The default value depends on the binding:

* [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) uses [WS_ENCODING_XML_UTF8](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_encoding).
* [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) uses [WS_ENCODING_XML_BINARY_SESSION_1](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_encoding).
* [WS_NAMEDPIPE_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) uses [WS_ENCODING_XML_BINARY_SESSION_1](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_encoding).

The [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) always uses the value [WS_ENCODING_XML_UTF8](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_encoding).

### `WS_CHANNEL_PROPERTY_ENVELOPE_VERSION:5`

A [WS_ENVELOPE_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version) value
used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty).
This value specifies what envelope version to use for the channel. The
envelope version of the channel must match that of the message used with
the channel.

This property is not supported with the [WS_NAMEDPIPE_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding). Named Pipe channels always use [WS_ENVELOPE_VERSION_SOAP_1_2](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version).

The default value depends on the binding:

* [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) uses [WS_ENVELOPE_VERSION_NONE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version) when
  the **WS_CHANNEL_PROPERTY_ENCODING** is [WS_ENCODING_RAW](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_encoding), and
  **WS_ENVELOPE_VERSION_SOAP_1_2** for other encodings.
* [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) uses [WS_ENVELOPE_VERSION_SOAP_1_2](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version).
* [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) uses [WS_ENVELOPE_VERSION_SOAP_1_2](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version).

### `WS_CHANNEL_PROPERTY_ADDRESSING_VERSION:6`

A [WS_ADDRESSING_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version) value
used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty).
This value specifies what addressing version to use for the channel. The
addressing version of the channel must match that of the message used with
the channel.

The default value depends on the binding:

* [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) uses [WS_ADDRESSING_VERSION_TRANSPORT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version) when
  the **WS_CHANNEL_PROPERTY_ENCODING** is [WS_ENCODING_RAW](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_encoding), and
  **WS_ADDRESSING_VERSION_1_0** for other encodings.
* [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) uses [WS_ADDRESSING_VERSION_1_0](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version).
* [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) uses [WS_ADDRESSING_VERSION_1_0](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version).
* [WS_NAMEDPIPE_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) uses [WS_ADDRESSING_VERSION_1_0](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version).

The [WS_ADDRESSING_VERSION_TRANSPORT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version) is only supported for
[WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

### `WS_CHANNEL_PROPERTY_MAX_SESSION_DICTIONARY_SIZE:7`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty).
This property is only valid for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) or **WS_NAMEDPIPE_CHANNEL_BINDING**.
This value specifies the quota for number of bytes of session dictionary
strings that will be transmitted or received when using a session-based encoding.

The only session-based encoding supported currently is
[WS_ENCODING_XML_BINARY_SESSION_1](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_encoding), which is the default encoding
for the [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

If the quota is reached on the receiving side, then the channel
will fault.

If the quota is reached on the sending side, then the channel will simply
transmit the string without using the session dictionary.

This value is ignored if not using a session-based encoding.

The default value is 2048.

### `WS_CHANNEL_PROPERTY_STATE:8`

A [WS_CHANNEL_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state) value
returned by [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty).

The returned value is a snapshot of the current state, so it is
possible that the state may have changed before the caller has
had a chance to examine the value.

### `WS_CHANNEL_PROPERTY_ASYNC_CALLBACK_MODEL:9`

A [WS_CALLBACK_MODEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_callback_model) value used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty).
This value indicates the preferred async callback model when issuing
async operations for the channel.

If using [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) see
[WS_LISTENER_PROPERTY_ASYNC_CALLBACK_MODEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id).

The default is [WS_LONG_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_callback_model).

Both the [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host) and [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) only support [WS_LONG_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_callback_model)
as an acceptable value for this property.

### `WS_CHANNEL_PROPERTY_IP_VERSION:10`

A [WS_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_ip_version) value
used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) or **WS_UDP_CHANNEL_BINDING**.
This property specifies which IP version that the channel should use to
communicate with the remote endpoint.

To specify the IP version to use for channels that are accepted, use the
[WS_LISTENER_PROPERTY_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id) listener property when
creating the listener object.

The default value is [WS_IP_VERSION_AUTO](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_ip_version).

### `WS_CHANNEL_PROPERTY_RESOLVE_TIMEOUT:11`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty),
or **WsSetChannelProperty** for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) and [WS_CHANNEL_TYPE_REQUEST](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type).
This timeout limits the amount of time that will be spent resolving
the DNS name. The timeout value is in milliseconds,
where the value INFINITE indicates no timeout.

This property can be set in any channel state.

The default value is INFINITE.

### `WS_CHANNEL_PROPERTY_CONNECT_TIMEOUT:12`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel),
[WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty), or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty)
for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) or **WS_NAMEDPIPE_CHANNEL_BINDING** on the client side.
This timeout limits the amount of time that will be spent to connect to the remote machine and complete the net.tcp or net.pipe handshake. The timeout value
is in milliseconds, where the value INFINITE indicates no timeout. To set
or get the corresponding timeout on the server side, use
([WS_LISTENER_PROPERTY_CONNECT_TIMEOUT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id)).

Used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel),
[WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty), or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) and [WS_CHANNEL_TYPE_REQUEST](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type).
This timeout limits the amount of time that will be spent to connect
to the HTTP server. The timeout value is in milliseconds,
where the value INFINITE indicates no timeout.

This property can be set in any channel state.

The default value is 30000 (30 seconds).

The [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) sets this timeout to INFINITE by default.

### `WS_CHANNEL_PROPERTY_SEND_TIMEOUT:13`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener),
[WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty), or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty)
for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) or **WS_NAMEDPIPE_CHANNEL_BINDING**. This timeout limits the
amount of time that will be spent sending the bytes of the message.
The timeout value is in milliseconds, where the value INFINITE indicates
no timeout.

Used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty),
or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding)
and [WS_CHANNEL_TYPE_REQUEST](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type).
This timeout limits the amount of time that will be spent sending the
HTTP headers and the bytes of the message. The timeout value is in milliseconds, where the
value INFINITE indicates no timeout.

This property can be set in any channel state.

The default value is 30000 (30 seconds).

Both [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host) and [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) set this
timeout to INFINITE by default.

### `WS_CHANNEL_PROPERTY_RECEIVE_RESPONSE_TIMEOUT:14`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty),
or **WsSetChannelProperty** for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) and [WS_CHANNEL_TYPE_REQUEST](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type).
This timeout limits the amount of time that will be spent waiting for
all the response headers to be received from the server.
The timeout value is in milliseconds, where the value INFINITE indicates no timeout.

This property can be set in any channel state.

The default value is 30000 (30 seconds).

The [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) sets this timeout to INFINITE.

### `WS_CHANNEL_PROPERTY_RECEIVE_TIMEOUT:15`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener),
[WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty), or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty),
for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) or **WS_NAMEDPIPE_CHANNEL_BINDING**.
This timeout limits the amount of time that will be spent receiving the
the bytes of the message.
The timeout value is in milliseconds, where the value INFINITE indicates
no timeout.

Used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty),
or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) and [WS_CHANNEL_TYPE_REQUEST](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type).
This timeout limits the amount of time that will be spent receiving the
bytes of the message. The timeout value is in milliseconds,
where the value INFINITE indicates no timeout.
This timeout can be triggered by [WsWriteMessageEnd](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritemessageend), [WsReadMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessagestart), and [WsReadMessageEnd](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessageend).

This property can be set in any channel state.

The default value is 30000 (30 seconds).

Both [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host) and [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) set this
timeout to INFINITE by default.

### `WS_CHANNEL_PROPERTY_CLOSE_TIMEOUT:16`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener)
[WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty), or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty)
for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) or **WS_NAMEDPIPE_CHANNEL_BINDING**.
This timeout limits the amount of time that will be spent completing the
the close net.tcp or net.pipe handshake. The timeout value is in milliseconds, where the
value INFINITE indicates no timeout.

This property can be set in any channel state.

The default value is 30000 (30 seconds).

The [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) sets this timeout to INFINITE by default.

### `WS_CHANNEL_PROPERTY_ENABLE_TIMEOUTS:17`

A **BOOL** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding), **WS_TCP_CHANNEL_BINDING**, **WS_NAMEDPIPE_CHANNEL_BINDING**,
and **WS_UDP_CHANNEL_BINDING**.
Used with [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for **WS_CUSTOM_CHANNEL_BINDING**.

When this property is set to **TRUE** or not supplied when calling [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel),
more specific channel timeout properties (e.g. **WS_CHANNEL_PROPERTY_SEND_TIMEOUT**)
takes precedence and behaves as documented. When this property is set to **FALSE**,
all specific channel timeout properties are set to INFINITE unless they are explicitly specified.

This property can be queried from a custom channel using [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty),
see [WS_GET_CHANNEL_PROPERTY_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_get_channel_property_callback) for more details.

The default value is **TRUE**.

In order to implement their own timeout logic, [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) and
[WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host) sets this property to **FALSE** for the
standard channels bindings and require custom channels to support it by querying and
verifying that it is set to **FALSE**.
More specific timeout properties can still be provided as described above.

### `WS_CHANNEL_PROPERTY_TRANSFER_MODE:18`

A [WS_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode) value
used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel)
for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) to control whether messages
sent and received on the channel are buffered or streamed. The client
and server may use different transfer modes and still be able to communicate.

All channels support [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for this
property.

For channel bindings other than [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding)the value is always [WS_BUFFERED_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode).

The default property value is [WS_BUFFERED_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode). Note,
only **WS_BUFFERED_TRANSFER_MODE** is used by Service Model for both
[WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) and [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host). The only exception
is around using message contracts on WS_SERVICE_HOST, where
**WS_STREAMED_OUTPUT_TRANSFER_MODE** is allowed.

[WS_STREAMED_OUTPUT_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode) with [WS_CHANNEL_TYPE_REQUEST](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type) requires Windows Vista and above, and supports only **WS_HTTP_HEADER_AUTH_SCHEME_BASIC** when used with security.

### `WS_CHANNEL_PROPERTY_MULTICAST_INTERFACE:19`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty),
or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding)
with [WS_CHANNEL_TYPE_DUPLEX](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type) to indicate which adapter
should be used when sending to a multicast address.

The value is the interface index of the adapter.

If this property is not set, or is 0, then the default adapter for the
machine is used. This may not be appropriate for machines with multiple adapters.

This property can be set in any channel state.

The default property value is 0.

### `WS_CHANNEL_PROPERTY_MULTICAST_HOPS:20`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty)
for [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) with [WS_CHANNEL_TYPE_DUPLEX](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type)
to specify the max number of hops that a UDP message can travel.

The default property value is 1.

### `WS_CHANNEL_PROPERTY_REMOTE_ADDRESS:21`

A [WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address) structure
used with [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty)
for [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) with [WS_CHANNEL_TYPE_DUPLEX](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type)
to retrieve the endpoint address of the remote party for the channel.

The fields of the returned
[WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address) structure are valid and constant until the channel
is reset or freed. The caller should not modify the values the returned
fields of the **WS_ENDPOINT_ADDRESS** point to.

This property cannot be retrieved until the channel has reached the open state.

This property is based on the source IP address that is received from
the network, which may be spoofed or tampered with even if using a
secure channel (depending on the network environment).

### `WS_CHANNEL_PROPERTY_REMOTE_IP_ADDRESS:22`

A [SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85)) structure
used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel)
for the following types of channels to retrieve the IP address
of the remote party:

* [WS_CHANNEL_TYPE_DUPLEX_SESSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type)
* [WS_CHANNEL_TYPE_DUPLEX](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type)
* [WS_CHANNEL_TYPE_REPLY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type)

This property cannot be retrieved until the channel has begun reading a message.

This property is based on the source IP address that is received from
the network, which may be spoofed or tampered with even if using a
secure channel (depending on the network environment).

### `WS_CHANNEL_PROPERTY_HTTP_CONNECTION_ID:23`

A pointer to a **ULONGLONG** used with [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty)
for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) with [WS_CHANNEL_TYPE_REPLY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type)
to retrieve an identifier that uniquely identifies the client connection.

This property cannot be retrieved until the channel has begun reading a message.

The connection ID uniquely identifies a connection while the
listener object that the channel was accepted from remains open.

A given reply channel instance is in no way correlated with a connection.
Each time the channel is accepted, there may be a different connection ID
(even if the total set of connections has not changed since the last accept).

The connection ID can be used by an application to correlate state with
a HTTP connection.

### `WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_CALLBACKS:24`

A [WS_CUSTOM_CHANNEL_CALLBACKS](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_custom_channel_callbacks) structure used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) for [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

This property is used to specify callbacks that
define the implementation of a custom channel.

This property must be specified when [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) is used.

### `WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_PARAMETERS:25`

A pointer to an arbitrary sized data type used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) for [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

This property is used to specify parameters used to create the custom
channel implementation.

The size of the property is the size of the data type.

The value of this property will be passed to the
[WS_CREATE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_channel_callback).

If this property is not specified, its value is **NULL** and size is zero.

### `WS_CHANNEL_PROPERTY_CUSTOM_CHANNEL_INSTANCE:26`

A **void *** used with [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

The size of the property is **sizeof(void*)**.
The value corresponds to the channel instance value returned by
the [WS_CREATE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_channel_callback).

This property can be used to obtain the underlying channel
instance for a custom channel. This allows a caller to directly
interact with the instance for cases when the existing
set of channel properties or channel functions is insufficient.

### `WS_CHANNEL_PROPERTY_TRANSPORT_URL:27`

A [WS_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string) structure
used with [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty)
for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) or **WS_TCP_CHANNEL_BINDING** for channels created with [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener).

This property is used on the server to obtain the URL that was passed
to [WsOpenChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenchannel) on the client.
This URL may be different than the value in the [WS_TO_HEADER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type)
if [WsAddressMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsaddressmessage) was used. The mapping of the
transport URL to the underlying transport varies by the
[WS_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding), as follows:

* [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding). The transport URL is
  the request URL.
* [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding). The transport URL is
  the URL that is present at the .NET framing layer.

This property is only available once the channel has
been accepted using [WsAcceptChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsacceptchannel).

The caller should pass the address of a [WS_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string) when
retrieving this property. The returned string is a fully qualified
URL in encoded form. The returned string is good until the channel
is freed or reset.

### `WS_CHANNEL_PROPERTY_NO_DELAY:28`

A **BOOL** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) or [WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

This property controls the TCP_NODELAY socket option value of the underlying socket.

When this value is **FALSE**, the Nagle algorithm is used which can
improve throughput by coalescing small messages.

Setting this value to **TRUE** may decrease latency at the cost of throughput
for small messages.

The default value is **FALSE**.

### `WS_CHANNEL_PROPERTY_SEND_KEEP_ALIVES:29`

A **BOOL** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

This property controls the SO_KEEPALIVE socket option value of the underlying socket.

Setting this value to **TRUE** will cause keep-alive packets to be sent
on the underlying socket, which may help detect when
a remote party is no longer available.

The default value is **FALSE**.

### `WS_CHANNEL_PROPERTY_KEEP_ALIVE_TIME:30`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

This property is measured in milliseconds.

This property may only be specified when the **WS_CHANNEL_PROPERTY_SEND_KEEP_ALIVES** property has the value of **TRUE**.

The value represents the amount of time before sending keep alive packets if the
socket is not in use.

The default value is 2 hours.

### `WS_CHANNEL_PROPERTY_KEEP_ALIVE_INTERVAL:31`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

This property is measured in milliseconds.

This property may only be specified when the **WS_CHANNEL_PROPERTY_SEND_KEEP_ALIVES** property has the value of **TRUE**.

After the time specified in **WS_CHANNEL_PROPERTY_KEEP_ALIVE_TIME** has expired,
the system will begin to send keep alive packets in an attempt to contact
the remote party. This setting controls how often the system will send
another packet (as a retry attempt).

The default value is 1 second.

### `WS_CHANNEL_PROPERTY_MAX_HTTP_SERVER_CONNECTIONS:32`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

This property specifies the maximum number of connections that a client application
may have against a HTTP server.
Connections may be cached and re-used by other components within the same process accessing the same HTTP server.

The default value is INFINITE (no limit).

### `WS_CHANNEL_PROPERTY_IS_SESSION_SHUT_DOWN:33`

A **BOOL** used with [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding)
or **WS_NAMEDPIPE_CHANNEL_BINDING** with [WS_CHANNEL_TYPE_DUPLEX_SESSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type).

This property indicates
whether [WsShutdownSessionChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsshutdownsessionchannel) has been
used to shut down the channel.

The channel must be in [WS_CHANNEL_STATE_OPEN](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state) or
**WS_CHANNEL_STATE_FAULTED** state.

### `WS_CHANNEL_PROPERTY_CHANNEL_TYPE:34`

A [WS_CHANNEL_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type) value
used with [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for all channel types
to query the type of the channel.

The channel can be in any [WS_CHANNEL_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state).

### `WS_CHANNEL_PROPERTY_TRIM_BUFFERED_MESSAGE_SIZE:35`

A **ULONG** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) or
[WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding),
**WS_HTTP_CHANNEL_BINDING**, or **WS_NAMEDPIPE_CHANNEL_BINDING** to control the memory allocation
characteristics for the messages on the channel.

This property specifies the maximum amount of memory the channel will keep
around after a message is [reset](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetmessage). If all the
messages a channel sees are all smaller than this size, then allocations
for purposes of buffering the messages will be minimized.

This property may only be specified when buffered input or output has been
specified (either [WS_STREAMED_INPUT_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode) or
**WS_STREAMED_OUTPUT_TRANSFER_MODE** have not been set).

The default value is 65536.

The [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) always uses the value 65536.

### `WS_CHANNEL_PROPERTY_ENCODER:36`

A [WS_CHANNEL_ENCODER](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_channel_encoder) structure used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding),
**WS_HTTP_CHANNEL_BINDING**, or **WS_NAMEDPIPE_CHANNEL_BINDING** to provide a custom encoding of messages.

This property cannot be used with [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

### `WS_CHANNEL_PROPERTY_DECODER:37`

A [WS_CHANNEL_DECODER](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_channel_decoder) structure used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding),
**WS_HTTP_CHANNEL_BINDING**, or **WS_NAMEDPIPE_CHANNEL_BINDING** to provide a custom dencoding of messages.

This property cannot be used with [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

### `WS_CHANNEL_PROPERTY_PROTECTION_LEVEL:38`

A [WS_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_protection_level) value used with [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for any channel type.

This property indicates
the security assurances provided by the channel.

The value of this property depends on the security requirements
requested for the channel.

### `WS_CHANNEL_PROPERTY_COOKIE_MODE:39`

A [WS_COOKIE_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_cookie_mode) value used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) with [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) to control how HTTP cookies are handled.

The default value is [WS_AUTO_COOKIE_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_cookie_mode).

### `WS_CHANNEL_PROPERTY_HTTP_PROXY_SETTING_MODE:40`

A [WS_HTTP_PROXY_SETTING_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_http_proxy_setting_mode) value used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) with [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) to control the HTTP proxy settings for the channel.

The default value is [WS_HTTP_PROXY_SETTING_MODE_AUTO](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_http_proxy_setting_mode).

### `WS_CHANNEL_PROPERTY_CUSTOM_HTTP_PROXY:41`

A [WS_CUSTOM_HTTP_PROXY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_custom_http_proxy) structure used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) with [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) to specify the custom custom setting for the HTTP channel. This property must
be specified when **WS_CHANNEL_PROPERTY_HTTP_PROXY_SETTING_MODE** is set to
[WS_HTTP_PROXY_SETTING_MODE_CUSTOM](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_http_proxy_setting_mode).

The default value is **NULL**.

### `WS_CHANNEL_PROPERTY_HTTP_MESSAGE_MAPPING:42`

A [WS_HTTP_MESSAGE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_message_mapping) structure used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

This property value controls how an HTTP request or response is mapped into
a message object. See [WS_HTTP_MESSAGE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_message_mapping) for more information.

The default value for this property is a [WS_HTTP_MESSAGE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_message_mapping) structure is as follows:

* requestMappingOptions: 0
* requestHeaderMappings: none
* responseMappingOptions: 0
* responseHeaderMappings: none

[WS_HTTP_MESSAGE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_message_mapping) fields requestMappingOptions and responseMappingOptions must be 0
unless encoding is set to [WS_ENCODING_RAW](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_encoding) using channel property **WS_CHANNEL_PROPERTY_ENCODING**.

### `WS_CHANNEL_PROPERTY_ENABLE_HTTP_REDIRECT:43`

A **BOOL** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) with [WS_CHANNEL_TYPE_REQUEST](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type).

This property value controls whether HTTP auto redirection is enabled.

Setting this value to **TRUE** enables HTTP auto redirection.

The default value is **FALSE**.
If the **WS_CHANNEL_PROPERTY_HTTP_REDIRECT_CALLBACK_CONTEXT** property is specified,
this property is ignored.

### `WS_CHANNEL_PROPERTY_HTTP_REDIRECT_CALLBACK_CONTEXT:44`

A [WS_HTTP_REDIRECT_CALLBACK_CONTEXT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_http_redirect_callback_context) structure
used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) with [WS_CHANNEL_TYPE_REQUEST](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type).

This property value may be specified when more granular control of automatic HTTP redirection is needed.

When this property is set, the specified callback routine will be called with the original endpoint URL
and the new URL that the message is to be forwarded to. Callback return value is used to indicate whether
the redirection should be allowed.

### `WS_CHANNEL_PROPERTY_FAULTS_AS_ERRORS:45`

A **BOOL** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty),
[WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) or [WsCreateServiceProxy](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateserviceproxy) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) and [WS_CHANNEL_TYPE_REQUEST](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type), or **WS_TCP_CHANNEL_BINDING**, **WS_NAMEDPIPE_CHANNEL_BINDING**, and **WS_UDP_CHANNEL_BINDING** on the client.

When set to **TRUE**, Channel and Service Model functions return an error code when a fault is received.
If the fault is recognized by this runtime, the corresponding error code is returned,
otherwise **WS_E_ENDPOINT_FAULT_RECEIVED** is returned. (See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).) When set to **FALSE**, [WsReceiveMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreceivemessage)
and [WsRequestReply](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsrequestreply) return **WS_E_ENDPOINT_FAULT_RECEIVED** when a fault is received.
The other channel functions return faults as regular messages and'[WS_MESSAGE_PROPERTY_IS_FAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id)
can be used to distinguish faults from other messages.

When this property is set to **TRUE** and used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel) or [WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty),
it overrides the following behavior of **WS_CHANNEL_PROPERTY_ALLOW_UNSECURED_FAULTS**: if the fault is recognized by the
runtime, an unsecured fault will not cause security verification of the fault message to fail even if
**WS_CHANNEL_PROPERTY_ALLOW_UNSECURED_FAULTS** is set to **FALSE**. The status of the security verification
can be determined by inspecting [WS_MESSAGE_PROPERTY_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id).
This does not apply to [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) as it does not support security.

When this property is set to **FALSE** or used with [WsCreateServiceProxy](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateserviceproxy) or the fault is not recognized
by the runtime, the behavior described in **WS_CHANNEL_PROPERTY_ALLOW_UNSECURED_FAULTS** applies without
exception.

Regardless of this property value, if an error code is returned as a result of receiving a fault,
[WsGetFaultErrorProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetfaulterrorproperty) may be used to query the details of the fault from the error object.

This property can be set in any channel state.

The default value is **TRUE**. If used with [WsCreateServiceProxy](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateserviceproxy), this property must be set to **TRUE**.

Setting this property to **TRUE** can cause message security verification to be disabled for certain faults.
Unverified faults may not be trustworthy.

### `WS_CHANNEL_PROPERTY_ALLOW_UNSECURED_FAULTS:46`

A **BOOL** used with [WsCreateChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannel), [WsSetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetchannelproperty),
or [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) and [WS_CHANNEL_TYPE_REQUEST](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type), or **WS_TCP_CHANNEL_BINDING** and **WS_NAMEDPIPE_CHANNEL_BINDING** on the client.

When set to **TRUE**, unsecured faults received on a secure channel do not cause message security verification to fail. Instead the
fault will be treated as if message security verification succeeded and handled as described in **WS_CHANNEL_PROPERTY_FAULTS_AS_ERRORS**.
The status of the security verification can be determined by inspecting [WS_MESSAGE_PROPERTY_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id).

When set to **FALSE**, message security verification of fault messages is handled like the verification of any other message.

**WS_CHANNEL_PROPERTY_FAULTS_AS_ERRORS** may override this property for faults recognized by this runtime.

This property only applies to message-level security verification and has no impact on transport security.

This property can be set in any channel state.

The default value is **FALSE**.

Setting this property to **TRUE** causes message security verification for faults to be disabled. Unsecured faults may not be trustworthy.

### `WS_CHANNEL_PROPERTY_HTTP_SERVER_SPN:47`

A **WCHAR** pointer
used with [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) and [WS_CHANNEL_TYPE_REQUEST](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type).

Returns the Server Principal Name of the remote endpoint used for the last failed request. There is no guarantee that this property is
available. The following are the necessary (but not always sufficient) conditions for this property to be present:

* The channel sent a request.
* The request failed due to mismatched HTTP header authentication schemes. See [WS_HTTP_HEADER_AUTH_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_header_auth_security_binding).
* The remote endpoint supports the "Nego2" authentication scheme.

This property is only available on Windows 7 and above.

### `WS_CHANNEL_PROPERTY_HTTP_PROXY_SPN:48`

A **WCHAR** pointer used with [WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) and [WS_CHANNEL_TYPE_REQUEST](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type).

Returns the Server Principal Name of the HTTP proxy server used for the last failed request. There is no guarantee that this property is
available. The following are the necessary (but not always sufficient) conditions for this property to be present:

* The channel sent a request.
* The request failed due to mismatched HTTP header authentication schemes. See [WS_HTTP_HEADER_AUTH_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_header_auth_security_binding).
* The HTTP proxy server supports the "Nego2" authentication scheme.

This property is only available on Windows 7 and above.

### `WS_CHANNEL_PROPERTY_MAX_HTTP_REQUEST_HEADERS_BUFFER_SIZE:49`

A **ULONG** used with [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) or
[WsGetChannelProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding)
with [WS_CHANNEL_TYPE_REPLY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type). This value is a limit as to how big the headers
of an HTTP request being received can be. The limit specifies the maximum size
of the HTTP request headers in bytes.

This property limits the amount of memory
that the [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) with [WS_CHANNEL_TYPE_REPLY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type)
will allocate in order to receive HTTP request headers. When receiving, the entire HTTP request
headers are read into a buffer before processing.

The default value is 65536.