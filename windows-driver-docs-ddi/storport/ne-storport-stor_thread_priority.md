## Description

**STOR_THREAD_PRIORITY** specifies the priority for a StorPort miniport-created thread.

## Constants

### `StorThreadPriorityBackground`

System priority level. The assigned priority level is 7.

### `StorThreadPriorityNormal`

System priority level. The assigned priority level is 8.

### `StorThreadPriorityDelayed`

Indicates an ordinary worker thread. The assigned priority level is 12.

### `StorThreadPriorityCritical`

Indicates a real-time system worker thread. The assigned priority level is 13.

### `StorThreadPrioritySuperCritical`

System priority level. The assigned priority level is 14.

### `StorThreadPriorityHyperCritical`

System priority level. The assigned priority level is 15.

### `StorThreadPriorityRealTime`

System priority level. The assigned priority level is 18.

## Remarks

A miniport sets thread priority when it calls [**StorPortCreateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcreatesystemthread) to create a thread, and can change thread priority in [**StorPortSetPriorityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetprioritythread).

Every thread has a scheduling priority (its thread priority). Higher values indicate higher priority threads.

See [Thread Priorities](https://learn.microsoft.com/windows-hardware/drivers/kernel/thread-priorities) for general information.

## See also

[**StorPortCreateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcreatesystemthread)

[**StorPortSetPriorityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetprioritythread)