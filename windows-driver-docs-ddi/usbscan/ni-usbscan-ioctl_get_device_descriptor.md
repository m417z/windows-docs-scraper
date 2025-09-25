# IOCTL_GET_DEVICE_DESCRIPTOR IOCTL

## Description

Returns vendor and device identifiers.

## Parameters

### Major code

### Input buffer

Pointer to a [DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_device_descriptor) structure.

### Input buffer length

Size of the input buffer.

### Output buffer

Pointer to a [DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_device_descriptor) structure (same as *lpInbuffer*).

### Output buffer length

Size of the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### DeviceIoControl Parameters

When the **DeviceloControl** function is called with the IOCTL_GET_USB_DESCRIPTOR I/O control code, the caller must specify the address of a [DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_device_descriptor) structure as the function's *lpOutbuffer* parameter. The kernel-mode driver fills in the structure.

For more information, see [Accessing Kernel-Mode Drivers for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/accessing-kernel-mode-drivers-for-still-image-devices).