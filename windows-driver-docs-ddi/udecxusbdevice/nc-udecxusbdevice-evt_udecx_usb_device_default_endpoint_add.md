# EVT_UDECX_USB_DEVICE_DEFAULT_ENDPOINT_ADD callback function

## Description

The USB device emulation class extension (UdeCx) invokes this callback function to request the client driver to create the default control endpoint on the virtual USB device.

## Parameters

### `UdecxUsbDevice` [in]

A handle to the UDE device object for which the client driver creates the default endpoint. The driver created this object in a previous call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate).

### `UdecxEndpointInit` [in]

A pointer to an **UDECXUSBENDPOINT_INIT** structure that the client driver retrieved in the previous call to [UdecxUsbSimpleEndpointInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbsimpleendpointinitallocate).

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[UdecxUsbSimpleEndpointInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbsimpleendpointinitallocate)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)