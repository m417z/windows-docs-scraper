# IOCTL_SCSI_GET_CAPABILITIES IOCTL

## Description

Returns the capabilities and limitations of the underlying SCSI HBA. The most important information is returned in the **MaximumTransferLength** and **AlignmentMask** members. Class drivers and users of [IOCTL_SCSI_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through) and [IOCTL_SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct) are required to honor these limitations.

Only legacy drivers can issue this request. The request fails if it is sent to a PDO created by the port driver.

To get SCSI capabilities data, a Plug and Play driver must issue an [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request for [STORAGE_ADAPTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_adapter_descriptor) data to the PDO for each device to which the driver has been added (that is, each device for which the driver has received an *AddDevice* call). A legacy driver should forward this request to the port driver. This request fails if it is sent to the FDO for an adapter.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

Updated [IO_SCSI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_io_scsi_capabilities) information is returned to the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the buffer, which must be >= **sizeof**(IO_SCSI_CAPABILITIES).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field contains the number of bytes returned in the output buffer. The **Status** field indicates the results of the operation.

## See also

[IO_SCSI_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_io_scsi_capabilities)