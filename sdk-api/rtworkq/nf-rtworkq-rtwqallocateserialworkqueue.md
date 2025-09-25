# RtwqAllocateSerialWorkQueue function

## Description

Creates a virtual work queue on top of another work queue that is guaranteed to serialize work items. The serial work queue wraps an existing multithreaded work queue. The serial work queue enforces a first-in, first-out (FIFO) execution order.

## Parameters

### `workQueueIdIn` [in]

The identifier of an existing work queue. This must be either a multithreaded queue or another serial work queue. Any of the following can be used:

* The default work queue (**RTWQ_STANDARD_WORKQUEUE**). See [RTWQ_WORKQUEUE_TYPE](https://learn.microsoft.com/windows/desktop/api/rtworkq/ne-rtworkq-rtwq_workqueue_type).
* The platform multithreaded queue (**RTWQ_MULTITHREADED_WORKQUEUE**). See [RTWQ_WORKQUEUE_TYPE](https://learn.microsoft.com/windows/desktop/api/rtworkq/ne-rtworkq-rtwq_workqueue_type).
* A multithreaded queue returned by the [RtwqLockSharedWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqlocksharedworkqueue) function.
* A serial queue created by the **RtwqAllocateSerialWorkQueue** function.

### `workQueueIdOut` [out]

Receives an identifier for the new serial work queue. Use this identifier when queuing work items.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_FAIL** | The application exceeded the maximum number of work queues. |
| **RTWQ_E_SHUTDOWN** | The application did not call [RtwqStartup](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqstartup), or the application has already called [RtwqShutdown](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqshutdown). |

## Remarks

When you are done using the work queue, call [RtwqUnlockWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqunlockworkqueue).

Multithreaded queues use a thread pool, which can reduce the total number of threads in the pipeline. However, they do not serialize work items. A serial work queue enables the application to get the benefits of the thread pool, without needing to perform manual serialization of its own work items.

## See also

[RTWQ_WORKQUEUE_TYPE](https://learn.microsoft.com/windows/desktop/api/rtworkq/ne-rtworkq-rtwq_workqueue_type)