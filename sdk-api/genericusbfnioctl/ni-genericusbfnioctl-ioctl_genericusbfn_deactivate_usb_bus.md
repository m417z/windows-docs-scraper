# IOCTL_GENERICUSBFN_DEACTIVATE_USB_BUS IOCTL

## Description

This IOCTL code is nevtot supported.

This I/O control code (IOCTL) is sent by the user-mode service or application this request to notify GenericUSBFn.sys to deactivate the Universal Serial Bus (USB). When deactivated, the bus can no longer process bus events and handle traffic.

## Parameters

### Input buffer

NULL.

### Input buffer length

None.

### Output buffer

NULL.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

If this I/O control code (IOCTL) is being called synchronously, set the *lpOverlapped* parameter to NULL. If this IOCTL is called asynchronously, assign the *lpOverlapped* parameter to a pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that contains a handle to an event object. The event objects signal when the operation is completed.

The return value is a BOOL value that indicates success or failure of the operation. TRUE indicates success, FALSE otherwise.

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[IOCTL_GENERICUSBFN_ACTIVATE_USB_BUS](https://learn.microsoft.com/windows/desktop/api/genericusbfnioctl/ni-genericusbfnioctl-ioctl_genericusbfn_activate_usb_bus)