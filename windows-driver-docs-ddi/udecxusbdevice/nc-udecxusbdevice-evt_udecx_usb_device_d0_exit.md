# EVT_UDECX_USB_DEVICE_D0_EXIT callback function

## Description

The USB device emulation class extension (UdeCx) invokes this callback function when it gets a request to send the virtual USB device to a low power state.

## Parameters

### `UdecxWdfDevice` [in]

A handle to a framework device object that represents the controller to which the USB device is attached. The client driver initialized this object in a previous call to [UdecxWdfDeviceAddUsbDeviceEmulation](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecxwdfdeviceaddusbdeviceemulation).

### `UdecxUsbDevice` [in]

A handle to UDE device object. The client driver created this object in a previous call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate).

### `WakeSetting` [in]

A [UDECX_USB_DEVICE_WAKE_SETTING](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ne-udecxusbdevice-_udecx_usb_device_wake_setting)-type value that indicates remote wake capability of the USB device.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE.

## Remarks

The client driver registered the function in a previous call to [UdecxUsbDeviceInitSetStateChangeCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitsetstatechangecallbacks) by supplying a function pointer to its implementation.

In the callback implementation, the client driver for the USB device is expected to perform steps to send the device to a low power state. In this function, the driver can initiate its wake-up from a low link power state, function suspend, or both.
To do so, the driver for a USB 2.0 device must call the [UdecxUsbDeviceSignalWake](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicesignalwake) method. USB 3.0 devices must use [UdecxUsbDeviceSignalFunctionWake](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicesignalfunctionwake).

The power request may be completed asynchronously by returning STATUS_PENDING, and then later calling [UdecxUsbDeviceLinkPowerExitComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicelinkpowerexitcomplete) with the actual completion code.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[EVT_UDECX_USB_DEVICE_D0_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_d0_entry)

[UdecxUsbDeviceLinkPowerExitComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicelinkpowerexitcomplete)

[UdecxUsbDeviceSignalWake](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicesignalwake)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)