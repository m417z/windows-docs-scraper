# RxDispatchToWorkerThread function

## Description

**RxDispatchToWorkerThread** invokes a routine in the context of a worker thread. The memory for the WORK_QUEUE_ITEM is allocated by this routine.

## Parameters

### `pMRxDeviceObject` [in]

A pointer to the device object of the corresponding network mini-redirector driver.

### `WorkQueueType` [in]

The type of the work queue representing the priority of the task. The *WorkQueueType* parameter can be one of can be one of the following enumerations for WORK_QUEUE_TYPE:

#### CriticalWorkQueue

Insert the WORK_QUEUE_ITEM into the queue from which a system thread with a real-time priority attribute will process the work item.

#### DelayedWorkQueue

Insert the WORK_QUEUE_ITEM into the queue from which a system thread with a variable priority attribute will process the work item.

#### HyperCriticalWorkQueue

Insert the WORK_QUEUE_ITEM into the queue from which a system thread will process the work item so that the routine to be invoked is not blocked.

### `Routine` [in]

A pointer to the routine to be invoked.

### `pContext` [in]

A pointer to a context parameter associated with the work item to complete that is passed to the driver.

## Return value

**RxDispatchToWorkerThread** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The item could not be dispatched. |

## Remarks

There are two common cases of dispatching operations to worker threads:

* For a very infrequent operation, space can be conserved by dynamically allocating and freeing memory for the work queue item when its is needed. The **RxDispatchToWorkerThread** routine would be used in this case
* When an operation is going to be repeatedly dispatched, time is conserved by allocating in advance the WORK_QUEUE_ITEM as part of the data structure to be dispatched and using this pre-allocated memory repeatedly. The [RxPostToWorkerThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxposttoworkerthread) routine would be used in this case

The trade off between the two dispatching operations is time versus space (memory usage).

The **RxDispatchToWorkerThread** invokes a routine in the context of a worker thread. The memory for the WORK_QUEUE_ITEM is allocated by the **RxDispatchToWorkerThread** routine from non-paged pool memory. Hence this routine can fail if insufficient resources are available.

The current implementation of the **RxDispatchToWorkerThread** routine queues work onto the same processor from which the call originated.

If the **RxDispatchToWorkerThread** routine fails on a debug build, the **_RxLog** routine is called with details of the error. If the **RxDispatchToWorkerThread** routine fails and WMI is enabled in the kernel, details of the error will be logged with WMI.

## See also

[RxPostToWorkerThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxposttoworkerthread)

[RxSpinDownMRxDispatcher](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxspindownmrxdispatcher)