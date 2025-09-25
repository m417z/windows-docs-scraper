# ExAllocateTimer function

## Description

The **ExAllocateTimer** routine allocates and initializes a timer object.

## Parameters

### `Callback` [in, optional]

A pointer to a driver-implemented [ExTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ext_callback) callback routine. The operating system calls this routine when the timer expires. This parameter is optional and can be **NULL** if no callback routine is needed.

### `CallbackContext` [in, optional]

A context value for the callback routine pointed to by the *Callback* parameter. The operating system passes this value as a parameter to the *ExTimerCallback* callback routine, if one is specified. This parameter is typically a pointer to a caller-defined structure that contains context information used by the callback routine. This parameter is optional and can be set to **NULL** if no context information is needed.

### `Attributes` [in]

The timer attributes. Set this parameter to zero or to the bitwise-OR of one or more of the following timer flag bits.

| Timer flag bit | Description |
| --- | --- |
| EX_TIMER_HIGH_RESOLUTION | High-resolution timer. Make the timer more precise by using a higher-resolution clock to drive the timer. |
| EX_TIMER_NO_WAKE | No-wake timer. Make the timer delay waking the processor to expire until the timer's expiration time plus its delay tolerance is exceeded. |
| EX_TIMER_NOTIFICATION | Notification timer. Make the timer a notification timer instead of a synchronization timer. If this flag is not set, the timer is a synchronization timer. |

The EX_TIMER_NOTIFICATION flag bit can be set regardless of what other flag bits are set.

The EX_TIMER_HIGH_RESOLUTION and EX_TIMER_NO_WAKE flag bits are mutually exclusive. If the caller sets both of these flag bits, the routine bug checks.

For more information about timer attributes, see Remarks.

## Return value

This routine returns a pointer to an [EX_TIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects) structure, if the call is successful. This structure is the timer object that the routine has allocated and initialized. If the call fails, the routine returns **NULL**.

## Remarks

This routine returns a pointer to the new timer object. To use the timer, the calling driver supplies this pointer in subsequent calls to the [ExSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsettimer), [ExCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excanceltimer), and [ExDeleteTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeletetimer) routines. If the driver supplies a pointer to an [ExTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ext_callback) callback routine as an input parameter to the **ExAllocateTimer** routine, the operating system passes this timer object as an input parameter to the *ExTimerCallback* routine.

A timer can be a notification timer or a synchronization timer. When a notification timer is signaled, all waiting threads have their wait satisfied. The state of this timer remains signaled until it is explicitly reset. When a synchronization timer expires, its state is set to signaled until a single waiting thread is released. Then, the timer is reset to the not-signaled state.

If the EX_TIMER_HIGH_RESOLUTION flag bit is set in *Attributes*, the operating system increases the resolution of the system clock, as necessary, so that the times at which the timer expires more precisely corresponds to the nominal expiration times specified in the *DueTime* and *Period* parameters to the **ExSetTimer** routine. For more information, see [High-Resolution Timers](https://learn.microsoft.com/windows-hardware/drivers/kernel/high-resolution-timers).

If the EX_TIMER_NO_WAKE flag bit is set in *Attributes*, the timer avoids unnecessarily waking the processor from a low-power state. For more information, see [No-Wake Timers](https://learn.microsoft.com/windows-hardware/drivers/kernel/no-wake-timers).

**ExAllocateTimer** allocates the storage for the timer object. When this object is no longer needed, the caller is responsible for freeing this object by calling the **ExDeleteTimer** routine.

The *Callback* parameter is optional. A driver that does not supply an *ExTimerCallback* routine can instead initiate a wait operation on the timer object. A driver thread can call a routine such as [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject) or [KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects) to wait for the timer to expire. When the timer expires, the timer object is signaled.

For more information, see [ExXxxTimer Routines and EX_TIMER Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects).

## See also

[EX_TIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects)

[ExCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excanceltimer)

[ExDeleteTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeletetimer)

[ExSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsettimer)

[ExTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ext_callback)