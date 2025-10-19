# MFPutWorkItemEx2 function

## Description

Puts an asynchronous operation on a work queue, with a specified priority.

## Parameters

### `dwQueue` [in]

The identifier for the work queue. This value can specify one of the standard Media Foundation work queues, or a work queue created by the application. For list of standard Media Foundation work queues, see [Work Queue Identifiers](https://learn.microsoft.com/windows/desktop/medfound/work-queue-identifiers). To create a new work queue, call [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) or [MFAllocateWorkQueueEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueueex).

### `Priority` [in]

The priority of the work item. This value should be 1, 0, or -1. Items with a value of 1 are executed before items with a value of 0. Items with a value of -1 are executed after items with a value of 0.

### `pResult` [in]

A pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface of an asynchronous result object. To create the result object, call [MFCreateAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateasyncresult).

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALID_WORKQUEUE** | Invalid work queue identifier. |
| **MF_E_SHUTDOWN** | The [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup) function was not called, or [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown) was called. |

## Remarks

To invoke the work item, this function passes *pResult* to the [MFInvokeCallback](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfinvokecallback) function. The callback is specified when you create the result object specified by *pResult*.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queue and Threading Improvements](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-work-queue-and-threading-improvements)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)