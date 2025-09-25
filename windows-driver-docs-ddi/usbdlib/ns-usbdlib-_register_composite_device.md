# _REGISTER_COMPOSITE_DEVICE structure

## Description

The **REGISTER_COMPOSITE_DEVICE** structure is used with the [IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_register_composite_device) I/O control request to register a parent driver of a Universal Serial Bus (USB) multi-function device (composite driver) with the USB driver stack.

To initialize the **REGISTER_COMPOSITE_DEVICE** structure, the composite driver must call the [USBD_BuildRegisterCompositeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_buildregistercompositedevice) routine.

## Members

### `Version`

The version of this structure. [USBD_BuildRegisterCompositeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_buildregistercompositedevice) sets this member.

### `Size`

The size of this structure. [USBD_BuildRegisterCompositeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_buildregistercompositedevice) sets this member.

### `Reserved`

Reserved. [USBD_BuildRegisterCompositeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_buildregistercompositedevice) sets this member.

### `CapabilityFlags`

The capabilities that are supported by the composite driver.
To specify that function suspend is supported by the composite driver, first initialize the [COMPOSITE_DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_composite_device_capabilities) structure by calling the [COMPOSITE_DEVICE_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-composite_device_capabilities_init) macro. Then, set the **CompositeDeviceCapabilityFunctionSuspend**
member of **COMPOSITE_DEVICE_CAPABILITIES** to 1. Finally, call [USBD_BuildRegisterCompositeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_buildregistercompositedevice) and pass the initialized structure in the *CapabilityFlags* parameter.

### `FunctionCount`

The number of functions supported by the composite device. The **FunctionCount** value must not exceed 255.

## See also

[COMPOSITE_DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_composite_device_capabilities)

[COMPOSITE_DEVICE_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-composite_device_capabilities_init)

[IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_register_composite_device)

[USBD_BuildRegisterCompositeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_buildregistercompositedevice)