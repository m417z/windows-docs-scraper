# IOCTL_SCSI_GET_ADDRESS IOCTL

## Description

Returns the address information, such as the target ID (TID) and the logical unit number (LUN) of a particular SCSI target. A legacy class driver can issue this request to the port driver to obtain the address of its device. On Windows 10 version 1809 and later versions, a legacy class driver can issue this request to obtain the address of its adapter.

This request is not relevant to storage class drivers that support Plug and Play because the port driver supplies the address information on behalf of the class driver.

This request must be directed to a class driver or to a PDO created by the port driver.

> [!NOTE]
> The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

Updated [SCSI_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_address) information is returned to the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the buffer, which must be >= **sizeof**([SCSI_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_address)).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field contains the number of bytes returned in the output buffer. The **Status** field indicates the results of the operation.

## See also

[SCSI_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_address)