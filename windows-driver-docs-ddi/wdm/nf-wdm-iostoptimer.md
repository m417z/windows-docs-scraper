# IoStopTimer function (wdm.h)

## Description

The **IoStopTimer** routine disables the timer for a specified device object so the driver-supplied [IoTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_timer_routine) routine is not called.

## Parameters

### `DeviceObject` [in]

Pointer to the device object with which the [IoTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_timer_routine) routine is associated.

## Remarks

The driver-supplied [IoTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_timer_routine) routine can be reenabled with a call to **IoStartTimer**.

Do not call **IoStopTimer** from within the *IoTimer* routine.

## See also

[IoInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializetimer)

[IoStartTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostarttimer)