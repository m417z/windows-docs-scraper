# WS_ABANDON_MESSAGE_CALLBACK callback function

## Description

Handles the [WsAbandonMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabandonmessage) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `channelInstance` [in]

Pointer to the state specific to this channel instance,
as created by the [WS_CREATE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_channel_callback).

### `message` [in]

The message that is current being read or written. This should be
the same message as was passed to [WsWriteMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritemessagestart) or [WsReadMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessagestart).

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | This is returned if the channel is not in the [WS_CHANNEL_STATE_OPEN](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state) state or the **WS_CHANNEL_STATE_FAULTED** state. |
| **E_INVALIDARG** | The specified message is not currently being read or written using the channel. |

## Remarks

See [WsAbandonMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabandonmessage) for information about the contract
of this API.