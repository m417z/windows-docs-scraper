# EVT_UDECX_USB_DEVICE_D0_ENTRY callback function

## Description

The USB device emulation class extension (UdeCx) invokes this callback function when it gets a request to bring the virtual USB device out of a low power state to working state.

## Parameters

### `UdecxWdfDevice` [in]

A handle to a framework device object that represents the controller to which the USB device is attached. The client driver initialized this object in a previous call to [UdecxWdfDeviceAddUsbDeviceEmulation](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecxwdfdeviceaddusbdeviceemulation).

### `UdecxUsbDevice` [in]

A handle to UDE device object. The client driver created this object in a previous call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate).

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE.

## Remarks

The client driver registered the function in a previous call to [UdecxUsbDeviceInitSetStateChangeCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitsetstatechangecallbacks) by supplying a function pointer to its implementation.

In the callback implementation, the client driver for the USB device is expected to perform steps to enter working state.

The power request may be completed asynchronously by returning STATUS_PENDING, and then later completing it by calling [UdecxUsbDeviceLinkPowerExitComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicelinkpowerexitcomplete) with the actual completion code.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[EVT_UDECX_USB_DEVICE_D0_EXIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_d0_exit)

[UdecxUsbDeviceLinkPowerExitComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicelinkpowerexitcomplete)

[UdecxUsbDeviceSignalWake](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicesignalwake)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)