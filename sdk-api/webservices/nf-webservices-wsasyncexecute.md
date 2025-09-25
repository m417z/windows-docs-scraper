# WsAsyncExecute function

## Description

Helper function for implementing an [asynchronous](https://learn.microsoft.com/windows/desktop/wsw/asynchronous-model) operation.

## Parameters

### `asyncState` [in]

A pointer to the [WS_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_state) structure used during the asynchronous operation. This is a state maintenance parameter not intended
for direct use. The application must allocate the **WS_ASYNC_STATE** structure and ensure that it
is kept alive during the entire asynchronous operation. The **WS_ASYNC_STATE** structure can be reused after an
asynchronous operation has completed.

### `operation` [in, optional]

Represents the initial asynchronous operation to be performed.

### `callbackModel` [in]

Indicates whether the callback is being invoked long or short.
For more information, see [WS_CALLBACK_MODEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_callback_model)

### `callbackState` [in]

A void pointer to a user-defined value that is passed to each [WS_ASYNC_FUNCTION](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_async_function).

### `asyncContext` [in, optional]

Pointer to information for invoking the function asynchronously. Pass **NULL** to invoke the function synchronously.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

## Remarks

For an understanding of how WWSAPI handles asynchronous operations, see the [Asynchronous Model](https://learn.microsoft.com/windows/desktop/wsw/asynchronous-model) topic.

In many cases, an asynchronous operation is composed of other asynchronous operations. Each asynchronous operation may return WS_S_ASYNC indicating the callback will be invoked, or any other success or failure code, in which case the callback will not be invoked. The operation must be prepared to accept a **NULL** WS_ASYNC_CONTEXT indicating that the caller is requesting the operation to be performed synchronously. It must also ensure that the callback is invoked appropriately. In complex asynchronous operations, **WsAsyncExecute** simplifies these details.

**WsAsyncExecute** operates by invoking a user-defined callback which can initiate an asynchrnous operation and indicate a function to be invoked when the asynchronous operation is complete. This sequence continues until the callback does not set another function to invoke. At this point, the callback specified by the WS_ASYNC_CONTEXT will be invoked if any of the operations completed asynchronously.

The [WS_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_state) parameter is used by **WsAsyncExecute** to maintain its state, and is not intended to be initialized, inspected, or used by the caller. The caller however, must allocate the **WS_ASYNC_STATE** and ensure that it is kept alive during the entire asynchronous operation. The **WS_ASYNC_STATE** may be reused once the asynchronous operation is complete.

The examples [AsyncAdd3ExplicitExample](https://learn.microsoft.com/windows/desktop/wsw/asyncadd3explicitexample) and [AsyncAdd3ImplicitExample](https://learn.microsoft.com/windows/desktop/wsw/asyncadd3implicitexample) demonstrate implementing
the same asynchronous function manually using **WsAsyncExecute**.