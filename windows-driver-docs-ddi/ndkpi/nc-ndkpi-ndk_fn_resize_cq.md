# NDK_FN_RESIZE_CQ callback function

## Description

The *NdkResizeCq* (*NDK_FN_RESIZE_CQ*) function changes the size of an NDK completion queue (CQ).

## Parameters

### `pNdkCq` [in]

A pointer to an NDK completion queue (CQ) object ([NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)).

### `CqDepth` [in]

The new number of completion entries that the CQ can hold. The CQ size must be less than or equal to the value that is specified in the **MaxCqDepth** member in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure.

### `RequestCompletion` [in]

A pointer to an *NdkRequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)) function.

### `RequestContext` [in, optional]

A context value to pass to the *Context* parameter of the callback function that is specified in the *RequestCompletion* parameter.

## Return value

The *NDK_FN_RESIZE_CQ* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The CQ was resized successfully. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The driver will call the specified *RequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)) function to complete the pending operation. |
| **STATUS_INVALID_PARAMETER** | The request failed because the CQ size that is specified in the *CqDepth* parameter is greater than the value in the **MaxCqDepth** member in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure. |
| **STATUS_INSUFFICIENT_RESOURCES** | The request failed due to insufficient resources. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkResizeCq* changes the number of completion entries that a CQ can hold.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)

[NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)

[NDK_CQ_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq_dispatch)

[NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)