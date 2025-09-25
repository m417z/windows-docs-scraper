# WS_ACCEPT_CHANNEL_CALLBACK callback function

## Description

Handles the [WsAcceptChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsacceptchannel) call
for a [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).

## Parameters

### `listenerInstance` [in]

The pointer to the state specific to this listener instance,
as created by the [WS_CREATE_LISTENER_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_listener_callback).

### `channelInstance` [in]

The pointer to the state specific to the channel instance,
as created by the [WS_CREATE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_create_channel_callback) when [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) was called.

### `asyncContext` [in, optional]

Information on how to invoke the function asynchronously, or NULL if invoking synchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_OPERATION_ABORTED** | The listener and/or channel was aborted. |
| **WS_E_OBJECT_FAULTED** | The listener has faulted. Once a listener has faulted, then accepts will immediately return this error. |
| **WS_E_INVALID_OPERATION** | The listener was in an inappropriate state. |
| **WS_E_ENDPOINT_DISCONNECTED** | The connection with the remote endpoint was terminated. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_SECURITY_VERIFICATION_FAILURE** | Security verification was not successful for the received data. |
| **WS_E_SECURITY_SYSTEM_FAILURE** | A security operation failed in the Windows Web Services framework. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

See [WsAcceptChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsacceptchannel) for information about the contract
of this API.