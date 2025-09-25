## Description

The **PoSetDeviceBusy** macro notifies the [power manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/power-manager) that the device associated with _IdlePointer_ is busy.

## Parameters

### `IdlePointer` [in, out]

Specifies a non-**NULL** idle pointer that was previously returned by [**PoRegisterDeviceForIdleDetection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregisterdeviceforidledetection). Note that **PoRegisterDeviceForIdleDetection** might return a **NULL** pointer. A caller of **PoSetDeviceBusy** must verify that the pointer is non-**NULL** before passing it to **PoSetDeviceBusy**.

## Remarks

The [**PoSetDeviceBusyEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-posetdevicebusyex) routine is a direct replacement for the **PoSetDeviceBusy** macro. If you are writing new driver code for Windows Vista with Service Pack 1 (SP1) and later versions of Windows, call **PoSetDeviceBusyEx** instead of **PoSetDeviceBusy**.

A driver uses **PoSetDeviceBusy** along with **PoRegisterDeviceForIdleDetection** to enable system idle detection for its device. If a device that is registered for idle detection becomes idle, the power manager sends an [**IRP_MN_SET_POWER**](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) request to put the device in a requested sleep state.

**PoSetDeviceBusy** reports that the device is busy, so that the power manager can restart its idle countdown. If the device is not powered up, **PoSetDeviceBusy** does not change its state. That is, it does not cause the system to send a power-on request.

A driver should call **PoSetDeviceBusy** on every I/O request.