# WS_OPERATION_FREE_STATE_CALLBACK callback function

## Description

Allows an application to cleanup state information that was registered with cancellation callback.
This callback is invoked by service model.

## Parameters

### `state` [in]

A reference to the application defined state registered with the callback.

## Remarks

See [WsRegisterOperationForCancel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsregisteroperationforcancel) for details.