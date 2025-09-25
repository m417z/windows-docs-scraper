# KsUnregisterWorker function

## Description

The **KsUnregisterWorker** function allows clients to unregister a worker. The function can destroy threads, depending on the number of threads in use. This must only be used after successful execution of **KsRegisterWorker**. The function can only be called at PASSIVE_LEVEL.

## Parameters

### `Worker` [in]

Specifies the previously allocated worker to be unregistered. The function will wait until any outstanding work item is completed.

## Return value

None

## Remarks

The client must ensure that outstanding I/O initiated on any worker thread has been completed before unregistering the worker has been completed. This means canceling or completing outstanding I/O either before unregistering the worker, or before the worker item returns from its callback for the last time and is unregistered. Unregistering of a worker will wait for any currently queued work items to complete before returning.