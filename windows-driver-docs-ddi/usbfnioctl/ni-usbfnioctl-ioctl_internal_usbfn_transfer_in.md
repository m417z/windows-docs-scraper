# IOCTL_INTERNAL_USBFN_TRANSFER_IN IOCTL

## Description

The class driver sends this request to initiate a data transfer to the host on the specified pipe.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

A pointer to a **USBFNPIPEID** type that specifies the pipe ID.

### Input buffer length

The size of a **USBFNPIPEID** type.

### Output buffer

The output buffer points to a buffer containing the data to be sent. The IN direction is from the host perspective representing an outbound transfer from the device to the host.

### Output buffer length

The length of the data to be sent.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the USB function class extension (UFX) returns STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it returns a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

This request must be sent after sending the [IOCTL_INTERNAL_USBFN_ACTIVATE_USB_BUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbfnioctl/ni-usbfnioctl-ioctl_internal_usbfn_activate_usb_bus) request.

UFX forwards this IOCTL request to the transfer queue created for the endpoint by [UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate).