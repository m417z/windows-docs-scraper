# IOCTL_INTERNAL_USBFN_ACTIVATE_USB_BUS IOCTL

## Description

The USB class driver sends this request to activate the bus so that the driver can prepare to process bus events and handle traffic.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

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

If the request is successful, the USB function class extension (UFX) returns STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it returns a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

All class drivers must send this IOCTL request before the device attempts to connect with the host.