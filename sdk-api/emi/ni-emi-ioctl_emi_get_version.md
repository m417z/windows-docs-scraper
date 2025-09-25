# IOCTL_EMI_GET_VERSION IOCTL

## Description

The **IOCTL_EMI_GET_VERSION**
control code retrieves the current version of the EMI interface supported by the device.

## Parameters

### Input buffer

 None.

### Input buffer length

 None.

### Output buffer

 The  **AssociatedIrp.SystemBuffer**  member specifies the address of a caller-allocated buffer that contains a EMI_VERSION structure. On output, this structure holds the EMI version that is supported by the device.

### Output buffer length

 The size of this buffer is specified in the  **Parameters.DeviceIoControl.OutputBufferLength**  member.

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

### Remarks

 **EMI_VERSION_V1**  indicate there is only one single energy measurement channel supported by the device.
 **EMI_VERSION_V2**  indicate there is multiple energy measurement channels supported by the device.

## See also

[Energy Metering Interface](https://learn.microsoft.com/windows-hardware/drivers/powermeter/energy-meter-interface)