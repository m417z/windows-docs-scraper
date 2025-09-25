# ExCancelTimer function

## Description

The **ExCancelTimer** routine cancels a timer that was set by a previous call to the [ExSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsettimer) routine.

## Parameters

### `Timer` [in, out]

A pointer to an [EX_TIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects) structure. This structure is a timer object that was previously allocated by the [ExAllocateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatetimer) routine.

### `Parameters` [in, optional]

Drivers must set this parameter to **NULL**.

## Return value

This routine returns **TRUE** if the timer was canceled. Otherwise, the routine returns **FALSE**.

## Remarks

After your driver calls the [ExSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsettimer) routine to set the timer, the timer might be canceled before it expires. The driver can call the **ExCancelTimer** routine to explicitly cancel a pending timer. Also, if the driver calls the **ExSetTimer** routine to set a new timer on a timer object before a previously set timer on this object expires, this **ExSetTimer** call implicitly cancels the previous timer and then starts the new timer.

A return value of **TRUE** indicates that the timer was set when **ExCancelTimer** was called. In this case, the routine cancels the timer. A return value of **FALSE** indicates that the timer was not set, which might mean that the timer was never set, that the timer had already been canceled, or that the timer had already expired. If the timer expires before it is cancelled, ExCancelTimer returns FALSE and the timer remains in the signaled state.

When a timer expires, the operating system signals the timer object. As an option, a driver can supply an [ExTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ext_callback) callback routine that is called when the timer expires. If the driver supplies this callback routine, this routine is guaranteed to be called if the timer object is signaled. If the timer is canceled before it expires, the timer object is not signaled and the callback routine is not called.

For more information, see [ExXxxTimer Routines and EX_TIMER Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects).

## See also

[EX_TIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects)

[ExAllocateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatetimer)

[ExSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsettimer)