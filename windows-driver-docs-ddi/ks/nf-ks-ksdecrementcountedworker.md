# KsDecrementCountedWorker function

## Description

Decrements the current worker count of a worker previous created by [KsRegisterCountedWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregistercountedworker). This should be called after each task within a worker has been completed.

## Parameters

### `Worker` [in]

Contains the previously allocated worker.

## Return value

Returns the current counter. A count of zero implies that the task list has been completed.

## Remarks

**KsDecrementCountedWorker** should be called after each task within a worker has been completed. A corresponding call to [KsIncrementCountedWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksincrementcountedworker) would have previously incremented the count. **KsDecrementCountedWorker** may be called at DISPATCH_LEVEL.

## See also

[KsIncrementCountedWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksincrementcountedworker)

[KsRegisterCountedWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregistercountedworker)