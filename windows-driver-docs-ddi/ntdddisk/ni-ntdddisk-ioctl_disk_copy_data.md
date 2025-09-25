# IOCTL_DISK_COPY_DATA IOCTL

## Description

This IOCTL_DISK_COPY_DATA IOCTL is used to copy data from one area of the disk to another.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the [DISK_COPY_DATA_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_copy_data_parameters) data. **Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Status** field is set to STATUS_SUCCESS if the operation is successful.

## See also

[DISK_COPY_DATA_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_disk_copy_data_parameters)