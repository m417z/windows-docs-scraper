# IOCTL_INTERNAL_USBFN_DESCRIPTOR_UPDATE IOCTL

## Description

The USB function class extension sends this request to the client driver to update to the endpoint descriptor for the specified endpoint.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

The input buffer points to a **USBFNPIPEID** that specifies the pipe ID for the endpoint.

### Input buffer length

The size of a **USBFNPIPEID** value.

### Output buffer

The output buffer points to a [USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor) structure that describes the endpoint descriptor. To retrieve the structure, the client driver must call [WdfRequestRetrieveOutputBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputbuffer).

### Output buffer length

The size of a [USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor) structure.

### Input/output buffer

### Input/output buffer length

### Status block

 The client driver shall complete the request with **STATUS_SUCCESS** if the request is successful.
Otherwise, the client driver shall complete the driver with to the appropriate error condition,
such as **STATUS_INVALID_PARAMETER** or **STATUS_INSUFFICIENT_RESOURCES**.

## Remarks

UFX sends this IOCTL to the command queue created for the endpoint by [UfxEndpointCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxendpointcreate). The client driver is expected to update the configuration of the endpoint on the controller with the parameters contained in the endpoint descriptor.