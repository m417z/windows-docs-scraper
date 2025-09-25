# WsOpenServiceHost function

## Description

Opens a [Service Host](https://learn.microsoft.com/windows/desktop/wsw/service-host) for communication and starts the Listeners on all the endpoints.
Client applications cannot connect to Service endpoints until **WsOpenSerivceHost** is called.

## Parameters

### `serviceHost` [in]

A pointer to the **Service Host** object to open. The pointer must reference a valid [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host) object
returned by [WsCreateServiceHost](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateservicehost) and the referenced **Service Host** value may not be **NULL**.

### `asyncContext` [in, optional]

A pointer to A WS_ASYNC_CONTEXT object that has information about how to invoke the function asynchronously. The value is set to **NULL** if invoking synchronously.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **WS_E_OPERATION_ABORTED** | The service host was aborted before the open, or during the open. |
| **WS_E_INVALID_OPERATION** | The current state of the service proxy is not valid for this operation. |
| **WS_E_ADDRESS_IN_USE** | The address is already being used. |
| **WS_E_ADDRESS_NOT_AVAILABLE** | The address is not valid for this context. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **WS_E_OPERATION_ABORTED** | The operation was aborted. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

Note that all the endpoints listeners have to successfully open before any channel is accepted by service host for communicating
with the client.