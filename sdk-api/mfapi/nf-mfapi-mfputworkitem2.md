# MFPutWorkItem2 function

## Description

Puts an asynchronous operation on a work queue, with a specified priority.

## Parameters

### `dwQueue` [in]

The identifier for the work queue. This value can specify one of the standard Media Foundation work queues, or a work queue created by the application. For list of standard Media Foundation work queues, see [Work Queue Identifiers](https://learn.microsoft.com/windows/desktop/medfound/work-queue-identifiers). To create a new work queue, call [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) or MFAllocateWorkQueueEx.

### `Priority` [in]

The priority of the work item. Work items are performed in order of priority.

### `pCallback` [in]

A pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface. The caller must implement this interface.

### `pState` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Success. |
| ****MF_E_INVALID_WORKQUEUE**** | Invalid work queue identifier. |
| **MF_E_SHUTDOWN** | The [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup) function was not called, or [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown) was called. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queue and Threading Improvements](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-work-queue-and-threading-improvements)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)