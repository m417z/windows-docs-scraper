# IOCTL_MINIPORT_PROCESS_SERVICE_IRP IOCTL

## Description

This IOCTL is used by a user-mode application or kernel-mode driver that requires notification when something of interest happens in the virtual miniport. This IOCTL might be used, for example, when a vendor-specific, time-consuming operation such as device discovery completes.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a user-defined structure.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of all the input data.

### Output buffer

Updated user-defined structures are returned in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

The length of the buffer.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field contains the number of bytes returned in the output buffer. The **Status** field indicates the results of the operation.

## See also

[HwStorProcessServiceRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_process_service_request)