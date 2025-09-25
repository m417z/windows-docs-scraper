## Description

The **KeSetCoalescableTimer** routine sets the initial expiration time and period of a timer object and specifies how much delay can be tolerated in the expiration times.

## Parameters

### `Timer` [in, out]

A pointer to a timer object. This parameter points to a [KTIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure, which is an opaque, system structure that represents the timer object. This object must have been previously initialized by the [KeInitializeTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimerex) or [KeInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimer) routine.

### `DueTime` [in]

Specifies an absolute or relative time at which the timer is to expire. If the value of the *DueTime* parameter is negative, the expiration time is relative to the current system time. Otherwise, the expiration time is absolute. The expiration time is expressed in system time units, which are 100-nanosecond intervals. Absolute expiration times track any changes that are made to the system clock. Relative expiration times are not affected by system clock changes.

### `Period` [in]

Specifies the interval between periodic timer expirations in milliseconds. The value of this parameter must not exceed MAXLONG. This parameter is optional and can be set to zero to indicate that the timer is nonperiodic.

### `TolerableDelay` [in]

Specifies a tolerance, in milliseconds, for the timer period that *Period* specifies and for the initial time interval that *DueTime* specifies. For a periodic timer, the time interval between two successive timer expirations will be in the range from (*Period* - *TolerableDelay*) to (*Period* + *TolerableDelay*). The initial expiration time will be in the range from *DueTime* to (*DueTime* + *TolerableDelay*). The *TolerableDelay* value cannot be negative.

### `Dpc` [in, optional]

A pointer to a DPC object. This parameter points to a [KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure, which is an opaque, system structure that represents the DPC object. This object must have been previously initialized by the [KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc) routine. This parameter is optional and can be specified as **NULL** if the caller does not require a DPC.

## Return value

**KeSetCoalescableTimer** returns **TRUE** if the timer object was already in the system timer queue. Otherwise, it returns **FALSE**.

## Remarks

This routine does the following:

- Sets the timer to a non-signaled state.

- Associates the timer with the DPC, if a DPC is specified.

- Cancels the timer if it is already active.

- Makes the timer active and sets the due time and period of the timer to the specified values. The timer can expire immediately if the specified due time has already passed.

The [KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex) routine is similar to **KeSetCoalescableTimer** but does not accept a *TolerableDelay* parameter. The *TolerableDelay* parameter of **KeSetCoalescableTimer** enables the caller to specify a tolerance for the timer period. A call to **KeSetCoalescableTimer** with *TolerableDelay* = 0 is the same as a call to **KeSetTimerEx**. In many instances, developers can easily modify existing drivers by replacing calls to **KeSetTimerEx** with calls to **KeSetCoalescableTimer**.

If two **KeSetCoalescableTimer** calls specify the same timer object, and the second call occurs before the *DueTime* that is specified for the first call expires, the second call implicitly cancels the timer from the first call. However, if a timer expiration from the first call has already enabled a DPC to run, the DPC might run after the timer is canceled. The second call replaces the pending expiration time from the first call with a new expiration time, and activates the timer again.

If the *Period* parameter is nonzero, the timer is periodic. For a periodic timer, the first timer expiration occurs at the time indicated by the *DueTime* parameter. Later expirations are separated by the interval that is specified by *Period*. If *Period* = 0, the timer is nonperiodic and expires at the time that is indicated by *DueTime*.

If the *Dpc* parameter is non-**NULL**, the routine creates an association between the specified DPC object and the timer object. After the timer expires, the timer service removes the timer object from the system timer queue and sets this object to a signaled state. If a DPC object is associated with the timer object, the timer service inserts the DPC object into the system DPC queue to run as soon as conditions allow.

Only one instance of a particular DPC object can be in the system DPC queue at a time. To avoid potential race conditions, avoid passing the same DPC object to both the **KeSetCoalescableTimer** and [KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc) routines.

Avoid changing the importance or the target processor of a DPC that is associated with an active timer. Either cancel the timer or make sure that the timer has expired before you call a routine such as [KeSetImportanceDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesetimportancedpc) or [KeSetTargetProcessorDpcEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettargetprocessordpcex) to change the DPC settings. For example, if a driver updates the target processor of a DPC while a timer enables the DPC to run, the DPC might run on an arbitrary processor.

A periodic timer automatically restarts as soon as it expires. Therefore, in a multiprocessor system, the DPC for a periodic timer might be running on two or more processors at the same time.

Drivers must cancel any active timers in their [Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) routines. Call the [KeCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kecanceltimer) routine to cancel a timer. If a DPC is associated with a timer that is periodic or that might recently have expired, a driver must wait (for example, by calling the [KeFlushQueuedDpcs](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keflushqueueddpcs) routine) to free the DPC and its associated data until all pending DPC executions on all processors finish.

**KeSetCoalescableTimer** uses the *TolerableDelay* parameter to perform timer coalescing. That is, the routine adjusts the expiration times for the timer to coincide with the expiration times of other software timers. Timer coalescing helps increase the length of idle periods so that the operating system can reduce power consumption and improve energy efficiency.

To use timer coalescing effectively, a caller should specify a *TolerableDelay* value of at least 32 milliseconds. This value equals two default system clock intervals of 15.6 milliseconds. If you can, use a larger *TolerableDelay* value, such as 100 milliseconds.

Try to specify the *Period* and *TolerableDelay* values in multiples of 50 milliseconds. Typical *Period* values are 50, 100, 250, 500, and 1000 milliseconds. Typical *TolerableDelay* values are 50, 100, 150, and 250 milliseconds.

Typically, a timer with a large *Period* value can use a proportionally large *TolerableDelay* value. For example, a timer with *Period* = 500 milliseconds might use *TolerableDelay* = 50 milliseconds, but a timer with *Period* = 10 seconds might use *TolerableDelay* = 1 second.

Expiration times are measured relative to the system clock, and the accuracy with which the operating system can detect when a timer expires is limited by the granularity of the system clock. For more information, see [Timer Accuracy](https://learn.microsoft.com/windows-hardware/drivers/kernel/timer-accuracy).

For more information about timer objects, see [Timer Objects and DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/timer-objects-and-dpcs). For more information about timer coalescing, see the [Windows Timer Coalescing](https://download.microsoft.com/download/9/C/5/9C5B2167-8017-4BAE-9FDE-D599BAC8184A/TimerCoal.docx) white paper on the WHDC website.

## See also

[KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KTIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KeCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kecanceltimer)

[KeFlushQueuedDpcs](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keflushqueueddpcs)

[KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc)

[KeInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimer)

[KeInitializeTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimerex)

[KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc)

[KeSetImportanceDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesetimportancedpc)

[KeSetTargetProcessorDpcEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettargetprocessordpcex)

[KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex)

[Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload)