# NDK_FN_DISCONNECT callback function

## Description

The *NdkDisconnect* (*NDK_FN_DISCONNECT*) function starts a disconnect on an NDK connection.

## Parameters

### `pNdkConnector` [in]

A pointer to a connector object ([NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)).

### `RequestCompletion` [in]

A pointer to a request completion callback routine *NdkRequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)).

### `RequestContext` [in, optional]

A context value to pass to the *Context* parameter of the callback function that is specified in the *RequestCompletion* parameter.

## Return value

The *NdkDisconnect* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The disconnect request was completed successfully. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The driver will call the specified *RequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)) function to complete the pending operation. |
| **STATUS_IO_TIMEOUT** | The disconnect handshake timed out. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkDisconnect* initiates a graceful disconnect on a connection. After the underlying protocol driver performs a graceful disconnect, the NDK provider must also perform an implicit flush on the QP.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_CONNECTOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector_dispatch)

[NDK_FN_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_connect)

[NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)