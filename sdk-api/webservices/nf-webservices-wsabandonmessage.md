# WsAbandonMessage function

## Description

Skips the remainder of a specified [message](https://learn.microsoft.com/windows/desktop/wsw/message) on a specified channel.

## Parameters

### `channel` [in]

Pointer to a [WS_CHANNEL](https://learn.microsoft.com/windows/desktop/wsw/ws-channel) structure representing the channel on which the message is being read or written.

### `message` [in]

Pointer to a [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) structure representing the message to abandon. This should be
the same message that was passed to the [WsWriteMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritemessagestart)
or [WsReadMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessagestart) function.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The channel is not in the WS_CHANNEL_STATE_OPEN or WS_CHANNEL_STATE_FAULTED state. (For channel states, see the [WS_CHANNEL_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state) enumeration.) |
| **E_INVALIDARG** | The specified message is not currently being read or written on the specified channel. |

## Remarks

**WsAbandonMessage** is used to skip reading or writing the remaining contents of a message,
allowing the next message for the channel to be read or written. In this respect, it is an alternative to
the [WsReadMessageEnd](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessageend) or [WsWriteMessageEnd](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritemessageend) functions, as shown in the following
state diagram:
:::image type="content" source="./images/AbandonMessage.png" border="false" alt-text="Diagram showing how the state transitions caused by the WsAbandonMessage function differ from the WSReadMessageEnd and WsWriteMessageEnd functions.":::

For read operations, an application typically calls **WsAbandonMessage** when it is unnecessary for the application to continue reading the
message data, for example, if the
message does not meet the application's requirements. This function can also be used
if the message contains malformed XML or if the [XML reader](https://learn.microsoft.com/windows/desktop/wsw/xml-reader) has
generated an error while reading the message.

If the channel is streamed
(see the WS_STREAMED_INPUT_TRANSFER_MODE value of the [WS_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode) enumeration), the remainder of the
streamed message data is read and automatically discarded with the next call to
[WsReadMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessagestart) or [WsCloseChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsclosechannel) for the
channel. If the channel is not streamed, the unread buffered message data
is simply discarded.

For write operations, an application typically calls **WsAbandonMessage** when the application cannot continue writing the message because it has encountered some error, such as one returned by the [XML writer](https://learn.microsoft.com/windows/desktop/wsw/xml-writer), or must stop generating the message for some other reason.

If the
channel is streamed (see the WS_STREAMED_INPUT_TRANSFER_MODE value of the [WS_TRANSFER_MODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_transfer_mode) enumeration), the message data will be truncated and may result in errors when read by the
remote party. If the channel is not streamed, the buffered data for the
message is simply discarded (since it was never transmitted).

This function allows the user of the channel to keep the channel open and
send or receive additional messages (such as sending a fault), even though
an error occurred. In contrast, [WsAbortChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortchannel) will causes
the channel to fault. A typical usage is first to try to abandon the message and
send a fault. If that fails, the channel can be aborted.

This function does not perform any blocking I/O.

This function is only valid when the channel is in the WS_CHANNEL_STATE_OPEN
or WS_CHANNEL_STATE_FAULTED states.
(For channel states, see the [WS_CHANNEL_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state) enumeration.)

The message specified must be the current message being read or the current message being written
for the specified channel.

If called correctly, this function will not fail (for example, due to lack of system resources).