# IOCTL_DVD_READ_STRUCTURE IOCTL

## Description

Returns information about a DVD disc, such as a layer descriptor, copyright information, or manufacturer-specific information.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-dvd_read_structure) structure that indicates the session ID and type of information to return.

### Input buffer length

Length of a [DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-dvd_read_structure).

### Output buffer

The driver returns the disc information in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the buffer, which must be >= **sizeof(***Descriptor***)** where *Descriptor* is [DVD_LAYER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_layer_descriptor), [DVD_COPYRIGHT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_copyright_descriptor), [DVD_DISK_KEY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_disk_key_descriptor), [DVD_BCA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_bca_descriptor), or [DVD_MANUFACTURER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_manufacturer_descriptor).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INSUFFICIENT_RESOURCES.

## See also

[DVD_BCA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_bca_descriptor)

[DVD_COPYRIGHT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_copyright_descriptor)

[DVD_DISK_KEY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_disk_key_descriptor)

[DVD_LAYER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_layer_descriptor)

[DVD_MANUFACTURER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_manufacturer_descriptor)

[DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-dvd_read_structure)