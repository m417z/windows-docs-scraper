# KsRegisterCountedWorker function

## Description

Handles clients registering for use of a thread.

## Parameters

### `WorkQueueType` [in]

Contains the priority of the work thread. This is normally one of the following: CriticalWorkQueue, DelayedWorkQueue, or HyperCriticalWorkQueue.

### `CountedWorkItem` [in]

Contains a pointer to the work queue item that will be queued as needed based on the current count value.

### `Worker` [out]

Contains the opaque context that must be used when scheduling a work item. Also contains the queue type, and is used to synchronize completion of work items.

## Return value

Returns STATUS_SUCCESS if a worker was initialized.

## Remarks

This must be matched by a corresponding [KsUnregisterWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksunregisterworker) when thread use is completed. This function resembles [KsRegisterWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisterworker), with the addition of passing the work item that will always be queued. This is to be used with [KsIncrementCountedWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksincrementcountedworker) and [KsDecrementCountedWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdecrementcountedworker) in order to minimize the number of work items queued, and reduce mutual exclusion code necessary in a work item needed to serialize access against multiple work item threads. The worker queue can still be used to queue other work items. This may only be called at PASSIVE_LEVEL.