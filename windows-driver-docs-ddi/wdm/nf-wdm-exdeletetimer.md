# ExDeleteTimer function

## Description

The **ExDeleteTimer** routine deletes a timer object that was previously allocated by the [ExAllocateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatetimer) routine.

## Parameters

### `Timer` [in]

A pointer to an [EX_TIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects) structure. This structure is a timer object that was previously allocated by the [ExAllocateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatetimer) routine.

### `Cancel` [in]

Whether to cancel the timer if it is currently set. If **TRUE**, the routine cancels the timer if the timer is set. If **FALSE**, the routine does not cancel the timer if it is set. If the caller sets *Wait* to **TRUE**, *Cancel* must also be **TRUE**; otherwise, a bug check occurs.

### `Wait` [in]

Whether to wait for the timer to finish expiring if the timer has already started the process of expiring. If **TRUE**, the routine waits for the timer to expire. If **FALSE**, the routine does not wait. For more information, see Remarks.

### `Parameters` [in]

A pointer to an [EXT_DELETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ext_delete_parameters) structure. The calling driver previously called the [ExInitializeDeleteTimerParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializedeletetimerparameters) routine to initialize this structure.

## Return value

This routine returns **TRUE** if *Cancel* is **TRUE** and the timer was canceled. Otherwise, the routine returns **FALSE**. For more information, see Remarks.

## Remarks

After your driver calls this routine, the timer object pointed to by *Timer* might no longer be valid. However, the *Timer* parameter value passed to an [ExTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ext_callback) callback routine, if the driver implements this routine, is always a valid pointer to a timer object.

If *Cancel* is **TRUE**, a return value of **FALSE** indicates that the timer was never set, or that the timer was set but expired before it could be canceled. If *Cancel* is **FALSE**, the routine always returns **FALSE**.

This routine can block if *Wait* is **TRUE**. If **ExDeleteTimer** is called from the driver's *ExTimerCallback* routine, which is called at DISPATCH_LEVEL, the *Wait* parameter in this call must be **FALSE**.

If *Wait* is **TRUE**, the routine must be called at IRQL <= APC_LEVEL. If *Wait* is **FALSE**, the routine can be called at IRQL <= DISPATCH_LEVEL.

For more information, see [Deleting a System-Allocated Timer Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/deleting-a-system-allocated-timer-object).

## See also

[EXT_DELETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ext_delete_parameters)

[EX_TIMER](https://learn.microsoft.com/windows-hardware/drivers/kernel/exxxxtimer-routines-and-ex-timer-objects)

[ExAllocateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatetimer)

[ExInitializeDeleteTimerParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializedeletetimerparameters)

[ExTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ext_callback)

[ExTimerDeleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ext_delete_callback)