# UdecxUsbDeviceInitAllocate function

## Description

Allocates memory for a **UDECXUSBDEVICE_INIT** structure that is used to initialize a virtual USB device.

## Parameters

### `UdecxWdfDevice` [in]

A handle to a framework device object that represents a USB device. The client driver initialized this object in the previous call to [UdecxWdfDeviceAddUsbDeviceEmulation](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecxwdfdeviceaddusbdeviceemulation).

## Return value

This method returns a pointer to an opaque **UDECXUSBDEVICE_INIT** that contains the initialization parameters. The structure is allocated by the USB device emulation class extension (UdeCx).

## Remarks

The UDE client driver calls this method to allocate parameters for the virtual device that is created by a subsequent call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate). If the device is not created or the driver is finished using the resources, the driver must free the resources by calling [UdecxUsbDeviceInitFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitfree).

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)