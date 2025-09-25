# IOCTL_GENERICUSBFN_GET_CLASS_INFO_EX IOCTL

## Description

This I/O control code (IOCTL) is sent by a user-mode service or application to retrieve information about a device's available pipes as configured in the registry.

## Parameters

### Input buffer

NULL.

### Input buffer length

None.

### Output buffer

A [USBFN_CLASS_INFORMATION_PACKET_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbfnbase/ns-usbfnbase-_usbfn_class_information_packet_ex) that provides information about the available pipes for a device.

### Output buffer length

The size of a [USBFN_CLASS_INFORMATION_PACKET_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/usbfnbase/ns-usbfnbase-_usbfn_class_information_packet_ex) structure.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

If this I/O control code (IOCTL) is being called synchronously, set the *lpOverlapped* parameter to NULL. If this IOCTL is called asynchronously, assign the *lpOverlapped* parameter to a pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an event object. The event objects signal when the operation is completed.

The return value is a BOOL value that indicates success or failure of the operation. TRUE indicates success, FALSE otherwise.

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[IOCTL_GENERICUSBFN_GET_CLASS_INFO](https://learn.microsoft.com/windows/desktop/api/genericusbfnioctl/ni-genericusbfnioctl-ioctl_genericusbfn_get_class_info)