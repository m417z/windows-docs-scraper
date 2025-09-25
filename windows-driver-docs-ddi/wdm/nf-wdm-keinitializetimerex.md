# KeInitializeTimerEx function

## Description

The **KeInitializeTimerEx** routine initializes an extended kernel timer object.

## Parameters

### `Timer` [out]

Pointer to a timer object, for which the caller provides the storage.

### `Type` [in]

Specifies the type of the timer object, either **NotificationTimer** or **SynchronizationTimer**.

## Remarks

The timer object is initialized to a not-signaled state.

Storage for a timer object must be resident: in the device extension of a driver-created device object, in the controller extension of a driver-created controller object, or in nonpaged pool allocated by the caller.

When a notification timer expires, all waiting threads are released and the timer remains in the signaled state until it is explicitly reset. When a synchronization timer expires, it is set to a signaled state until a single waiting thread is released and then the timer is reset to a not-signaled state.

Callers of **KeInitializeTimerEx** should be running at IRQL = DISPATCH_LEVEL or lower. It is best to initialize timers at IRQL = PASSIVE_LEVEL.

For more information about timer objects, see [Timer Objects and DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/timer-objects-and-dpcs).

Use [KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer) or [KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex) to define when the timer will expire.

## See also

[KeCancelTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kecanceltimer)

[KeReadStateTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereadstatetimer)

[KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer)

[KeSetTimerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimerex)

[KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)