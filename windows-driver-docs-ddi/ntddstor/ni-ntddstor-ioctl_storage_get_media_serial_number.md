# IOCTL_STORAGE_GET_MEDIA_SERIAL_NUMBER IOCTL

## Description

Queries the USB generic parent driver for the serial number of a USB device. If a USB device has a CSM-1 content security interface, a USB client driver can query for its serial number using this request. USB client drivers that help implement a digital rights management (DRM) system can use this information to ensure that only legitimate customers have access to digitized intellectual property.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns the serial number of the indicated device in a structure of type [MEDIA_SERIAL_NUMBER_DATA](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff562213(v=vs.85)) in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be at least **sizeof**(MEDIA_SERIAL_NUMBER_DATA).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the size, in bytes, of the returned data. The **Status** field can be set to STATUS_SUCCESS, or possibly to STATUS_INVALID_BUFFER_SIZE or STATUS_INSUFFICIENT_RESOURCES.

## See also

[MEDIA_SERIAL_NUMBER_DATA](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff562213(v=vs.85))