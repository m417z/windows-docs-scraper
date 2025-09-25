# MFBeginUnregisterWorkQueueWithMMCSS function

## Description

Unregisters a work queue from a Multimedia Class Scheduler Service (MMCSS) task.

## Parameters

### `dwWorkQueueId` [in]

The identifier of the work queue. For private work queues, the identifier is returned by the [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) function. For platform work queues, see [Work Queue Identifiers](https://learn.microsoft.com/windows/desktop/medfound/work-queue-identifiers).

### `pDoneCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `pDoneState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

This function unregisters a work queue that was associated with an MMCSS class through the [MFBeginRegisterWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfbeginregisterworkqueuewithmmcss) function.

This function is asynchronous. When the operation completes, the callback object's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method is called. At that point, the application should call [MFEndUnregisterWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfendunregisterworkqueuewithmmcss) to complete the asynchronous request.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)