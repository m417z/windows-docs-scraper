# UdecxUsbDeviceSignalWake function

## Description

Initiates wake up from a low link power state for a virtual USB 2.0 device.

## Parameters

### `UdecxUsbDevice` [in]

A handle to UDE device object. The client driver retrieved this pointer in the previous call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate).

## Remarks

The client driver for the device must have enabled wake capability in the most recent [EVT_UDECX_USB_DEVICE_D0_EXIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_d0_exit) call.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[EVT_UDECX_USB_DEVICE_D0_EXIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_d0_exit)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)