# WS_SHUTDOWN_SESSION_CHANNEL_CALLBACK callback function

## Description

Handles the [WsShutdownSessionChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsshutdownsessionchannel) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `channelInstance` [in]

The pointer to the state specific to this channel instance,
as created by the [WS_CREATE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_channel_callback).

### `asyncContext` [in, optional]

Information on how to invoke the function asynchronously, or **NULL** if invoking synchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | This is returned if the channel is not in the [WS_CHANNEL_STATE_OPEN](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state) state. |

## Remarks

See [WsShutdownSessionChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsshutdownsessionchannel) for information about the contract
of this API.