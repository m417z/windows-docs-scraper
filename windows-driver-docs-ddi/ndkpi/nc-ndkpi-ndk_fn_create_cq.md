# NDK_FN_CREATE_CQ callback function

## Description

The *NdkCreateCq* (*NDK_FN_CREATE_CQ*) function creates an NDK completion queue (CQ) object.

## Parameters

### `pNdkAdapter` [in]

A pointer to an NDK adapter object ([NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)).

### `CqDepth` [in]

The maximum number of completion entries that the CQ can hold. This value must be less than or equal to the **MaxCqDepth** value that is specified in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure.

### `CqNotification` [in]

A pointer to the *NdkCqNotificationCallback* function ([NDK_FN_CQ_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_cq_notification_callback)) that the provider uses to notify the consumer when request completions are queued in the CQ. The provider will not call *NdkCqNotificationCallback* unless the consumer arms the notification with the *NdkArmCq* ([NDK_FN_ARM_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_arm_cq)) function.

### `CqNotificationContext` [in, optional]

A context value that the NDK provider passes back to the *NdkCqNotificationCallback* function that is specified in the *CqNotification* parameter.

### `Affinity` [in, optional]

An affinity mask ([GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity)) that provides preferred processors that the consumer would choose to run the *NdkCqNotificationCallback* callbacks. Providers should honor the processor preferences if their underlying hardware allows it, but consumers cannot assume that *NdkCqNotificationCallback* callbacks will occur only on the preferred processors. Set *Affinity* to NULL if there are no preferred processors.

### `CreateCompletion` [in]

A pointer to an *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that completes the creation of an NDK object.

### `RequestContext` [in, optional]

A context value that the NDK provider passes back to the *NdkCreateCompletion* function that is specified in the *CreateCompletion* parameter.

### `ppNdkCq`

A pointer to a completion queue (CQ) object ([NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)) is returned in this location if the request succeeds without returning STATUS_PENDING. If *NdkCreateCq* returns STATUS_PENDING this parameter is ignored and the created object is returned with the callback that is specified in the *CreateCompletion* parameter.

## Return value

The
*NDK_FN_CREATE_CQ* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The CQ object was created successfully and returned with the **ppNdkCq* parameter. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The provider will call the function specified in the *CreateCompletion* parameter([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) to complete the pending operation. |
| **STATUS_INVALID_PARAMETER** | The request failed because the requested *CqDepth* value is greater than the **MaxCqDepth** value that is specified in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure. |
| **STATUS_INSUFFICIENT_RESOURCES** | The request failed due to insufficient resources. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **Other status codes** | An error occurred. |

## Remarks

The *NdkCreateCq* function creates an NDK completion queue (CQ) object. If the function returns STATUS_SUCCESS, the created object is returned in the *ppNdkCq* parameter. If *NdkCreateCq* returns STATUS_PENDING, the created object is returned by the *NdkCreateCompletion* ([NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)) function that is specified in the *CreateCompletion* parameter.

## See also

[GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity)

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)

[NDK_ADAPTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter_dispatch)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)

[NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)

[NDK_FN_ARM_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_arm_cq)

[NDK_FN_CQ_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_cq_notification_callback)

[NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)