# WsCloseServiceHost function

## Description

Closes down communication with the specified [service host](https://learn.microsoft.com/windows/desktop/wsw/service-host).

## Parameters

### `serviceHost` [in]

Pointer to a [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host) structure that represents the service host to be closed.

### `asyncContext` [in, optional]

Pointer to a [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) structure containing information for invoking the function asynchronously. Pass **NULL** to invoke the function synchronously.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_INVALID_OPERATION** | The current state of the service host is not valid for this operation. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **WS_E_OPERATION_ABORTED** | The operation was aborted. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

**WsCloseServiceHost** closes all listeners on the service host. As a result, no new
channels are accepted from the client. However, pending I/O on channels already accepted
is allowed to complete.

This has implications for endpoints configured to run with session-based channel bindings. If a client has an open session with a service on such an endpoint, the
closure will not complete until the client closes the session with the service.