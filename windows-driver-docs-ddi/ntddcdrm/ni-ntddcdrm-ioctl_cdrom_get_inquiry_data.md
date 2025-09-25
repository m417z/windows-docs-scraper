# IOCTL_CDROM_GET_INQUIRY_DATA IOCTL

## Description

Returns the SCSI inquiry data for the CD-ROM device. This IOCTL can be used when a device has been exclusively locked with [IOCTL_CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_exclusive_access).

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the returned inquiry data. For a description of the layout of the inquiry data in the output buffer, see [INQUIRYDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_inquirydata).

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** indicates the number of bytes that can be written to **Irp->AssociatedIrp.SystemBuffer**, which must be >= **sizeof**([INQUIRYDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_inquirydata)).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field contains the number of bytes returned in the output buffer. The **Status** field indicates the results of the operation.

## Remarks

## See also

[INQUIRYDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_inquirydata)

[IOCTL_CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_exclusive_access)