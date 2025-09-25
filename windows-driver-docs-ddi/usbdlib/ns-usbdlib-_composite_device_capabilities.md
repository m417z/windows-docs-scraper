# _COMPOSITE_DEVICE_CAPABILITIES structure

## Description

The **COMPOSITE_DEVICE_CAPABILITIES** structure specifies the capabilities of the driver of a USB multi-function device (composite driver). To initialize the structure, use the [COMPOSITE_DEVICE_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-composite_device_capabilities_init) macro.

## Members

### `CapabilityFunctionSuspend`

If set to 1, indicates that the composite driver supports the USB function suspend feature.

### `Reserved`

Reserved.

## See also

[COMPOSITE_DEVICE_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-composite_device_capabilities_init)

[How to Register a Composite Device](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_register_composite_device)

[REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_register_composite_device)

[USBD_BuildRegisterCompositeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_buildregistercompositedevice)