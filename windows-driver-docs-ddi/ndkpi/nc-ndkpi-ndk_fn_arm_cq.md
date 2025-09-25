# NDK_FN_ARM_CQ callback function

## Description

The *NdkArmCq* (*NDK_FN_ARM_CQ*) function arms an NDK completion queue (CQ) notification.

## Parameters

### `pNdkCq` [in]

A pointer to an NDK completion queue object ([NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)).

### `Type` [in]

The type of notification to arm. The following notification types are defined:

| Term | Description |
| --- | --- |
| NDK_CQ_NOTIFY_ERRORS | Notify if there are any completion queue errors such as a completion queue overrun or catastrophic failure. |
| NDK_CQ_NOTIFY_ANY | Notify of the next successful completion in the completion queue. |
| NDK_CQ_NOTIFY_SOLICITED | Notify when the completion queue receives a send request that includes the ND_OP_FLAG_SEND_AND_SOLICIT_EVENT flag. |

## Remarks

After the NDK consumer arms a completion queue (CQ) notification, the provider calls the *NdkCqNotificationCallback* callback function (the [NDK_FN_CQ_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_cq_notification_callback) routine that the consumer specified when the CQ was created with the *NdkCreateCq* ([NDK_FN_CREATE_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_cq)) function) when the specified type of notification is due.

If the CQ is closed while a call to *NdkCqNotificationCallback* is in-progress, the close request will remain pending until *NdkCqNotificationCallback* returns control to the provider. After the close request is completed, the provider will not call *NdkCqNotificationCallback*.

## See also

[NDKPI Completion Handling Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-completion-handling-requirements)

[NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)

[NDK_CQ_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq_dispatch)

[NDK_FN_CQ_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_cq_notification_callback)

[NDK_FN_CREATE_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_cq)