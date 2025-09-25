# _UDECX_ENDPOINT_TYPE enumeration

## Description

Defines values for endpoint types supported by a virtual USB device.

## Constants

### `UdecxEndpointTypeInvalid`

The endpoint is not of a valid type.

### `UdecxEndpointTypeSimple`

The endpoint is defined in the first (and only) interface setting of the interface. That device has only one configuration. The client driver creates all endpoints before the device is detected.

### `UdecxEndpointTypeDynamic`

The endpoint is dynamically created in the client driver's implementation of the [EVT_UDECX_USB_DEVICE_ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_endpoints_configure) callback.

## See also

[USB endpoints](https://learn.microsoft.com/windows-hardware/drivers/usbcon/)

[UdecxUsbDeviceInitSetEndpointsType](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitsetendpointstype)