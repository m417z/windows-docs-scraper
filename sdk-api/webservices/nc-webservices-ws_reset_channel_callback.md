# WS_RESET_CHANNEL_CALLBACK callback function

## Description

Handles the [WsResetChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetchannel) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `channelInstance` [in]

The pointer to the state specific to this channel instance,
as created by the [WS_CREATE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_channel_callback).

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The channel was in an inappropriate state. |

## Remarks

See [WsResetChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetchannel) for information about the contract
of this API.