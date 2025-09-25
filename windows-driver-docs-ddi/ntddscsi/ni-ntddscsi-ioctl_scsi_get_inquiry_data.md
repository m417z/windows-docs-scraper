# IOCTL_SCSI_GET_INQUIRY_DATA IOCTL

## Description

Returns the SCSI inquiry data for all devices on a given SCSI host bus adapter (HBA). If the IOCTL is employed in user space, the program must have opened a handle to the HBA, which can be enumerated by various means, such as SetupDixxx calls. You can use [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) to find information about a specific device on the HBA. To determine the size of the output buffer that is required, the caller should send this IOCTL request in a loop. Every time that the storage stack rejects the IOCTL with an error message that indicates that the buffer was too small, the caller should double the buffer size.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the returned inquiry data. For a description of the layout of the inquiry data in the output buffer, see [SCSI_ADAPTER_BUS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_adapter_bus_info).

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** indicates the size, in bytes, of the buffer, which must be >= (**sizeof**(SCSI_ADAPTER_BUS_INFO) + (*NumberOfBuses*) * **sizeof**(SCSI_BUS_DATA)) + (*InquiryDataSize* * *NumberOfLUs*), where the *InquiryDataSize* is (**sizeof**(SCSI_INQUIRY_DATA) - 1 + INQUIRYDATABUFFERSIZE) rounded up to an alignment boundary.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field contains the number of bytes returned in the output buffer. The **Status** field indicates the results of the operation.

## See also

[IOCTL_SCSI_MINIPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport)

[IOCTL_SCSI_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through)

[IOCTL_SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct)

[IOCTL_SCSI_RESCAN_BUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_rescan_bus)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[SCSI_ADAPTER_BUS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_adapter_bus_info)

[SCSI_INQUIRY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_inquiry_data)

[STORAGE_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_descriptor)