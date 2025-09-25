# MFLockSharedWorkQueue function

## Description

Obtains and locks a shared work queue.

## Parameters

### `wszClass` [in]

The name of the MMCSS task.

### `BasePriority` [in]

The base priority of the work-queue threads.

If the regular-priority queue is being used (*wszClass*=""), then the value 0 must be passed in.

### `pdwTaskId` [in, out]

The MMCSS task identifier. On input, specify an existing MCCSS task group ID , or use the value zero to create a new task group. If the regular priority queue is being used (*wszClass*=""), then **NULL** must be passed in. On output, receives the actual task group ID.

### `pID` [out]

Receives an identifier for the new work queue. Use this identifier when queuing work items.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A *multithreaded work queue* uses a thread pool to dispatch work items. Whenever a thread becomes available, it dequeues the next work item from the queue. Work items are dequeued in first-in-first-out order, but work items are not serialized. In other words, the work queue does not wait for a work item to complete before it starts the next work item.

Within a single process, the Microsoft Media Foundation platform creates up to one multithreaded queue for each Multimedia Class Scheduler Service (MMCSS) task. The **MFLockSharedWorkQueue** function checks whether a matching work queue already exists. If not, the function creates a new work queue and registers the work queue with MMCSS. The function returns the MMCSS task identifier (*pdwTaskId*) and the work queue identifier (*pID*). To queue a work item, pass the work queue identifier to any of the following functions:

* [MFPutWorkItem](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfputworkitem)
* [MFPutWorkItem2](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfputworkitem2)
* [MFPutWorkItemEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfputworkitemex)
* [MFPutWorkItemEx2](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfputworkitemex2)

The **MFLockSharedWorkQueue** function also locks the queue. Before the process exits, call [MFUnlockWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfunlockworkqueue) to unlock the work queue.

If the regular priority queue is being used (*wszClass*=""), then NULL must be passed in to *pdwTaskId* and the value 0 must be passed into *BasePriority*.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queue and Threading Improvements](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-work-queue-and-threading-improvements)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)