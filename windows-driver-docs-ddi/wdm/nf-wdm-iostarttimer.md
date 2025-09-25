# IoStartTimer function (wdm.h)

## Description

The **IoStartTimer** routine enables the timer associated with a given device object so the driver-supplied [IoTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_timer_routine) routine is called once per second.

## Parameters

### `DeviceObject` [in]

Pointer to a device object whose timer routine is to be called.

## Remarks

The driver must already have set up the IoTimer routine for the *DeviceObject* by calling **IoInitializeTimer**.

## See also

[IoInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializetimer)

[IoStopTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostoptimer)

[IoTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_timer_routine)

[KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc)

[KeInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializetimer)

[KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettimer)