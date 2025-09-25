# MFBeginRegisterWorkQueueWithMMCSSEx function

## Description

Associates a work queue with a Multimedia Class Scheduler Service (MMCSS) task.

## Parameters

### `dwWorkQueueId` [in]

The identifier of the work queue. For private work queues, the identifier is returned by the [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) function. For platform work queues, see [Work Queue Identifiers](https://learn.microsoft.com/windows/desktop/medfound/work-queue-identifiers).

### `wszClass` [in]

The name of the MMCSS task. For more information, see [Multimedia Class Scheduler Service](https://learn.microsoft.com/windows/desktop/ProcThread/multimedia-class-scheduler-service).

### `dwTaskId` [in]

The unique task identifier. To obtain a new task identifier, set this value to zero.

### `lPriority` [in]

The base relative priority for the work-queue threads. For more information, see [AvSetMmThreadPriority](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmthreadpriority).

### `pDoneCallback` [in]

A pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `pDoneState` [in]

A pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function extends the [MFBeginRegisterWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfbeginregisterworkqueuewithmmcss) function by adding the *lPriority* parameter.

This function is asynchronous. When the operation completes, the callback object's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method is called. At that point, call [MFEndRegisterWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfendregisterworkqueuewithmmcss) to complete the asynchronous request.

To unregister the work queue from the MMCSS task, call [MFBeginUnregisterWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfbeginunregisterworkqueuewithmmcss).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queue and Threading Improvements](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-work-queue-and-threading-improvements)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)