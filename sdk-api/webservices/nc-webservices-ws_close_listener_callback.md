# WS_CLOSE_LISTENER_CALLBACK callback function

## Description

Handles the [WsCloseListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscloselistener) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `listenerInstance` [in]

The pointer to the state specific to this listener instance,
as created by the [WS_CREATE_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_listener_callback).

### `asyncContext` [in, optional]

Information on how to invoke the function asynchronously, or **NULL** if invoking synchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_OPERATION_ABORTED** | The close was aborted by a call to [WsAbortListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortlistener) as it was closing. |
| **WS_E_INVALID_OPERATION** | The listener was in an inappropriate state. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

See [WsCloseListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscloselistener) for information about the contract
of this API.