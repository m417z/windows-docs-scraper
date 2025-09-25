# _WORK_QUEUE_TYPE enumeration

## Description

The **WORK_QUEUE_TYPE** enumeration type indicates the type of system worker thread that handles a work item.

## Constants

### `CriticalWorkQueue`

Indicates a real-time system worker thread. The assigned priority level is 13.

### `DelayedWorkQueue`

Indicates an ordinary worker thread. The assigned priority level is 12.

### `HyperCriticalWorkQueue`

System priority level. The assigned priority level is 15.

### `NormalWorkQueue`

System priority level. The assigned priority level is 8

### `BackgroundWorkQueue`

System priority level. The assigned priority level is 7.

### `RealTimeWorkQueue`

System priority level. The assigned priority level is18.

### `SuperCriticalWorkQueue`

System priority level. The assigned priority level is 14.

### `MaximumWorkQueue`

System priority maximum. No priority level assigned.

### `CustomPriorityWorkQueue`

The queue has a custom priority level assigned by the caller. The **CustomPriorityWorkQueue** value is the base priority level for the custom priority queue. Work items are queued at a particular priority by setting *QueueType* to **CustomPriorityWorkQueue** + *Priority* where *Priority* is the **KPRIORITY** value for the work item.

This queue type is valid starting with Windows 8.1.

## Remarks

For drivers targeting Windows 8.1 or later versions of Windows, use of only **CustomPriorityWorkQueue** with a custom priority level is recommended.

 A work queue priority < 17 is advised since queuing
at a higher priority may interfere with work item processing by critical system components.

For more information about system worker threads, see [System Worker Threads](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-worker-threads).

## See also

[IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem)

[IoQueueWorkItemEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitemex)

[IoTryQueueWorkItem](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn683917(v=vs.85))