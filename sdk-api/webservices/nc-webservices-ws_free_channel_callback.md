# WS_FREE_CHANNEL_CALLBACK callback function

## Description

Handles the [WsFreeChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreechannel) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `channelInstance` [in]

The pointer to the state specific to this channel instance,
as created by the [WS_CREATE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_channel_callback).

The callback should free this pointer.

## Remarks

See [WsOpenChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenchannel) for information about the contract
of this API.