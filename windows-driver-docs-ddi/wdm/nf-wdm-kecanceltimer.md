# KeCancelTimer function

## Description

The **KeCancelTimer** routine dequeues a timer object before the timer interval, if any was set, expires.

## Parameters

### `unnamedParam1` [in, out]

Pointer to an initialized timer object, for which the caller provides the storage.

## Return value

If the specified timer object is in the system timer queue, **KeCancelTimer** returns **TRUE**.

## Remarks

If the timer object is currently in the system timer queue, it is removed from the queue. If a DPC object is associated with the timer, it too is canceled. Otherwise, no operation is performed.

The routine returns **TRUE** if the timer is still in the timer queue. A nonperiodic timer is removed from the system queue as soon as it expires. Thus, for nonperiodic timers, **KeCancelTimer** returns **FALSE** if the timer DPC has been queued. Periodic timers are always in the timer queue, so **KeCancelTimer** always returns **TRUE** for periodic timers.

Note that a DPC that is already running runs to completion. The driver must ensure that the DPC has completed before freeing any resources used by the DPC. For a nonperiodic timer, you can use synchronization primitives, such as event objects, to synchronize between the driver and the DPC. The driver can check the return code of **KeCancelTimer** to determine if the DPC is running. If so, the DPC can signal the event before exiting, and the driver can wait for that event to be reset to the not-signaled state.

Since for periodic timers **KeCancelTimer** always returns **TRUE**, drivers must use a different technique to wait until the DPC has completed. Use the [KeFlushQueuedDpcs](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keflushqueueddpcs) routine to block until the DPC executes.

Drivers do not need to synchronize for data stored in global variables or driver object extensions. The system automatically calls **KeFlushQueuedDpcs** before deallocating either of these regions.

For more information about timer objects, see [Timer Objects and DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/timer-objects-and-dpcs).

## See also

[KeInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimer)

[KeReadStateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereadstatetimer)

[KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer)