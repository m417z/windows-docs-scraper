# UdecxUsbDeviceInitSetEndpointsType function

## Description

Indicates the type of endpoint (simple or dynamic) in the initialization parameters that the client driver uses to create the virtual USB device.

## Parameters

### `UdecxUsbDeviceInit` [in, out]

A pointer to a WDF-allocated structure that contains initialization parameters for the virtual USB device. The client driver retrieved this pointer in the previous call to [UdecxUsbDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitallocate).

### `UdecxEndpointType` [in]

A [UDECX_ENDPOINT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ne-udecxusbdevice-_udecx_endpoint_type)-type value that indicates the type of USB endpoint.

## Remarks

Before creating the virtual USB device, the client driver must indicate the type of endpoint it supports. It can support one of two types (defined in [UDECX_ENDPOINT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/ne-udecxusbdevice-_udecx_endpoint_type)):

* Simple endpoint-The client driver creates all endpoint objects before plugging in the device. The device must have only one configuration and one interface setting per interface.
* Dynamic endpoint-The client creates endpoint objects in the [EVT_UDECX_USB_DEVICE_ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_endpoints_configure) callback function.
  The USB device emulation class extension (UdeCx) invokes the driver's implementation when it gets a request to add or configure endpoints.

The *UdecxUsbDeviceInit* is an opaque structure that contains pointers to callback functions related to endpoints. If the client driver supports dynamic endpoints, then these callback functions must be implemented by the driver:

* [EVT_UDECX_USB_DEVICE_ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_endpoints_configure)
* [EVT_UDECX_USB_DEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_endpoint_add)
* [EVT_UDECX_USB_DEVICE_DEFAULT_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_default_endpoint_add)

Before calling this method, the client driver must have set those pointers by calling [UdecxUsbDeviceInitSetStateChangeCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitsetstatechangecallbacks).

## See also

[Architecture: USB Device Emulation (UDE)](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[EVT_UDECX_USB_DEVICE_ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_endpoints_configure)

[USB endpoints](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[UdecxUsbDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitallocate)

[UdecxUsbDeviceInitSetStateChangeCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitsetstatechangecallbacks)

[Write a UDE client driver](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)