# WS_OPEN_LISTENER_CALLBACK callback function

## Description

Handles the [WsOpenListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenlistener) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `listenerInstance` [in]

The pointer to the state specific to this listener instance,
as created by the [WS_CREATE_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_listener_callback).

### `url` [in]

The URL to listen on. The format and interpretation of the URL
is defined by the custom listener.

### `asyncContext` [in, optional]

Information on how to invoke the function asynchronously, or **NULL** if invoking synchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_OPERATION_ABORTED** | The listener was aborted during the open, or before the open. |
| **WS_E_INVALID_OPERATION** | The listener is in the incorrect state. |
| **WS_E_ADDRESS_IN_USE** | The address is already being used. |
| **WS_E_ADDRESS_NOT_AVAILABLE** | The address is not valid for this context. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **WS_E_OPERATION_ABORTED** | The operation was aborted. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

See [WsOpenListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenlistener) for information about the contract
of this API.