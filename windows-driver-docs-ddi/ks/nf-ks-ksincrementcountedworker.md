# KsIncrementCountedWorker function

## Description

Increments the current worker count, and optionally queues the counted work item with the worker previously created by [KsRegisterCountedWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregistercountedworker).

## Parameters

### `Worker` [in]

Contains the previously allocated worker.

## Return value

Returns the current counter. A count of one implies that a worker was actually scheduled.

## Remarks

This should be called after an addition has been made to the worker's list of tasks to perform. A corresponding call to [KsDecrementCountedWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdecrementcountedworker) should be made within the work item after each task has been completed. This may be called at DISPATCH_LEVEL.

## See also

[KsDecrementCountedWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdecrementcountedworker)

[KsRegisterCountedWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregistercountedworker)