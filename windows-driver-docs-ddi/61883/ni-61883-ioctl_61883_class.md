# IOCTL_61883_CLASS IOCTL

## Description

 An IEC-61883 client driver uses the [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control) IRP with **IoControlCode** IOCTL_61883_CLASS to communicate with 1394 driver stack using the IEC-61883 protocol. The driver has access to all operations provided by the IEC-61883 protocol driver through this request.

## Parameters

### Major code

### Input buffer

**Parameters->Others.Argument1** points to an [AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request) structure. The **Function** member of the request structure specifies the type of request. The union member of the request structure specifies the request-type-specific parameters of the request. The parameters and their meaning are documented with each request.

### Input buffer length

### Output buffer

**Parameters->Others.Argument1** points to the AV_61883_REQUEST structure passed as input. As part of completing the request, the bus driver fills in certain submembers of the union within the request structure with information for the driver. The returned information is documented with each request.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The information the IEC-61883 protocol driver returns in the I/O Status Block is documented with each request.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)