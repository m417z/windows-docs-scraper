# WsAbortServiceHost function

## Description

Aborts all current operations on the specified [service host](https://learn.microsoft.com/windows/desktop/wsw/service-host).

## Parameters

### `serviceHost` [in]

Pointer to a [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host) structure representing the service host on which to abort operations.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

**WsAbortServiceHost** aborts all listeners on the service host, and as a result, no new channels are accepted from the client. All channels currently being used by the service host to service messages are aborted as well.

If a call is pending and it has a cancel callback registered through the [WsRegisterOperationForCancel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsregisteroperationforcancel) function, the callback is called. However, the runtime still waits for the call to complete.

For more information on registering for cancellation notification,
see [WsRegisterOperationForCancel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsregisteroperationforcancel).