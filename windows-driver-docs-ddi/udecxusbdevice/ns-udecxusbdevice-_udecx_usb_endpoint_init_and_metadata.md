# _UDECX_USB_ENDPOINT_INIT_AND_METADATA structure

## Description

Contains the descriptors supported by an endpoint of a virtual USB device.

## Members

### `UdecxUsbEndpointInit`

A pointer to a **UDECXUSBDEVICE_INIT** structure that contains initialization parameters for the virtual USB device. The client driver retrieved this pointer in the previous call to [UdecxUsbDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitallocate).

### `EndpointDescriptorBufferLength`

The length of the endpoint descriptor.

### `EndpointDescriptor`

Required. A buffer containing the endpoint descriptor. The descriptor is described in a [USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor) structure.

### `SuperSpeedEndpointCompanionDescriptor`

Optional. A USB-defined SuperSpeed Endpoint Companion descriptor. For more information, see section 9.6.7 and Table 9-20 in the official USB 3.0 specification. The descriptor is described in a [USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_superspeed_endpoint_companion_descriptor) structure.

## See also

[EVT_UDECX_USB_DEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_endpoint_add)