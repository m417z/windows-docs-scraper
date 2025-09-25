# NDK_FN_CREATE_SRQ callback function

## Description

The *NdkCreateSrq* (*NDK_FN_CREATE_SRQ*) function creates an NDK shared receive queue (SRQ) object.

## Parameters

### `pNdkPd` [in]

A pointer to an NDK protection domain (PD) object ([NDK_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_pd)).

### `SrqDepth` [in]

The maximum number of receive requests that can be outstanding over the SRQ. This value must be less than or equal to the value in the **MaxSrqDepth** member that is specified in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure.

### `MaxReceiveRequestSge` [in]

The maximum number of SGEs that are supported in a single receive request. This value must be less than or equal to the value in the **MaxReceiveRequestSge** member that is specified in the NDK_ADAPTER_INFO structure.

### `NotifyThreshold` [in]

The minimum number of queued receive requests for triggering SRQ notification callbacks.

### `SrqNotification` [in, optional]

An optional *NdkSrqNotificationCallback* function([NDK_FN_SRQ_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_srq_notification_callback)) which the provider calls if the queued receive request count falls below the threshold that is specified in the *NotifyThreshold* parameter.

### `SrqNotificationContext` [in, optional]

A context value that the NDK provider passes back to the *NdkSrqNotificationCallback* function that is specified in the *SrqNotification* parameter.

### `Affinity` [in, optional]

An affinity mask ([GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity)) that specifies preferred processors that the consumer would choose to run the *NdkSrqNotificationCallback* callbacks. Providers should honor the processor preferences if their underlying hardware allows it, but consumers cannot assume that *NdkSrqNotificationCallback* callbacks will occur only on the preferred processors. Set *Affinity* to NULL if there are no preferred processors.

### `CreateCompletion` [in]

A pointer to an *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that completes the creation of an NDK object.

### `RequestContext` [in, optional]

A context value that the NDK provider passes back to the *NdkCreateCompletion* function that is specified in the *CreateCompletion* parameter.

### `ppNdkSrq`

A pointer to a created SRQ object ([NDK_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq)) is returned in this location if the request succeeds without returning STATUS_PENDING. If the request returns STATUS_PENDING then this parameter is ignored and the created object is returned with the callback that is specified in the *CreateCompletion* parameter.

## Return value

The
*NdkCreateSrq* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The SRQ object was created successfully and returned with the **ppNdkSrq* parameter. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The provider will call the function specified in the *CreateCompletion* parameter ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) to complete the pending operation. |
| **STATUS_INVALID_PARAMETER** | The request failed because the requested *SrqDepth* or *MaxReceiveRequestSge* is not within the limits that are specified in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure. |
| **STATUS_INSUFFICIENT_RESOURCES** | The request failed due to insufficient resources. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **Other status codes** | An error occurred. |

## Remarks

The *NdkCreateSrq* function creates an NDK shared receive queue (SRQ) object. If the function returns STATUS_SUCCESS, the created object is returned in the *ppNdkSrq* parameter. If *NdkCreateSrq* returns STATUS_PENDING, the created object is returned by the *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that is specified in the *CreateCompletion* parameter.

## See also

[GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity)

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)

[NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)

[NDK_FN_SRQ_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_srq_notification_callback)

[NDK_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_pd)

[NDK_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq)