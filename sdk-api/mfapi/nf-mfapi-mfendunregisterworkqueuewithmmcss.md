# MFEndUnregisterWorkQueueWithMMCSS function

## Description

Completes an asynchronous request to unregister a work queue from a Multimedia Class Scheduler Service (MMCSS) task.

## Parameters

### `pResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

Call this function when the [MFBeginUnregisterWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfbeginunregisterworkqueuewithmmcss) function completes asynchronously.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)