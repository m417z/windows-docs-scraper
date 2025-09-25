# IOCTL_INTERNAL_USBFN_GET_PIPE_STATE IOCTL

## Description

The class driver sends this request to get the stall state of the specified pipe.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

A pointer to a **USBFNPIPEID** type that specifies the pipe ID.

### Input buffer length

The size of a **USBFNPIPEID** type.

### Output buffer

A pointer to **BOOLEAN** value that is set by USB Function Class Extension (UFX) to indicate whether or not the specified pipe is stalled. TRUE, indicates the pipe is in stall state; FALSE indicates the pipe is in clear state.

### Output buffer length

The size of a **BOOLEAN**.

### Input/output buffer

### Input/output buffer length

### Status block

UFX completes the request with **STATUS_SUCCESS**.

## Remarks

This request must be sent after sending the [IOCTL_INTERNAL_USBFN_ACTIVATE_USB_BUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_activate_usb_bus) request.

When stalled, the pipe sends STALL transaction packets to the host. See the Universal Serial Bus (USB) specification for more information.

UFX forwards this IOCTL request to the transfer queue created for the endpoint by [UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate).