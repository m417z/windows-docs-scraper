# WsAcceptChannel function

## Description

Accepts the next incoming message from the specified [listener](https://learn.microsoft.com/windows/desktop/wsw/listener).

## Parameters

### `listener` [in]

Pointer to a [WS_LISTENER](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) structure representing the listener.
This is the listener passed to [WsCreateChannelForListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatechannelforlistener) when the channel was created.

### `channel` [in]

Pointer to a [WS_CHANNEL](https://learn.microsoft.com/windows/desktop/wsw/ws-channel) structure representing the channel to accept.

### `asyncContext` [in, optional]

Pointer to a [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) data structure with information for invoking the function asynchronously. Pass a **NULL**
value for a synchronous operation.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_OPERATION_ABORTED** | The listener or channel was aborted. |
| **WS_E_OBJECT_FAULTED** | The listener has faulted. See the Remarks section. |
| **WS_E_INVALID_OPERATION** | The listener or the channel or both were in an inappropriate state. See the Remarks section. |
| **WS_E_ENDPOINT_DISCONNECTED** | The connection with the remote endpoint was terminated. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **WS_E_SECURITY_VERIFICATION_FAILURE** | Security verification was not successful for the received data. |
| **WS_E_SECURITY_SYSTEM_FAILURE** | A security operation failed in the Windows Web Services framework. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

Once you accept a channel, you must close it when you no longer need it and free the resources by calling the
[WsCloseChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsclosechannel) function, and then calling either the [WsFreeChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreechannel) or the [WsResetChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetchannel).
function.

For **WsAcceptChannel** to succeed, the listener must be in WS_LISTENER_STATE_OPEN state, and the channel must be in WS_CHANNEL_STATE_CREATED state. For more information, see the [WS_LISTENER_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_state) and [WS_CHANNEL_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_state) enumerations.

If a listener is in the **WS_LISTENER_STATE_FAULTED** state,
**WsAcceptChannel** immediately returns the **WS_E_OBJECT_FAULTED** error code. If an
application is calling **WsAcceptChannel** in a loop, the application must check for this
error, so it can end the loop.