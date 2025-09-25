# PoStartDeviceBusy function (ntifs.h)

## Description

The **PoStartDeviceBusy** routine marks the start of a period of time in which the device is busy.

## Parameters

### `IdlePointer` [in, out]

A pointer to an idle counter. This is a pointer value that was previously returned by the [PoRegisterDeviceForIdleDetection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregisterdeviceforidledetection) routine. Because **PoRegisterDeviceForIdleDetection** might return a NULL pointer, the caller must verify that the pointer is non-NULL before it calls **PoStartDeviceBusy**.

## Remarks

The **PoStartDeviceBusy** and [PoEndDeviceBusy](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poenddevicebusy) routines mark the start and end of a time period in which a device is busy. Each call to **PoStartDeviceBusy** must be followed by a corresponding call to **PoEndDeviceBusy**.

For each device, the [power manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-manager) maintains a count of the number of outstanding **PoStartDeviceBusy** calls for which it has not yet received a corresponding **PoEndDeviceBusy** call. A **PoStartDeviceBusy** call increments the busy count by one. A **PoEndDeviceBusy** call decrements the busy count by one. A nonzero busy count disables the idle counter for the device. After the busy count reaches zero, the power manager resets the idle counter to the time-out period and enables the counter.

Rather than use the **PoStartDeviceBusy** and **PoEndDeviceBusy** routines to reset the idle counter, you can call the [PoSetDeviceBusyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-posetdevicebusyex) routine (or the [PoSetDeviceBusy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-posetdevicebusy) macro). To disable the idle counter during an extended busy period, a driver can call the **PoRegisterDeviceForIdleDetection** routine to disable and enable idle notifications at the start and end of the busy period. However, **PoStartDeviceBusy** and **PoEndDeviceBusy** are typically more convenient to use for this purpose, and you should consider using these routines in new code that you write for Windows 7 and later versions of Windows.

## See also

[PoEndDeviceBusy](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poenddevicebusy)

[PoRegisterDeviceForIdleDetection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregisterdeviceforidledetection)

[PoSetDeviceBusy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-posetdevicebusy)