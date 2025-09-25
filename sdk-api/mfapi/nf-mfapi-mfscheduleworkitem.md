# MFScheduleWorkItem function

## Description

Schedules an asynchronous operation to be completed after a specified interval.

## Parameters

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface. The caller must implement this interface.

### `pState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

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

This function creates an asynchronous result object. When the timer interval elapses, the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method specified by *pCallback* is called.

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[MFScheduleWorkItemEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfscheduleworkitemex)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)