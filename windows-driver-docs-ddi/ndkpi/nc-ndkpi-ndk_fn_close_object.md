# NDK_FN_CLOSE_OBJECT callback function

## Description

The *NdkCloseObject* (*NDK_FN_CLOSE_OBJECT*) function initiates a close request for an NDK object.

## Parameters

### `pNdkObject` [in]

A pointer to the object header ([NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)) for the object to close.

### `CloseCompletion` [in]

A pointer to an *NdkCloseCompletion* close completion callback function ([NDK_FN_CLOSE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_completion)).

### `RequestContext` [in, optional]

A context value for the NDK provider to pass back to the *NdkCloseCompletion* function that is specified in the *CloseCompletion* parameter.

## Return value

The
*NdkCloseObject* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The NDK object is closed. The provider will not call the *NdkCloseCompletion* function. |
| **STATUS_PENDING** | The request is pending, the provider will call the *NdkCloseCompletion* function to complete the operation asynchronously. The close request has been successfully initiated, but it might not be completed. |
| **Other status codes** | An error occurred. |

## Remarks

The function dispatch table for each type of NDK object includes an *NDK_FN_CLOSE_OBJECT* function pointer. Close requests are asynchronous. An NDK consumer must not access the object after a close request is started.

The NDK provider must ensure that the *NdkCloseCompletion* function ([NDK_FN_CLOSE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_completion)) is the last callback called for the object that is closing. The provider must ensure that all outstanding asynchronous requests are completed and all in-progress callbacks have returned and further callbacks are prevented before the provider calls the *NdkCloseCompletion* function. After the provider calls the *NdkCloseCompletion* function, the provider not call any completion functions or notification callback functions for the object.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_CONNECTOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector_dispatch)

[NDK_CQ_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq_dispatch)

[NDK_FN_CLOSE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_completion)

[NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)