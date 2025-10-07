# IOCTL_EMI_GET_METADATA_SIZE IOCTL

## Description

The **IOCTL_EMI_GET_METADATA_SIZE**
control code retrieves the size of the EMI metadata object that can be obtained from the device by issuing an [IOCTL_EMI_GET_METADATA](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_metadata) request. This should be requested before [IOCTL_EMI_GET_METADATA](https://learn.microsoft.com/windows/win32/api/emi/ni-emi-ioctl_emi_get_metadata) as the size will be vary based on the driver implementation.

## Parameters

### Input buffer

\<text> None. \</text>

### Input buffer length

\<text> None. \</text>

### Output buffer

\<text> The  **AssociatedIrp.SystemBuffer**  member specifies the address of a caller-allocated buffer that contains a [EMI_METADATA_SIZE](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_metadata_size) structure. On output, this structure holds the size of EMI metadata \</text>

### Output buffer length

\<text> The size of this buffer is specified in the  **Parameters.DeviceIoControl.OutputBufferLength**  member. \</text>

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## See also

[Energy Metering Interface](https://learn.microsoft.com/windows-hardware/drivers/powermeter/energy-meter-interface)