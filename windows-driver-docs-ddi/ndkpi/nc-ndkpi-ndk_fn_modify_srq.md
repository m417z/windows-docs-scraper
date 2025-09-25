# NDK_FN_MODIFY_SRQ callback function

## Description

The *NdkModifySrq* (*NDK_FN_MODIFY_SRQ*) function modifies the size and notification threshold of an NDK shared receive queue (SRQ).

## Parameters

### `pNdkSrq` [in]

A pointer to an NDK shared receive queue (SRQ) object ([NDK_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq)).

### `SrqDepth` [in]

The new size of the SRQ. The new size must be less than or equal to the size that is specified in the **MaxSrqDepth** member of the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure.
A size of zero means no depth modification is requested. That is, the existing SRQ depth value must be preserved.

### `NotifyThreshold` [in]

The number of queued receive requests that will trigger an SRQ notification callback. If this value is greater than zero, the NDK provider must arm the SRQ notification to trigger when the number of queued receive requests falls below the specified value. If the number of queued receive requests is already below the threshold value at the time of this function call, an SRQ notification must be generated. After an SRQ notification is generated, further notifications are disarmed until the NDK consumer invokes this function again with a non-zero threshold value. If a threshold value of zero is specified, the provider must preserve the current SRQ notification threshold and arming status.

### `RequestCompletion` [in]

A pointer to a request completion callback routine *NdkRequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)).

### `RequestContext` [in, optional]

A context value to pass to the *Context* parameter of the callback function that is specified in the *RequestCompletion* parameter.

## Return value

The
*NdkModifySrq* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The request was completed successfully. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The driver will call the specified *RequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)) function to complete the pending operation. |
| **STATUS_INVALID_PARAMETER** | The request failed because the value in the *SrqDepth* parameter is not within the limits that are specified in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkModifySrq* modifies the size and notification threshold for an NDK shared receive queue (SRQ) object ([NDK_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq)).

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)

[NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)

[NDK_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq)