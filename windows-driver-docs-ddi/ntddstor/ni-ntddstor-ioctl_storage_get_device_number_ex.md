# IOCTL_STORAGE_GET_DEVICE_NUMBER_EX IOCTL

## Description

Returns a [**STORAGE_DEVICE_NUMBER_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_number_ex) structure that contains the FILE_DEVICE_*XXX* type, device number, device GUID, and, for a partitionable device, the partition number assigned to a device by the driver when the device is started. This request is usually issued by a fault-tolerant disk driver.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the [**STORAGE_DEVICE_NUMBER_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_number_ex) data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= ```sizeof(STORAGE_DEVICE_NUMBER_EX)```.

### Input/output buffer

n/a

### Input/output buffer length

n/a

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INSUFFICIENT_RESOURCES.

## See also

[**IOCTL_STORAGE_GET_DEVICE_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_number)

[**STORAGE_DEVICE_NUMBER_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_number_ex)