# WS_ABORT_LISTENER_CALLBACK callback function

## Description

Handles the [WsAbortListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortlistener) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `listenerInstance` [in]

The pointer to the state specific to this listener instance,
as created by the [WS_CREATE_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_listener_callback).

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The listener was in an inappropriate state. |

## Remarks

See [WsAbortListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortlistener) for information about the contract
of this API.