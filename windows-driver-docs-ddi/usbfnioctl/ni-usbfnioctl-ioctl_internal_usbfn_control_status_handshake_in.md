# IOCTL_INTERNAL_USBFN_CONTROL_STATUS_HANDSHAKE_IN IOCTL

## Description

The class driver sends this request to send a zero-length control status handshake on endpoint 0 in the IN direction.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

A **USBFNPIPEID** type value that indicates the pipe ID. The pipe ID of the default control endpoint is 0.

### Input buffer length

The size of a **USBFNPIPEID** type.

### Output buffer

NULL.

### Output buffer length

NULL.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the USB function class extension (UFX) returns STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it returns a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

This request must be sent after sending the [IOCTL_INTERNAL_USBFN_ACTIVATE_USB_BUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_activate_usb_bus) request.

UFX forwards this IOCTL request to the transfer queue created for the endpoint by [UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate).