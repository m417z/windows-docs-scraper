# IOCTL_GET_VERSION IOCTL

## Description

Returns the version number of the driver.

## Parameters

### Major code

### Input buffer

**NULL**

### Input buffer length

Zero.

### Output buffer

Pointer to a [DRV_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_drv_version) structure.

### Output buffer length

Size of the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### DeviceIoControl Parameters

When the **DeviceIoControl** function is called with the IOCTL_GET_VERSION I/O control code, the caller must specify the address of a [DRV_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_drv_version) structure as the function's *lpOutBuffer* parameter. The kernel-mode driver fills in the structure members.

For more information, see [Accessing Kernel-Mode Drivers for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/accessing-kernel-mode-drivers-for-still-image-devices).