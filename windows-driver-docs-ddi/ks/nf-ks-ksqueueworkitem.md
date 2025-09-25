# KsQueueWorkItem function

## Description

The **KsQueueWorkItem** function queues the specified work item with a worker previous created by the [KsRegisterWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisterworker) function.

## Parameters

### `Worker` [in]

Specifies the previously allocated worker.

### `WorkItem` [in]

Specifies the initialized work item to queue. This work item is only associated with the worker as long as the worker is on a queue. The work item must have been initialized by [IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem).

## Return value

The **KsQueueWorkItem** function returns STATUS_SUCCESS if the work item was queued, or if unsuccessful the function returns an error when attempting to create a new worker if no threads are currently available.

## Remarks

The worker can only be on a queue in one place, so subsequent queuing of the worker must wait until the work item has begun executing. This function may be called at **DISPATCH_LEVEL**.