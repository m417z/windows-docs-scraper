# USBD_BuildRegisterCompositeDevice function

## Description

The **USBD_BuildRegisterCompositeDevice** routine is called by the driver of a USB multi-function device (composite driver) to initialize a [REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_register_composite_device) structure with the information required for registering the driver with the USB driver stack.

The routine is called by a driver that replaces the Microsoft-provided composite driver, Usbccgp.sys.

## Parameters

### `USBDHandle` [in]

A USBD handle that is retrieved in a previous call to the [USBD_CreateHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_createhandle) routine.

### `CapabilityFlags` [in]

A caller-allocated [COMPOSITE_DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_composite_device_capabilities) structure that indicates the capabilities that are supported by the composite driver. For instance, to indicate that the composite driver supports function suspend, set the **CapabilityFunctionSuspend** member of **COMPOSITE_DEVICE_CAPABILITIES** to 1.

### `FunctionCount` [in]

The number of physical device objects (PDOs) to be created by the parent driver. The *FunctionCount* value cannot exceed 255.

### `RegisterCompositeDevice` [out]

A pointer to a caller-allocated [REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_register_composite_device) structure. Upon completion, the structure is populated with the specified registration information. To register the composite driver, send the [IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_register_composite_device) I/O request and pass the populated structure.

## See also

[IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_internal_usb_register_composite_device)

[REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_register_composite_device)