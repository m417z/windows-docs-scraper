# NDK_FN_SRQ_NOTIFICATION_CALLBACK callback function

## Description

The *NdkSrqNotificationCallback* (*NDK_FN_SRQ_NOTIFICATION_CALLBACK*) function provides NDK shared receive queue (SRQ) notifications from an NDK provider.

## Parameters

### `SrqNotificationContext` [in, optional]

A context area that was specified in the *SrqNotificationContext* parameter of the *NdkCreateSrq* ([NDK_FN_CREATE_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_srq)) function when the SRQ object was created.

### `SrqStatus` [in]

Indicates if a fatal SRQ error occurred. The following status codes are defined:

| Term | Description |
| --- | --- |
| STATUS_SUCCESS | The SRQ is operating normally. |
| STATUS_INTERNAL_ERROR | A catastrophic error occurred on the SRQ. The SRQ is unusable. All of the associated queue pairs (QPs) are also unusable. No future completions will be reported. This error usually indicates a hardware error. |

## Remarks

**Note** This routine is implemented by the NDK consumer and passed to the NDK provider.

An NDK provider calls the *NdkSrqNotificationCallback* function when the number of receive requests that are queued on the SRQ falls below the minimum number of queued receive requests (*NotifyThreshold*). The *NotifyThreshold* is an input parameter to the *NdkCreateSrq* ([NDK_FN_CREATE_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_srq)) and *NdkModifySrq* ([NDK_FN_MODIFY_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_modify_srq)) functions.