# IOCTL_INTERNAL_USB_GET_PORT_STATUS IOCTL

## Description

The **IOCTL_INTERNAL_USB_GET_PORT_STATUS** I/O request queries the status of the PDO.

**IOCTL_INTERNAL_USB_GET_PORT_STATUS** is a kernel-mode I/O control request. This request targets the USB hub PDO. This IOCTL must be sent at IRQL = PASSIVE_LEVEL.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**Parameters.Others.Argument1** should be a pointer to a ULONG to be filled in with the port status flags.

### Input buffer length

The size of a ULONG.

### Output buffer

**Parameters.Others.Argument1** points to a ULONG that has the port status flags filled in. The flags can be one or both of USBD_PORT_ENABLED (bit 0) or USBD_PORT_CONNECTED (bit 1). When the USB_PORT_ENABLED bit is set, the port has been enabled after resetting the device connected to the port. When the USB_PORT_ENABLED bit is clear, software has disabled the port or hardware has disabled it due to abnormal hardware conditions. When the USB_PORT_CONNECTED bit is set, the host controller root hub or external hub has detected that a device is connected to the port. When the USB_PORT_CONNECTED bit is clear, the host controller root hub or external hub has detected that a device is not connected to the port.

### Output buffer length

The size of a ULONG.

### Input/output buffer

### Input/output buffer length

### Status block

The bus or port driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS or the appropriate error status.