# UdecxUsbDeviceInitFree function

## Description

Releases the resources that were allocated by the [UdecxUsbDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitallocate) call.

## Parameters

### `UdecxUsbDeviceInit` [in, out]

A pointer to a WDF-allocated structure that contains initialization parameters for the virtual USB device. The client driver retrieved this pointer in the previous call to [UdecxUsbDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitallocate).

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)