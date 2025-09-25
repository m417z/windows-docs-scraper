# WsCloseListener function

## Description

Causes the specified [listener](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) to stop listening.

## Parameters

### `listener` [in]

Pointer to a [WS_LISTENER](https://learn.microsoft.com/windows/desktop/wsw/ws-listener) structure representing the listener to close.

### `asyncContext` [in, optional]

Pointer to a [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) structure containing information for invoking the function asynchronously. Pass **NULL** to invoke the function synchronously.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_OPERATION_ABORTED** | The close was aborted by a call to [WsAbortListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsabortlistener) as the listener was closing. |
| **WS_E_INVALID_OPERATION** | The listener was in an inappropriate state. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

After the listener is closed, the listener can safely be released.

This operation is allowed for listener in the **WS_LISTENER_STATE_OPEN** or
**WS_LISTENER_STATE_FAULTED** state.
(For listener states, see the [WS_LISTENER_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_state) enumeration.)

When a listener is closed, any pending attempts to accept a channel with the [WsAcceptChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsacceptchannel) method are aborted. However, **WsCloseListener** waits for any pending I/O to complete before proceeding with the closing process.