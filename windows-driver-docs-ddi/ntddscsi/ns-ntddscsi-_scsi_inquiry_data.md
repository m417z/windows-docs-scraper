# _SCSI_INQUIRY_DATA structure

## Description

The SCSI_INQUIRY_DATA structure is used in conjunction with the [IOCTL_SCSI_GET_INQUIRY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_get_inquiry_data) request to retrieve the SCSI inquiry data for all devices on a given SCSI bus.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `PathId`

Indicates the number of the bus the device is located on.

### `TargetId`

Indicates the number of the device on the bus.

### `Lun`

Indicates the logical unit number of the logical unit on the target device.

### `DeviceClaimed`

When **TRUE**, indicates that the device has been claimed by a class driver.

### `InquiryDataLength`

Indicates the length in bytes of inquiry data.

### `NextInquiryDataOffset`

Contains an offset to the inquiry data for the next logical unit on the target device.

### `InquiryData`

Pointer to buffer containing the inquiry data for the logical unit.

## Remarks

The [IOCTL_SCSI_GET_INQUIRY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_get_inquiry_data) request retrieves inquiry data for all devices associated with a specified adapter. An adapter can potentially have multiple buses. The **PathId** member identifies the bus. Each bus can have multiple target devices. The **TargetId** member identifies the target device, and each target device can have multiple logical units. The **Lun** member identifies the logical unit.

## See also

[IOCTL_SCSI_GET_INQUIRY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_get_inquiry_data)

[SCSI_ADAPTER_BUS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_adapter_bus_info)

[SCSI_BUS_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_bus_data)