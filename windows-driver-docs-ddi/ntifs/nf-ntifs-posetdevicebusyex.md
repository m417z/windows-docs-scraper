# PoSetDeviceBusyEx function (ntifs.h)

## Description

The **PoSetDeviceBusyEx** routine notifies the [power manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-manager) that the device associated with the specified idle counter is busy.

## Parameters

### `IdlePointer` [in, out]

A pointer to an idle counter. This is a pointer value that was previously returned by the [**PoRegisterDeviceForIdleDetection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregisterdeviceforidledetection) routine. Because **PoRegisterDeviceForIdleDetection** might return a NULL pointer, the caller must verify that the pointer is non-NULL before it calls **PoSetDeviceBusyEx**.

## Remarks

This routine is a direct replacement for the [**PoSetDeviceBusy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-posetdevicebusy) macro. If you are writing new driver code for Windows Vista with Service Pack 1 (SP1) and later versions of Windows, call **PoSetDeviceBusyEx** instead of **PoSetDeviceBusy**.

A driver calls the **PoSetDeviceBusyEx** and **PoRegisterDeviceForIdleDetection** routines to enable system idle detection for its device. If a device that is registered for idle detection stays idle for the driver-specified time-out period, the power manager sends an [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) request to put the device in a requested sleep state.

**PoSetDeviceBusyEx** reports that the device is busy, so that the power manager can restart its idle countdown. If the device is in a sleep state, **PoSetDeviceBusyEx** does not change the state of the device. That is, it does not cause the system to send an **IRP_MN_SET_POWER** request to awaken the device.

**PoSetDeviceBusyEx** is designed for use with I/O operations that are relatively brief compared to the time-out period of the idle counter. For longer operations that might exceed this period, use the [**PoStartDeviceBusy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-postartdevicebusy) and [**PoEndDeviceBusy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poenddevicebusy) routines instead.

A driver that makes multiple requests for brief I/O operations should call **PoSetDeviceBusyEx** for every I/O request that it makes.

## See also

[IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power)

[**PoEndDeviceBusy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poenddevicebusy)

[**PoRegisterDeviceForIdleDetection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregisterdeviceforidledetection)

[**PoSetDeviceBusy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-posetdevicebusy)

[**PoStartDeviceBusy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-postartdevicebusy)