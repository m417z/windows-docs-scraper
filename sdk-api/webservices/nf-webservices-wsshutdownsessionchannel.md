# WsShutdownSessionChannel function

## Description

Used to signal the end of messages for a session channel.

## Parameters

### `channel` [in]

The session channel to shut down.

### `asyncContext` [in, optional]

Information on how to invoke the function asynchronously, or **NULL** if invoking synchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | This is returned if the channel is not in the [WS_CHANNEL_STATE_OPEN](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state) state. |

## Remarks

This function will indicate to the remote party that all
messages have been sent for the channel.

The remote party can detect that no more messages are available on the channel by
looking for the **WS_S_END** return value when receiving a message. (See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).) However,
messages can also become unavailable if the non-application messages were filtered by
the channel as described in [Channel Layer Overview](https://learn.microsoft.com/windows/desktop/wsw/channel-layer-overview). Session shutdown can
be distinguished from message filtering by keeping track of whether prior messages were
received. If prior messages were received then the session was shut down.

This function only applies to channels created with a
[WS_CHANNEL_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type) with a session that support
sending of messages:

* [WS_CHANNEL_TYPE_OUTPUT_SESSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type)
* [WS_CHANNEL_TYPE_DUPLEX_SESSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_type)

The channel must be in [WS_CHANNEL_STATE_OPEN](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state) state.

If this function is successful, the value of the
[WS_CHANNEL_PROPERTY_IS_SESSION_SHUT_DOWN](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id) property
will be **TRUE**.

Once a session channel has been shut down, attempting
to send a message on the channel or attempting to shut down
the channel will return **WS_E_INVALID_OPERATION**.

Calling this function is optional. When a session channel is closed using
[WsCloseChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsclosechannel) when in [WS_CHANNEL_STATE_OPEN](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state),
then the channel is automatically shut down as part of the close process.