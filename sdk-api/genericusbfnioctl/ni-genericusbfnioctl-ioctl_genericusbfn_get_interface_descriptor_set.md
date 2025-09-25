# IOCTL_GENERICUSBFN_GET_INTERFACE_DESCRIPTOR_SET IOCTL

## Description

This I/O control code (IOCTL) is sent by a user-mode service or application to get the entire Universal Serial Bus (USB) interface descriptor set for a function on the device.

**Note** This IOCTL request does not retrieve the interface descriptor set for the entire device.

## Parameters

### Input buffer

A pointer to a [USBFN_INTERFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbfnbase/ns-usbfnbase-_usbfn_interface_info) structure.

### Input buffer length

The size of a [USBFN_INTERFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbfnbase/ns-usbfnbase-_usbfn_interface_info) structure.

### Output buffer

A pointer to a buffer that contains a [USBFN_INTERFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbfnbase/ns-usbfnbase-_usbfn_interface_info) structure. The USB function class extension (UFX) populates the structure with the entire interface descriptor set including its endpoint descriptors.

### Output buffer length

The size of a [USBFN_INTERFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbfnbase/ns-usbfnbase-_usbfn_interface_info).

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

This request must be sent after sending the [IOCTL_GENERICUSBFN_ACTIVATE_USB_BUS](https://learn.microsoft.com/windows/desktop/api/genericusbfnioctl/ni-genericusbfnioctl-ioctl_genericusbfn_activate_usb_bus) request.

The length of the entire interface descriptor is variable. The class driver might need to send this IOCTL request twice to get the entire descriptor set.

If the length of the entire descriptor set is greater than the specified output buffer length, UFX sets the **Size** member of [USBFN_INTERFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbfnbase/ns-usbfnbase-_usbfn_interface_info) to the actual buffer length and fails the request with STATUS_BUFFER_TOO_SMALL. The driver must then allocated an output buffer of length specified by **Size** and resend the request.

If this I/O control code (IOCTL) is being called synchronously, set the *lpOverlapped* parameter to NULL. If this IOCTL is called asynchronously, assign the *lpOverlapped* parameter to a pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an event object. The event objects signal when the operation is completed.

The return value is a BOOL value that indicates success or failure of the operation. TRUE indicates success, FALSE otherwise.

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)