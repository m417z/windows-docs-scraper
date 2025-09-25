# IOCTL_INTERNAL_USB_RESET_PORT IOCTL

## Description

The **IOCTL_INTERNAL_USB_RESET_PORT** I/O control request is used by a driver to reset the upstream port of the device it manages. After a successful reset, the bus driver reselects the configuration and any alternative interface settings that the device had before the reset occurred. All pipe handles, configuration handles and interface handles remain valid.

Drivers should cancel all I/O requests and wait for them to complete before initiating this operation.

A driver that manages an individual interface on a composite device cannot reset the interface without resetting the entire composite device and all of its interfaces. For this reason, drivers that manage interfaces should attempt other types of error recovery, such as resetting pipes ([_URB_PIPE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_pipe_request)), before resetting the interface.

This IOCTL must be sent at an IRQL of PASSIVE_LEVEL.

**IOCTL_INTERNAL_USB_RESET_PORT** is a kernel-mode I/O control request. This request targets the USB hub PDO.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The bus or port driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS or the appropriate error status.

## See also

[_URB_PIPE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_pipe_request)