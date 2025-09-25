# SwDeviceClose function

## Description

Closes the software device handle. When the handle is closed, if the lifetime of the SwDevice is **SWDeviceLifetimeHandle**, PnP will initiate the process of "unplugging" the device. The device will no longer be reported as a child of its parent device.

## Parameters

### `hSwDevice` [in]

The **HSWDEVICE** handle to close.

## Remarks

After **SwDeviceClose** returns, the operating system is guaranteed to not call the [SW_DEVICE_CREATE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/swdevice/nc-swdevice-sw_device_create_callback) callback function, and any calls to Software Device API functions that were in progress are guaranteed to have completed.

You can call **SwDeviceClose** at any time even if the callback function hasn't been called yet.

In Windows 8, you can't call **SwDeviceClose** inside the [SW_DEVICE_CREATE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/swdevice/nc-swdevice-sw_device_create_callback) callback function. Doing so will cause a deadlock. Be careful of releasing a ref counted object that will call **SwDeviceClose** when its destructor runs. In Windows 8.1, this restriction is lifted, and you can call **SwDeviceClose** inside the callback function.

By calling **SwDeviceClose**, if the lifetime of the SwDevice is **SWDeviceLifetimeHandle**, you initiate the process of "unplugging" the device. This causes the device to no longer be reported as a child of its parent which causes PnP to issue a "surprise removal" of the device. The call to **SwDeviceClose** returns before this removal is complete. However, you can safely call [SwDeviceCreate](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdevicecreate) immediately after **SwDeviceClose**. The new create will be queued until the previous removal processing completes, and then the device will be re-created.

PnP removal makes the device "Not present" and does not uninstall the device. PnP removal of a device is the same as unplugging a USB device and all of the persisted property state for the device will remain. If you wish to uninstall the device after calling **SwDeviceClose**, see [Uninstalling the device](https://learn.microsoft.com/windows-hardware/drivers/install/how-devices-and-driver-packages-are-uninstalled#uninstalling-the-device).

## See also

[SwDeviceCreate](https://learn.microsoft.com/windows/desktop/api/swdevice/nf-swdevice-swdevicecreate)