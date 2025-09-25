# RxPostToWorkerThread function

## Description

**RxPostToWorkerThread** invokes a routine passed as a parameter in the context of a worker thread. Memory for the WORK_QUEUE_ITEM must be allocated by the caller.

## Parameters

### `pMRxDeviceObject` [in]

A pointer to the device object of the corresponding network mini-redirector driver.

### `WorkQueueType` [in]

The type of the work queue that represents the priority of the task. This parameter can be one of the following values:

#### CriticalWorkQueue

Insert WORK_QUEUE_ITEM into the queue from which a system thread with a real-time priority attribute will process the work item.

#### DelayedWorkQueue

Insert WORK_QUEUE_ITEM into the queue from which a system thread with a variable priority attribute will process the work item.

#### HyperCriticalWorkQueue

Insert WORK_QUEUE_ITEM into the queue from which a system thread will process the work item so that the routine to invoke is not blocked.

### `pWorkQueueItem` [in]

A pointer to WORK_QUEUE_ITEM.

### `Routine` [in]

A pointer to the routine to invoke.

### `pContext` [in]

A pointer to a context parameter associated with the work item to complete that is passed to the driver.

## Return value

**RxDispatchToWorkerThread** returns STATUS_SUCCESS on success or one of the following error code on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The item could not be dispatched. |

## Remarks

There are two common cases of dispatching operations to worker threads. The trade-off between the following two dispatching operations is time versus space (memory usage):

* When an operation is going to be repeatedly dispatched, time is conserved by allocating in advance the WORK_QUEUE_ITEM structure as part of the data structure to be dispatched. In this case, use the **RxPostToWorkerThread** routine.
* For an infrequent operation, you can conserve space by dynamically allocating and freeing memory for the work queue item when it is needed. In this case, use the [RxDispatchToWorkerThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxdispatchtoworkerthread) routine.

The **RxPostToWorkerThread** routine invokes a routine in the context of a worker thread. The memory for the WORK_QUEUE_ITEM structure must be allocated from non-paged pool memory by the calling routine.

The current implementation of the **RxPostToWorkerThread** routine queues work onto the same processor from which the call originated.

If the **RxPostToWorkerThread** routine fails on a debug build, the [_RxLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxlog/nf-rxlog-_rxlog) routine is called with details of the error. If the **RxPostToWorkerThread** routine fails and WMI is enabled in the kernel, details of the error will be logged with WMI.

## See also

[RxDispatchToWorkerThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxdispatchtoworkerthread)

[RxSpinDownMRxDispatcher](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxspindownmrxdispatcher)

[_RxLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxlog/nf-rxlog-_rxlog)