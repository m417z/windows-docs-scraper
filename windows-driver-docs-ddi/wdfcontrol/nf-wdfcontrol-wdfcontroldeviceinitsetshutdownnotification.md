# WdfControlDeviceInitSetShutdownNotification function

## Description

[Applies to KMDF only]

The **WdfControlDeviceInitSetShutdownNotification** method sets shutdown notification information for a control device object.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure that the driver obtained by calling [WdfControlDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitallocate).

### `Notification` [in]

A pointer to the driver's [EvtDeviceShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nc-wdfcontrol-evt_wdf_device_shutdown_notification) event callback function.

### `Flags` [in]

One or more [WDF_DEVICE_SHUTDOWN_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/ne-wdfcontrol-_wdf_device_shutdown_flags)-typed flags that indicate when the [EvtDeviceShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nc-wdfcontrol-evt_wdf_device_shutdown_notification) callback function will be called.

## Remarks

The driver must call **WdfControlDeviceInitSetShutdownNotification** before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfControlDeviceInitSetShutdownNotification**, see [Using Control Device Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-control-device-objects).

#### Examples

For a code example that uses **WdfControlDeviceInitSetShutdownNotification**, see [WdfControlDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitallocate).

## See also

[EvtDeviceShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nc-wdfcontrol-evt_wdf_device_shutdown_notification)

[WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)

[WDF_DEVICE_SHUTDOWN_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/ne-wdfcontrol-_wdf_device_shutdown_flags)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)