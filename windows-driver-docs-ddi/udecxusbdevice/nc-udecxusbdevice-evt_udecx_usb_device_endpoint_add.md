# EVT_UDECX_USB_DEVICE_ENDPOINT_ADD callback function

## Description

The USB device emulation class extension (UdeCx) invokes this callback function to request the client driver to create a dynamic endpoint on the virtual USB device.

## Parameters

### `UdecxUsbDevice` [in]

A handle to the UDE device object for which the client driver creates an endpoint. The driver created this object in a previous call to [UdecxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdevicecreate).

### `EndpointToCreate` [in]

A pointer to a [UDECX_USB_ENDPOINT_INIT_AND_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ns-udecxusbdevice-_udecx_usb_endpoint_init_and_metadata) structure that contains the endpoint descriptor.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE.

## Remarks

The client driver registered this callback function in a previous call to [UdecxUsbDeviceInitSetStateChangeCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitsetstatechangecallbacks) by supplying a function pointer to its implementation.

In the implementation, the client driver is expected to create the endpoint by calling [UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate) by using the initialization parameters (**UDECXUSBENDPOINT_INIT**) passed by the class extension in the [UDECX_USB_ENDPOINT_INIT_AND_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ns-udecxusbdevice-_udecx_usb_endpoint_init_and_metadata) structure.

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[UdecxUsbEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbendpoint/nf-udecxusbendpoint-udecxusbendpointcreate)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)