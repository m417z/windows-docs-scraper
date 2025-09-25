# IOCTL_INTERNAL_USBFN_TRANSFER_IN_APPEND_ZERO_PKT IOCTL

## Description

The class driver sends this request to initiate an IN transfer to the specified pipe and appends a zero-length packet to indicate the end of the transfer.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

A pointer to a **USBFNPIPEID** type that specifies the pipe ID.

### Input buffer length

The size of a **USBFNPIPEID** type.

### Output buffer

The output buffer points to a data buffer containing the data to be sent. The IN direction is from the host perspective representing an outbound transfer from the device to the host.

### Output buffer length

The size of the data to be sent.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the USB function class extension (UFX) returns STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it returns a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

This request must be sent after sending the [IOCTL_INTERNAL_USBFN_ACTIVATE_USB_BUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_activate_usb_bus) request.

UFX forwards this IOCTL request to the transfer queue created for the endpoint by [UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate).

The function controller initiates a transfer in the IN direction on the endpoint and automatically appends a zero-length packet transfer after the data provided in the data buffer is successfully sent. A zero-length packet is only appended by the controller if the size of the transfer payload is a multiple of the endpoint’s maximum packet size.