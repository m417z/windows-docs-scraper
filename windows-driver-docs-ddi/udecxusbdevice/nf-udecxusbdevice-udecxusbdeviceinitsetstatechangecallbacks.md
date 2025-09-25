# UdecxUsbDeviceInitSetStateChangeCallbacks function

## Description

Initializes a WDF-allocated structure with pointers to callback functions.

## Parameters

### `UdecxUsbDeviceInit` [in, out]

A pointer to a WDF-allocated structure that contains initialization parameters for the virtual USB device. The client driver retrieved this pointer in the previous call to [UdecxUsbDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitallocate).

### `Callbacks` [in]

A pointer to a [UDECX_USB_DEVICE_STATE_CHANGE_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ns-udecxusbdevice-_udecx_usb_device_state_change_callbacks) structure that contains pointers to callback functions implemented by the client driver.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[UdecxUsbDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitallocate)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)