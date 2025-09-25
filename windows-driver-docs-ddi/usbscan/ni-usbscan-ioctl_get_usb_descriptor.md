# IOCTL_GET_USB_DESCRIPTOR IOCTL

## Description

Returns a specified USB Descriptor.

## Parameters

### Major code

### Input buffer

Pointer to a [USBSCAN_GET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_usbscan_get_descriptor) structure.

### Input buffer length

Size of the input buffer.

### Output buffer

Pointer to a [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor), [USB_STRING_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_string_descriptor), or [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor) structure.

### Output buffer length

Size of the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### DeviceIoControl Parameters

When the **DeviceloControl** function is called with the IOCTL_GET_USB_DESCRIPTOR I/O control code, the caller must specify the address of a [USBSCAN_GET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_usbscan_get_descriptor) structure as the function's *lpInBuffer* parameter. Depending on the value specified for the **DescriptorType** member of the USBSCAN_GET_DESCRIPTOR structure, the function's *lpOutbuffer* parameter must point to either a [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor), [USB_STRING_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_string_descriptor), or [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor) structure.

The kernel-mode driver obtains a USB descriptor by calling [UsbBuildGetDescriptorRequest](https://learn.microsoft.com/previous-versions/ff538943(v=vs.85)).

For more information, see [Accessing Kernel-Mode Drivers for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/accessing-kernel-mode-drivers-for-still-image-devices).

For more information about USB descriptors, see the *Universal Serial Bus Specification*.