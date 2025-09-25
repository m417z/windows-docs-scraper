# WS_FREE_LISTENER_CALLBACK callback function

## Description

Handles the [WsFreeListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreelistener) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `listenerInstance` [in]

The pointer to the state specific to this listener instance,
as created by the [WS_CREATE_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_listener_callback).

The callback should free this pointer.

## Remarks

See [WsOpenListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenlistener) for information about the contract
of this API.