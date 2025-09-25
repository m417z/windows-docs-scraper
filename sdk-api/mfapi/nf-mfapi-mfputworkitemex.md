# MFPutWorkItemEx function

## Description

Puts an asynchronous operation on a work queue.

## Parameters

### `dwQueue` [in]

The identifier for the work queue. This value can specify one of the standard Media Foundation work queues, or a work queue created by the application. For list of standard Media Foundation work queues, see [Work Queue Identifiers](https://learn.microsoft.com/windows/desktop/medfound/work-queue-identifiers). To create a new work queue, call [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) or [MFAllocateWorkQueueEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueueex).

### `pResult` [in]

A pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface of an asynchronous result object. To create the result object, call [MFCreateAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateasyncresult).

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Success. |
| ****MF_E_INVALID_WORKQUEUE**** | Invalid work queue identifier. For more information, see [IMFAsyncCallback::GetParameters](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-getparameters). |
| **MF_E_SHUTDOWN** | The [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup) function was not called, or [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown) was called. |

## Remarks

To invoke the work-item, this function passes *pResult* to the [MFInvokeCallback](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfinvokecallback) function. The callback is specified when you create the result object specified by *pResult*.

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[MFPutWorkItem](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfputworkitem)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)