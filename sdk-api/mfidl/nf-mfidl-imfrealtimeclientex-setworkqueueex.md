# IMFRealTimeClientEx::SetWorkQueueEx

## Description

Specifies the work queue that this object should use for asynchronous work items.

## Parameters

### `dwMultithreadedWorkQueueId`

The work queue identifier.

### `lWorkItemBasePriority`

The base priority for work items.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The object should use the values of *dwMultithreadedWorkQueueId* and *lWorkItemBasePriority* when it queues new work items. Use the [MFPutWorkItem2](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfputworkitem2) or [MFPutWorkItemEx2](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfputworkitemex2) function to queue the work item.

## See also

[IMFRealTimeClientEx](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfrealtimeclientex)

[Work Queue and Threading Improvements](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-work-queue-and-threading-improvements)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)