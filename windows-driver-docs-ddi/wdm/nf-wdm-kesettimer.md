# KeSetTimer function

## Description

The **KeSetTimer** routine sets the absolute or relative interval at which a timer object is to be set to a signaled state and, optionally, supplies a [CustomTimerDpc](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-a-customtimerdpc-routine) routine to be executed when that interval expires.

## Parameters

### `Timer` [in, out]

Pointer to a timer object that was initialized with [KeInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimer) or [KeInitializeTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimerex).

### `DueTime` [in]

Specifies the absolute or relative time at which the timer is to expire. If the value of the *DueTime* parameter is negative, the expiration time is relative to the current system time. Otherwise, the expiration time is absolute. The expiration time is expressed in system time units (100-nanosecond intervals). Absolute expiration times track any changes in the system time; relative expiration times are not affected by system time changes.

### `Dpc` [in, optional]

Pointer to a DPC object that was initialized by [KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc). This parameter is optional.

## Return value

If the timer object was already in the system timer queue, **KeSetTimer** returns **TRUE**.

## Remarks

The **KeSetTimer** routine does the following:

- Computes the expiration time.

- Sets the timer to a not-signaled state.

- Inserts the timer object in the system timer queue.

If the timer object was already in the timer queue, it is implicitly canceled before being set to the new expiration time. A call to **KeSetTimer** before the previously specified *DueTime* has expired cancels both the timer and the call to the *Dpc*, if any, associated with the previous call.

If the *Dpc* parameter is specified, a DPC object is associated with the timer object. When the timer expires, the timer object is removed from the system timer queue and its state is set to signaled. If a DPC object was associated with the timer when it was set, the DPC object is inserted in the system DPC queue to be executed as soon as conditions permit after the timer interval expires.

Expiration times are measured relative to the system clock, and the accuracy with which the operating system can detect when a timer expires is limited by the granularity of the system clock. For more information, see [Timer Accuracy](https://learn.microsoft.com/windows-hardware/drivers/kernel/timer-accuracy).

Only one instantiation of a given DPC object can be queued at any given moment. To avoid potential race conditions, the DPC passed to **KeSetTimer** should not be passed to [KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc).

Drivers must cancel any active timers in their [Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) routines. Use [KeCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kecanceltimer) to cancel any timers.

Callers of **KeSetTimer** can specify one expiration time for a timer. To set a recurring timer use [KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex).

For more information about timer objects, see [Timer Objects and DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/timer-objects-and-dpcs).

## See also

[KeCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kecanceltimer)

[KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc)

[KeInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimer)

[KeInitializeTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimerex)

[KeReadStateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereadstatetimer)

[KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex)

[KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects)