# NDK_FN_CREATE_QP_WITH_SRQ callback function

## Description

The *NdkCreateQpWithSrq* (*NDK_FN_CREATE_QP_WITH_SRQ*) function create an NDK queue pair (QP) object with an NDK shared receive queue (SRQ) object.

## Parameters

### `pNdkPd` [in]

A pointer to an NDK protection domain (PD) object ([NDK_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_pd)).

### `pReceiveCq` [in]

A pointer to a completion queue (CQ) to use for receive request completions ([NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)).

### `pInitiatorCq` [in]

A pointer to a CQ to use for initiator request completions.

### `pSrq` [in]

A pointer to an NDK shared receive queue (SRQ) object ([NDK_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq)) to post receive requests.

### `QPContext` [in, optional]

A context value to be returned in the **QPContext** member of the [NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result) structure for all requests that are posted over this QP.

### `InitiatorQueueDepth` [in]

The maximum number of initiator requests that can be outstanding over the QP. This value must be less than or equal to the value in the **MaxInitiatorQueueDepth** member of the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure.

### `MaxInitiatorRequestSge` [in]

The maximum number of SGEs that can be supported in a single initiator request. This value must be less than or equal to the value in the **MaxInitiatorRequestSge** member of the NDK_ADAPTER_INFO structure.

### `InlineDataSize` [in]

The maximum amount of inline data in bytes that can be sent in a single send or write request. This value must be less than or equal to the value in the **MaxInlineDataSize** member of the NDK_ADAPTER_INFO structure.

### `CreateCompletion` [in]

A pointer to an *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that completes the creation of an NDK object.

### `RequestContext` [in, optional]

A context value that the NDK provider passes back to the *NdkCreateCompletion* function that is specified in the *CreateCompletion* parameter.

### `ppNdkQp`

A pointer to a created QP object ([NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)) is returned in this location if the request succeeds without returning STATUS_PENDING. If the request returns STATUS_PENDING then this parameter is ignored and the created object is returned with the callback that is specified in the *CreateCompletion* parameter.

## Return value

The
*NdkCreateQpWithSrq* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The QP object was created successfully and returned with the **ppNdkQp* parameter. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The provider will call the function specified in the *CreateCompletion* parameter([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) to complete the pending operation. |
| **STATUS_INVALID_PARAMETER** | The request failed because the requested *InitiatorQueueDepth*, *MaxInitiatorRequestSge* or *InlineDataSize* is not within the limits that are specified in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure. |
| **STATUS_INSUFFICIENT_RESOURCES** | The request failed due to insufficient resources. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **Other status codes** | An error occurred. |

## Remarks

The *NdkCreateQpWithSrq* function creates an NDK queue pair (QP) object with a shared receive queue (SRQ). A QP consists of a receive queue and an initiator queue. The receive queue is used to post receive requests. An initiator queue is used for initiating send, bind, fast-register, read, write, and invalidate requests.

If the function returns STATUS_SUCCESS, the created object is returned in the *ppNdkQp* parameter. If *NdkCreateQpWithSrq* returns STATUS_PENDING, the created object is returned by the *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that is specified in the *CreateCompletion* parameter.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)

[NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)

[NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)

[NDK_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_pd)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)

[NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result)

[NDK_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq)