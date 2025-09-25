# _USBSCAN_GET_DESCRIPTOR structure

## Description

The USBSCAN_GET_DESCRIPTOR structure is used as a parameter to [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol), when the specified I/O control code is [IOCTL_GET_USB_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ni-usbscan-ioctl_get_usb_descriptor).

## Members

### `DescriptorType`

Same as the *DescriptorType* parameter to [UsbBuildGetDescriptorRequest](https://learn.microsoft.com/previous-versions/ff538943(v=vs.85)).

### `Index`

Same as the *Index* parameter to **UsbBuildGetDescriptorRequest**.

### `LanguageId`

Same as the *LanguageId* parameter to **UsbBuildGetDescriptorRequest**.