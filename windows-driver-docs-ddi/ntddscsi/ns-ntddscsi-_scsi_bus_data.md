# _SCSI_BUS_DATA structure

## Description

The SCSI_BUS_DATA structure is used in conjunction with the [IOCTL_SCSI_GET_INQUIRY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_get_inquiry_data) request and the [SCSI_ADAPTER_BUS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_adapter_bus_info) structure to retrieve the SCSI inquiry data for all devices on a given SCSI bus.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `NumberOfLogicalUnits`

Contains the number of logical units on the bus for which inquiry data is being retrieved.

### `InitiatorBusId`

Contains the SCSI bus ID for the adapter.

### `InquiryDataOffset`

Contains an offset from the beginning of the SCSI_ADAPTER_BUS_INFO structure to the inquiry data.

## See also

[IOCTL_SCSI_GET_INQUIRY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_get_inquiry_data)

[SCSI_ADAPTER_BUS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_adapter_bus_info)