# IOCTL_STORAGE_PROTOCOL_COMMAND IOCTL

## Description

A driver can use **IOCTL_STORAGE_PROTOCOL_COMMAND** to pass vendor-specific commands to a storage device.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the results of the vendor-specific command to the buffer at **Irp->AssociatedIrp.SystemBuffer**. Cast the structure returned to a [STORAGE_PROTOCOL_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_command) and check its **ReturnStatus** field to determine the status of the command request.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof**([STORAGE_PROTOCOL_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_command)).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to **STATUS_SUCCESS**, or possibly to **STATUS_INSUFFICIENT_RESOURCES**.

## See also

[STORAGE_PROTOCOL_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_protocol_command)