# UdecxUsbSimpleEndpointInitAllocate function

## Description

Allocates memory for an initialization structure that is used to create a simple endpoint for the specified virtual USB device.

## Parameters

### `UdecxUsbDevice` [in]

A handle to UDE device object. The client driver retrieved this pointer in the previous call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate).

## Return value

This method returns a pointer to an opaque **UDECXUSBENDPOINT_INIT** structure that contains the initialization parameters. The structure is allocated by the USB device emulation class extension (UdeCx).

## Remarks

The UDE client driver calls this method to allocate parameters for a simple endpoint that is created by a subsequent call to [UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate). If the device is not created or the driver is finished using the resources, the driver must free the resources by calling [UdecxUsbEndpointInitFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointinitfree).

The only valid time to create simple endpoints is after creating a UDE device object and before calling [UdecxUsbDevicePlugIn](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceplugin) on the device.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)