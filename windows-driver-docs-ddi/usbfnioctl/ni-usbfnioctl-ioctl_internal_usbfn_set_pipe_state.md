# IOCTL_INTERNAL_USBFN_SET_PIPE_STATE IOCTL

## Description

The class driver sends this request to set the stall state of the specified USB pipe.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

A pointer to a **USBFNPIPEID** type that specifies the pipe ID.

### Input buffer length

The size of a **USBFNPIPEID** type.

### Output buffer

A pointer to **BOOLEAN** value that specifies the stall state to set. If TRUE, USB Function Class Extension (UFX) sets the pipe to stall state; FALSE sets to clear state.

### Output buffer length

The size of a **BOOLEAN**.

### Input/output buffer

### Input/output buffer length

### Status block

UFX completes the request with **STATUS_SUCCESS**.

## Remarks

This request must be sent after sending the [IOCTL_INTERNAL_USBFN_ACTIVATE_USB_BUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_activate_usb_bus) request.

UFX forwards this IOCTL request to the transfer queue created for the endpoint by [UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate).