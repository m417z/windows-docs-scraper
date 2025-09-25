# IOCTL_INTERNAL_USB_CYCLE_PORT IOCTL

## Description

The **IOCTL_INTERNAL_USB_CYCLE_PORT** I/O request simulates a device unplug and replug on the port associated with the PDO.

Drivers should cancel all I/O requests and wait for them to complete before initiating this operation.

A driver that manages an individual interface on a composite device cannot cycle the port to which the device is attached without affecting the entire composite device and all of its interfaces. For this reason, drivers that manage interfaces should attempt other types of error recovery, such as resetting pipes ([_URB_PIPE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_pipe_request)), before cycling the port.

**IOCTL_INTERNAL_USB_CYCLE_PORT** is a kernel-mode I/O control request. This request targets the USB hub PDO. This request must be sent at an IRQL of PASSIVE_LEVEL.

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