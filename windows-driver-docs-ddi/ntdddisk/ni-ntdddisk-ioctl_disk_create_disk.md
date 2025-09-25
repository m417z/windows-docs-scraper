# IOCTL_DISK_CREATE_DISK IOCTL

## Description

Creates an empty partition for the device object. It can operate on either an EFI disk or an MBR disk. The parameters necessary to create an empty disk depend on the type of partition table that will be put onto the disk. For more information, see [CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_create_disk).

Disk drivers enumerate partitions as though they were child devices. Thus, upon creating the new partition, the disk class driver notifies the PnP manager by means of a call to **IoInvalidateDeviceRelations** that the disk device has a new child device (partition).

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the CREATE_DISK data.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer made available to the driver, which must be >= **sizeof**(CREATE_DISK). Otherwise, the driver returns with an error status of STATUS_INFO_LENGTH_MISMATCH.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS if the operation was successful. Other possible status values are: STATUS_NOT_SUPPORTED if the partition style requested is not supported; STATUS_DEVICE_NOT_READY if the class driver failed to retrieve the disk geometry; and STATUS_INSUFFICIENT_RESOURCES if the class driver failed to obtain a necessary resource, such as heap memory.

## See also

[CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_create_disk)