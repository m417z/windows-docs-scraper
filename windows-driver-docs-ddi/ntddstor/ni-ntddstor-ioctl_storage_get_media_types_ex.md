# IOCTL_STORAGE_GET_MEDIA_TYPES_EX IOCTL

## Description

Returns information about the types of media supported by a device. A storage class driver must handle this IOCTL to control devices to be accessed by the removable storage manager (RSM) either as stand-alone devices or as data transfer elements (drives) in a media library or changer device.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns an array of [DEVICE_MEDIA_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_media_info) structures, one for each media type supported by the device, embedded in a [GET_MEDIA_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_get_media_types) structure in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the parameter buffer, which must be >= **sizeof(**GET_MEDIA_TYPES**)** plus additional device-type-specific data, if any.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INFO_LENGTH_MISMATCH or STATUS_INSUFFICIENT_RESOURCES.

## See also

[DEVICE_MEDIA_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_media_info)

[GET_MEDIA_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_get_media_types)