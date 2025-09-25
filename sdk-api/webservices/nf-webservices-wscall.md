# WsCall function

## Description

Used internally by the [service proxy](https://learn.microsoft.com/windows/desktop/wsw/service-proxy) to format the specified arguments according to the specified metadata and send them in a message. The application should
never call this function directly.

## Parameters

### `serviceProxy` [in]

Pointer to a WS_SERVICE_PROXY structure representing the service proxy.

### `operation` [in]

Pointer to a [WS_OPERATION_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_operation_description) structure containing the metadata for the call.

### `arguments` [in, optional]

An array of pointers to the individual arguments for the service operation being represented by the *operation* parameter.

The number of elements must correspond to the number of parameters specified as part of WS_OPERATION_DESCRIPTION in
the operation parameter.

### `heap` [in]

Pointer to a [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) structure representing the [heap](https://learn.microsoft.com/windows/desktop/wsw/heap) from which memory is allocated for the call.

### `callProperties`

An array of [WS_CALL_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_call_property) structures containing the call properties.

### `callPropertyCount` [in]

The number of properties in the call properties array.

### `asyncContext` [in, optional]

Pointer to information for invoking the function asynchronously. Pass **NULL** to invoke the function synchronously.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **WS_E_OPERATION_ABANDONED** | The operation was abandoned. |
| **WS_E_OPERATION_TIMED_OUT** | The operation did not complete within the time allotted. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |
| **Other Errors** | This function may return other errors not listed above. |