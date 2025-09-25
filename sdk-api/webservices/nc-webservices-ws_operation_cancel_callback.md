# WS_OPERATION_CANCEL_CALLBACK callback function

## Description

Gives notification of the cancellation of an
asynchronous service operation call as a result of an aborted shutdown of service host.
This callback is invoked by service model.

## Parameters

### `reason` [in]

Specifies the reason for which the call back is called.

### `state` [in]

A reference to the application defined state registered with the callback.

## Remarks

See [WsRegisterOperationForCancel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsregisteroperationforcancel) for details.