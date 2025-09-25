# NDK_FN_CQ_NOTIFICATION_CALLBACK callback function

## Description

The *NdkCqNotificationCallback* (*NDK_FN_CQ_NOTIFICATION_CALLBACK*) function is called by the NDK provider to notify the consumer about a completion queue (CQ) event.

## Parameters

### `CqNotificationContext` [in, optional]

A context area that was specified in the *CqNotificationContext* parameter of the *NdkCreateCq* ([NDK_FN_CREATE_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_cq)) function when the completion queue (CQ) object was created.

### `CqStatus` [in]

Indicates the CQ error status. The following status codes are defined:

| Term | Description |
| --- | --- |
| STATUS_SUCCESS | Indicates the CQ is operating normally. |
| STATUS_BUFFER_OVERFLOW | Indicates more completions than that maximum that the CQ can hold were attempted to be queued on the CQ and the CQ is unusable. All of the associated queue pairs (QPs) are also unusable. No future completions will be reported. A STATUS_BUFFER_OVERFLOW error usually indicates a programming error. |
| STATUS_INTERNAL_ERROR | Indicates a fatal error occurred on the CQ and the CQ is unusable. All of the associated queue pairs (QPs) are also unusable. No future completions will be reported. A STATUS_INTERNAL_ERROR error usually indicates a hardware error. |

## Remarks

An NDK provider calls *NdkCqNotificationCallback* to notify the consumer about a completion queue (CQ) event.

The NDK consumer specified the *NdkCqNotificationCallback* function in the *CqNotificationContext* parameter of the *NdkCreateCq* ([NDK_FN_CREATE_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_cq)) function when the completion queue (CQ) object was created.

## See also

[NDKPI Completion Handling Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-completion-handling-requirements)

[NDK_FN_CREATE_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_cq)