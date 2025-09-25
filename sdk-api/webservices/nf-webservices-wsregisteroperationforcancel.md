# WsRegisterOperationForCancel function

## Description

A service operation can use this function to register for a cancel notification.
It is only valid to call this API when the service operation is executing. The behavior
for calling it after the completion of Service Operation is not supported.

While this API is being called and the runtime has determined that the cancellation of the
service operation is necessary, it can call the callback during the call to this API by the application.

The caller should therefore assume that the runtime may call on the callback
[WS_OPERATION_CANCEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_operation_cancel_callback) as soon as the WsRegisterOperationForCancel is called.

## Parameters

### `context` [in]

The context that the property value is being obtained for.

### `cancelCallback` [in]

Function pointer for cancel notification function.

### `freestateCallback` [in, optional]

A optional parameter specifying the function pointer to the free state call.

### `userState` [in, optional]

A optional parameter specifying the application specific state which can be used to identify call data.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.