# WsAbortServiceProxy function

## Description

Aborts the [service proxy](https://learn.microsoft.com/windows/desktop/wsw/service-proxy), and cancels any pending I/O on the service proxy.

## Parameters

### `serviceProxy` [in]

Pointer to a [WS_SERVICE_PROXY](https://learn.microsoft.com/windows/desktop/wsw/ws-service-proxy) structure representing the service proxy to abort.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

**WsAbortServiceProxy** shows the following behavior depending on the state of service proxy (see the [WS_SERVICE_PROXY_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_service_proxy_state) enumeration for possible states):

* If the service proxy is opening and in the WS_SERVICE_PROXY_STATE_OPENING state, you can call **WsAbortServiceProxy** to abort the opening operation. The service proxy will
  cancel all pending I/O and transition back to WS_SERVICE_PROXY_STATE_CREATED state.
* If the service proxy is already open and in the WS_SERVICE_PROXY_STATE_OPEN state, **WsAbortServiceProxy** will cause the service proxy to abort all underlying channels and transition to the
  WS_SERVICE_PROXY_STATE_FAULTED state. Once the abort is initiated, the service proxy will not accept any new calls. The application can call [WsCloseServiceProxy](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscloseserviceproxy) to close it
* If the service proxy is closing and in the WS_SERVICE_PROXY_STATE_CLOSING state, all underlying channels are aborted, and the service proxy transitions to the WS_SERVICE_PROXY_STATE_CLOSED state.

For an example of using this function, see [ServiceCancellationExample](https://learn.microsoft.com/windows/desktop/wsw/servicecancellationexample).