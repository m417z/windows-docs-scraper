# UdecxUsbDevicePlugIn function

## Description

Notifies the USB device emulation class extension (UdeCx) that the USB device has been plugged in the specified port.

## Parameters

### `UdecxUsbDevice` [in]

A handle to UDE device object. The client driver retrieved this pointer in the previous call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate).

### `Options` [in]

A [UDECX_USB_DEVICE_PLUG_IN_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ns-udecxusbdevice-_udecx_usb_device_plug_in_options)-type value that indicates the port to which the device is plugged. At most one of Usb20PortNumber, Usb30PortNumber can be non-zero. NULL disables plug-in options (use defaults).

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

After the client driver calls this method, the class extension sends I/O requests and invokes callback functions on the endpoints and the device.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)