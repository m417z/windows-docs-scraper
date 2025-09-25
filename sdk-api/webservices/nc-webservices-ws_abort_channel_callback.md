# WS_ABORT_CHANNEL_CALLBACK callback function

## Description

Handles the [WsAbortChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortchannel) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `channelInstance` [in]

The pointer to the state specific to this channel instance,
as created by the [WS_CREATE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_channel_callback).

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.

## Remarks

See [WsAbortChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortchannel) for information about the contract
of this API.