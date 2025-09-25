# IOCTL_AVCSTRM_CLASS IOCTL

## Description

An AV/C subunit driver uses the [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control) IRP, with the **IoControlCode** member set to IOCTL_AVCSTRM_CLASS, to communicate with *avcstrm.sys*. The driver has access to all operations provided by the AV/C Streaming filter driver (*avcstrm.sys*) through this request.

For more information about IRPs and IOCTLs, see [Handling IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-irps).

## Parameters

### Major code

### Input buffer

On input, **Irp->Parameters->Others.Arguments1** points to an [AVC_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_avc_stream_request_block) structure. The **Function** member of the AVC_STREAM_REQUEST_BLOCK specifies the type of request. Do not set this member directly. Use the [INIT_AVCSTRM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/nf-avcstrm-init_avcstrm_header) macro to initialize this member (as well as additional members of the AVC_STREAM_REQUEST_BLOCK structure). The **CommandData** member of the AVC_STREAM_REQUEST_BLOCK is a union that specifies the request-type-specific parameters of the request. The parameters and their meaning are documented with each request (function code). The [AVCSTRM_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ne-avcstrm-_avcstrm_function) enumeration provides a list of function codes supported by *avcstrm.sys*.

### Input buffer length

Length of an [AVC_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_avc_stream_request_block) structure.

### Output buffer

On output, **Irp->Parameters->Others.Arguments1** points to the [AVC_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_avc_stream_request_block) structure passed as input. As part of completing the request, the bus driver fills in certain members of the **CommandData** union of the AVC_STREAM_REQUEST_BLOCK structure with information for the driver.

### Output buffer length

Length of an [AVC_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_avc_stream_request_block) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The information the AV/C Streaming driver returns in the I/O Status Block is documented with each request.

## Remarks

Must be called at IRQL = PASSIVE_LEVEL.

## See also

[AVCSTRM_ABORT_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-abort-streaming)

[AVCSTRM_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-close)

[AVCSTRM_GET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-get-property)

[AVCSTRM_GET_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-get-state)

[AVCSTRM_OPEN](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-open)

[AVCSTRM_READ](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-read)

[AVCSTRM_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-set-property)

[AVCSTRM_SET_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-set-state)

[AVCSTRM_WRITE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-write)