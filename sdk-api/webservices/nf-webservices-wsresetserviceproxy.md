# WsResetServiceProxy function

## Description

Resets service proxy.

WsResetServiceProxy provides a convenient way to reuse the service proxy.
Once the proxy is [closed](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_service_proxy_state),
the application can call WsResetServiceProxy to reuse it.

Reusing the service proxy is helpful in scenarios where an application connects
to the same service time and time again. The cost of initialization is only paid
once during the initial creation of the service proxy.

## Parameters

### `serviceProxy` [in]

The service proxy.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The serviceProxy was in an inappropriate state. |
| **E_INVALIDARG** | One or more arguments are invalid. |