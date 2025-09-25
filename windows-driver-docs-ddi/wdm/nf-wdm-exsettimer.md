# ExSetTimer function

## Description

The **ExSetTimer** routine starts a timer operation and sets the timer to expire at the specified due time.

## Parameters

### `Timer` [in]

A pointer to an [EX_TIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects) structure. This structure is a timer object that was previously allocated by the [ExAllocateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatetimer) routine.

### `DueTime` [in]

The absolute or relative time at which the timer is to expire. If the value of the *DueTime* parameter is negative, the expiration time is relative to the current system time. Otherwise, the expiration time is absolute. The expiration time is expressed in system time units (100-nanosecond intervals). Absolute expiration times track any changes in the system time; relative expiration times are not affected by system time changes. An absolute time is expressed as the amount of time passed, in system time units, since the start of the year 1601.

The *DueTime* parameter for a [high-resolution timer](https://learn.microsoft.com/windows-hardware/drivers/kernel/high-resolution-timers) must be a relative time (negative value), or the routine bug checks.

### `Period` [in]

An optional period for the timer in system time units (100-nanosecond intervals). Must be less than or equal to MAXLONG. For a timer that is one-shot instead of periodic, set *Period* to zero.

### `Parameters` [in, optional]

A pointer to an [EXT_SET_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ext_set_parameters_v0) structure. The calling driver previously called the [ExInitializeSetTimerParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializesettimerparameters) routine to initialize this structure.

## Return value

This routine returns **TRUE** if it cancels a timer that was pending at the time that the routine was called. Otherwise, the routine returns **FALSE**. For more information, see Remarks.

## Remarks

Your driver can call this routine to set a timer to expire at a future time. The driver can then wait for the timer to expire. Or, the driver can implement a callback routine that is called when the timer expires.

After a driver calls **ExSetTimer**, the driver can call a routine such as [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject) or [KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects) to wait for the timer to expire. When the timer expires, the operating system signals the timer object.

As an option, the driver can implement an [ExTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ext_callback) callback routine, and supply a pointer to this routine as an input parameter to the [ExAllocateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatetimer) routine. When the timer expires, the operating system calls the *ExTimerCallback* routine.

An **ExSetTimer** call implicitly cancels any previously started set-timer operation on the timer object specified by *Timer*. If your driver previously called **ExSetTimer** to set a timer that uses *Timer*, and this timer has not yet expired when **ExSetTimer** is called a second time, the second call cancels the timer from the first call and then starts the new timer. In this case, the second call returns **TRUE**. However, if the timer started by the first call expires before the second call can cancel this timer, the second call starts the new timer and returns **FALSE**.

If the *Period* parameter is nonzero, the timer is periodic. For a periodic timer, the *DueTime* parameter specifies the time of the initial timer expiration, and *Period* specifies the interval between subsequent expirations.

The hardware timer used for the system clock signals interrupt requests at uniform intervals, but the handling of these interrupts might be delayed by interrupt processing for other devices. Thus, for a periodic timer, the delay from a periodic expiration time to the time at which the timer object is signaled or the *ExTimerCallback* routine runs might vary from one period to the next. For more information, see [Timer Accuracy](https://learn.microsoft.com/windows-hardware/drivers/kernel/timer-accuracy).

A periodic timer can expire no more than once per system clock tick. Setting the period of a timer to a value smaller than the interval between system clock ticks does not cause the timer to expire more than once per system clock tick, but might cause the intervals between successive expirations to vary if the system clock rate changes. For example, the operating system might temporarily increase the system clock rate to meet the timing requirements of a high-resolution timer. For more information, see [High-Resolution Timers](https://learn.microsoft.com/windows-hardware/drivers/kernel/high-resolution-timers).

For a periodic timer that is not a high-resolution timer, a driver can achieve relatively uniform periodic expirations by setting *Period* to an integer multiple of the default interval between system clock ticks.

To avoid excessive power consumption, a driver should not set the period of a long-running high-resolution timer to a value less than the default interval between system clock ticks. Otherwise, the system clock timer will continuously generate interrupts at the maximum allowed system clock rate.

For more information, see [ExXxxTimer Routines and EX_TIMER Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects).

## See also

[EXT_SET_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ext_set_parameters_v0)

[EX_TIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects)

[ExAllocateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatetimer)

[ExInitializeSetTimerParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializesettimerparameters)

[ExTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ext_callback)

[KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)