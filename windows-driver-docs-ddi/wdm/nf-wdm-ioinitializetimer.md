# IoInitializeTimer function

## Description

The **IoInitializeTimer** routine sets up a driver-supplied [IoTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_timer_routine) routine associated with a given device object.

## Parameters

### `DeviceObject` [in]

Pointer to a device object representing a device on which I/O operations can time out.

### `TimerRoutine` [in]

Pointer to the driver-supplied *IoTimer* routine.

### `Context` [in, optional]

Pointer to the driver-determined context with which its *IoTimer* routine will be called.

## Return value

**IoInitializeTimer** returns STATUS_SUCCESS if the *IoTimer* routine is set up.

## Remarks

**IoInitializeTimer** should be called only once per device object.

A driver's [IoTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_timer_routine) routine is called once per second after the driver enables the timer by calling [IoStartTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostarttimer). The driver can disable the timer by calling [IoStopTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostoptimer) and can reenable it again with **IoStartTimer**.

The driver's *IoTimer* routine is called at IRQL = DISPATCH_LEVEL and therefore must not contain pageable code.

When the timer is running, the I/O manager calls the driver-supplied *IoTimer* routine once per second. Drivers whose time-out routines should be called at variable intervals or at intervals of finer granularity can set up a [CustomTimerDpc](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-a-customtimerdpc-routine) routine and use the **Ke*Xxx*Timer** routines.

## See also

[IoStartTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostarttimer)

[IoStopTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostoptimer)

[IoTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_timer_routine)

[KeInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimer)

[KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer)