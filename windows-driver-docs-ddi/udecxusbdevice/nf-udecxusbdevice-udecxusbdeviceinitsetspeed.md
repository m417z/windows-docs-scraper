# UdecxUsbDeviceInitSetSpeed function

## Description

Sets the USB speed of the virtual USB device to create.

## Parameters

### `UdecxUsbDeviceInit` [in, out]

A pointer to a WDF-allocated structure that contains initialization parameters for the virtual USB device. The client driver retrieved this pointer in the previous call to [UdecxUsbDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitallocate).

### `UsbDeviceSpeed` [in]

A [UDECX_USB_DEVICE_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ne-udecxusbdevice-_udecx_usb_device_speed)-type value that indicates the USB speed to set.

## Remarks

After the client driver sets the USB speed of the device, it only operates in that speed. The speed also determines the kind of port to which the device can connect. For example, a USB SuperSpeed device cannot connect to a USB 2.0 port.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)