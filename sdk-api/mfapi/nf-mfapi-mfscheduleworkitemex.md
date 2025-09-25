# MFScheduleWorkItemEx function

## Description

Schedules an asynchronous operation to be completed after a specified interval.

## Parameters

### `pResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface of an asynchronous result object. To create the result object, call [MFCreateAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateasyncresult).

### `Timeout` [in]

Time-out interval, in milliseconds. Set this parameter to a negative value. The callback is invoked after −*Timeout* milliseconds. For example, if *Timeout* is −5000, the callback is invoked after 5000 milliseconds.

### `pKey` [out]

Receives a key that can be used to cancel the timer. To cancel the timer, call [MFCancelWorkItem](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcancelworkitem) and pass this key in the *Key* parameter.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

When the timer interval elapses, the timer calls [MFInvokeCallback](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfinvokecallback) with the *pResult* pointer to invoke the asynchronous callback. The callback is specified when you create the result object.

## See also

[MFScheduleWorkItem](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfscheduleworkitem)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)