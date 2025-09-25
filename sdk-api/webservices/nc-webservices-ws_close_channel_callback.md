# WS_CLOSE_CHANNEL_CALLBACK callback function

## Description

Handles the [WsCloseChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsclosechannel) call
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
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_OPERATION_ABORTED** | The close was aborted by a call to [WsAbortChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortchannel) as it was closing. |
| **WS_E_INVALID_OPERATION** | The channel was in an inappropriate state. |
| **WS_E_OPERATION_ABORTED** | The operation was aborted. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_ENDPOINT_DISCONNECTED** | The connection with the remote endpoint was terminated. |
| **WS_E_ENDPOINT_FAILURE** | The remote endpoint could not process the request. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

See [WsCloseChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsclosechannel) for information about the contract
of this API.