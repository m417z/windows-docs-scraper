# KeInitializeTimer function

## Description

The **KeInitializeTimer** routine initializes a timer object.

## Parameters

### `Timer` [out]

Pointer to a timer object, for which the caller provides the storage.

## Remarks

The timer object is initialized to a not-signaled state.

Storage for a timer object must be resident: in the device extension of a driver-created device object, in the controller extension of a driver-created controller object, or in nonpaged pool allocated by the caller.

**KeInitializeTimer** can only initialize a notification timer. Use [KeInitializeTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimerex) to initialize a notification timer or a synchronization timer.

Use [KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer) or [KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex) to define when the timer will expire.

For more information about timer objects, see [Timer Objects and DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/timer-objects-and-dpcs).

Callers of **KeInitializeTimer** should be running at IRQL = DISPATCH_LEVEL or lower. It is best to initialize timers at IRQL = PASSIVE_LEVEL.

## See also

[KeCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kecanceltimer)

[KeInitializeTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimerex)

[KeReadStateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereadstatetimer)

[KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer)

[KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex)

[KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)