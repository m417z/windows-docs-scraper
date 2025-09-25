# WS_ASYNC_FUNCTION callback function

## Description

Used with the [WsAsyncExecute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsasyncexecute) to specify the next
function to invoke in a series of async operations.

## Parameters

### `hr` [in]

The result of the previous async operation.

### `callbackModel` [in]

Whether the callback is being invoked long or short.
For more information, see [WS_CALLBACK_MODEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_callback_model).

### `callbackState` [in]

This user supplied value that was passed to [WsAsyncExecute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsasyncexecute)/

### `next`

Set the function field to the next function to call. It will be called regardless of whether or not the current function succeeds or fails.

Set the function field to **NULL** to indicate that there are no more functions to call.

[WsAsyncExecute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsasyncexecute) will set the function field to **NULL** before each function is called.

### `asyncContext` [in, optional]

Information on how to invoke the function asynchronously, or **NULL** if invoking synchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.