# _SCSI_ADDRESS structure

## Description

The SCSI_ADDRESS structure is used in conjunction with the [IOCTL_SCSI_GET_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_get_address) request to retrieve the address information, such as the target ID (TID) and the logical unit number (LUN) of a particular SCSI target.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Length`

Contains the length of this structure in bytes.

### `PortNumber`

Contains the number of the SCSI adapter.

### `PathId`

Contains the number of the bus.

### `TargetId`

Contains the number of the target device.

### `Lun`

Contains the logical unit number.

## Remarks

Legacy class drivers issue the [IOCTL_SCSI_GET_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_get_address) request to the port driver to obtain the address of their devices.

## See also

[IOCTL_SCSI_GET_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_get_address)