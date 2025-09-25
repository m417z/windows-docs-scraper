# _SIDEBANDAUDIO_EP_USB_TRANSPORT_RESOURCE_TYPE enumeration

## Description

Describes the type of transport resource. The resources will be returned in the output buffer.

## Constants

### `SIOP_TYPE_USBAUD_USBD_INTERFACE_DESCRIPTOR`

[USB Interface Descriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor)

### `SIOP_TYPE_USBAUD_EP_USBD_ENDPOINT_DESCRIPTOR`

[USBD Endpoint Descriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor)

### `SIOP_TYPE_USBAUD_EP_USBD_ENDPOINT_OFFLOAD_INFORMATION`

[USBD Endpoint Offload Information](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_endpoint_offload_information)

### `SIOP_TYPE_USBAUD_EP_USBAUDIO_TRANSPORT_RESOURCES`

[Sideband Audio EP transport resource](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbsidebandaudio/ns-usbsidebandaudio-_sidebandaudio_ep_usbaudio_transport_resources)

### `SIOP_TYPE_USBAUD_EP_OFFLOAD_RESOURCE_ID`

ULONG resource ID specific to hardware platform.

### `SIOP_TYPE_USBAUD_FB_EP_USBD_ENDPOINT_DESCRIPTOR`

Feedback Endpoint [USBD Endpoint Descriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor)

### `SIOP_TYPE_USBAUD_FB_EP_USBD_ENDPOINT_OFFLOAD_INFORMATION`

Feedback Endpoint [USBD Endpoint Offload Information](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_endpoint_offload_information)

### `SIOP_TYPE_USBAUD_FB_EP_USBAUDIO_TRANSPORT_RESOURCES`

Feedback Endpoint [Sideband Audio EP transport resource](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbsidebandaudio/ns-usbsidebandaudio-_sidebandaudio_ep_usbaudio_transport_resources)

### `SIOP_TYPE_USBAUD_FB_EP_OFFLOAD_RESOURCE_ID`

Feedback Endpoint ULONG resource ID specific to hardware platform.

### `SIOP_TYPE_USBAUD_ENDPOINT_DESCRIPTOR_PER_FORMAT`

USBD_ENDPOINT_DESCRIPTOR for specific format.

### `SBUSBAUD_EP_TRANSPORT_RESOURCE_TYPE_INVALID`

Unused

## Remarks

[IOCTL_SBAUD_GET_SIOP](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_siop) is defined with [METHOD_NEITHER](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-neither-buffered-nor-direct-i-o) buffering model. The requested resource information will be copied to the [Irp->UserBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp).

## See also

[IOCTL_SBAUD_GET_SIOP](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_siop)

[usbsidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbsidebandaudio/)