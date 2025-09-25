# IOCTL_GENERICUSBFN_REGISTER_USB_STRING IOCTL

## Description

This I/O control code (IOCTL) is sent by a user-mode service or application to register a Universal Serial Bus (USB) string descriptor.

## Parameters

### Input buffer

A pointer to a buffer that contains a [USBFN_USB_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbfnbase/ns-usbfnbase-_usbfn_usb_string) structure with the USB string descriptor.

### Input buffer length

The size of a [USBFN_USB_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbfnbase/ns-usbfnbase-_usbfn_usb_string) structure.

### Output buffer

NULL.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

This request must be sent after sending the [IOCTL_GENERICUSBFN_ACTIVATE_USB_BUS](https://learn.microsoft.com/windows/desktop/api/genericusbfnioctl/ni-genericusbfnioctl-ioctl_genericusbfn_activate_usb_bus) request.

If this I/O control code (IOCTL) is being called synchronously, set the *lpOverlapped* parameter to NULL. If this IOCTL is called asynchronously, assign the *lpOverlapped* parameter to a pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an event object. The event objects signal when the operation is completed.

The return value is a BOOL value that indicates success or failure of the operation. TRUE indicates success, FALSE otherwise.

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)