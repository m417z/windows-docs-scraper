# WsCloseServiceProxy function

## Description

Closes down communication with the specified [service proxy](https://learn.microsoft.com/windows/desktop/wsw/service-proxy).

## Parameters

### `serviceProxy` [in]

Pointer to a [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) structure representing he service proxy to be closed.

### `asyncContext` [in, optional]

Pointer to a [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) structure containing information for invoking the function asynchronously. Pass **NULL** to invoke the function synchronously.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_INVALID_OPERATION** | The current state of the service proxy is not valid for this operation. This is only error for which close will fail. |
| **WS_E_ENDPOINT_DISCONNECTED** | The underlying [WS_CHANNEL](https://learn.microsoft.com/windows/desktop/wsw/ws-channel) was disconnected during the close operation. This error occurs only in cases where the underlying channel is session based. |
| **WS_E_OPERATION_ABORTED** | The operation was aborted. |
| **WS_E_ENDPOINT_FAILURE** | The remote endpoint could not process the request. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

If a service operation call is pending on the service proxy, **WsCloseServiceProxy** waits for each call to complete. After calling **WsCloseServiceProxy** application should not perform any more calls on the service proxy.

Note that WS_E_INVALID_OPERATION is the only
error code that indicates that closure has failed. Other error codes indicate that the operation succeeded, and the error code is for informational purposes only.