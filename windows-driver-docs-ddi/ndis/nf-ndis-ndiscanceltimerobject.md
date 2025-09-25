# NdisCancelTimerObject function

## Description

The
**NdisCancelTimerObject** function cancels a timer object that is associated with a previous call to the
[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject) function.

## Parameters

### `TimerObject` [in]

A handle to a timer object that NDIS provides when a driver calls the
[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject) function.

## Return value

**NdisCancelTimerObject** returns **TRUE** if the specified timer object is in the system timer queue;
otherwise, it returns **FALSE**.

## Remarks

A call to
**NdisCancelTimerObject** cancels execution of a
[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function) function, provided
that the last specified timeout interval has not yet expired.

NDIS drivers should call
**NdisCancelTimerObject** first when they are halting or unloading to ensure that a
*NetTimerCallback* function does not attempt to access resources that the driver has already
released.

If a nonzero value was specified in the
*MillisecondsPeriod* parameter of the
[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject) function, the timer is known as a *periodic timer*. If a zero value was specified in the *MillisecondsPeriod* parameter, the timer is known as a *one-shot timer*. The following points apply to canceling both types of timers:

* If the caller of
  **NdisCancelTimerObject** is canceling a periodic timer, it must be running at IRQL = PASSIVE_LEVEL. Otherwise, the caller of
  **NdisCancelTimerObject** should be running at IRQL <= DISPATCH_LEVEL.
* If the caller of
  **NdisCancelTimerObject** is canceling a periodic timer, **NdisCancelTimerObject** calls [KeFlushQueuedDpcs](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keflushqueueddpcs) to ensure that the timer is not currently running. Therefore, the caller is not required to have a separate synchronization mechanism to ensure that the timer is not currently being executed on another processor.

  If the caller of
  **NdisCancelTimerObject** is canceling a one-shot timer, the caller is required to have a separate synchronization mechanism to ensure the timer is not currently running on another processor. For example, the caller could call [NDIS_WAIT_FOR_MUTEX](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-wait-for-mutex) in order to wait for the timer thread to signal a mutex object when the thread is about to complete.

  For more information, see [Synchronization and Notification in Network Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/synchronization-and-notification-in-network-drivers).

## See also

[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject)

[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject)

[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function)