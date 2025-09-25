# _SCSI_PASS_THROUGH_DIRECT structure

## Description

The **SCSI_PASS_THROUGH_DIRECT** structure is used in conjunction with an [IOCTL_SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct) request to instruct the port driver to send an embedded SCSI command to the target device.

> [!NOTE]
> The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storage-miniport-drivers) driver models.

## Members

### `Length`

Contains the value of **sizeof**(SCSI_PASS_THROUGH_DIRECT).

### `ScsiStatus`

Reports the SCSI status that was returned by the HBA or the target device.

### `PathId`

Indicates the SCSI port or bus for the request.

### `TargetId`

Indicates the target controller or device on the bus.

### `Lun`

Indicates the logical unit number of the device.

### `CdbLength`

Indicates the size in bytes of the SCSI command descriptor block.

### `SenseInfoLength`

Indicates the size in bytes of the request-sense buffer.

### `DataIn`

Indicates whether the SCSI command will read or write data. This field must have one of three values:

|Data Transfer Type|Meaning|
|----|----|
|SCSI_IOCTL_DATA_IN|Read data from the device.|
|SCSI_IOCTL_DATA_OUT|Write data to the device.|
|SCSI_IOCTL_DATA_UNSPECIFIED|No data transferred.|

### `DataTransferLength`

Indicates the size in bytes of the data buffer. Many devices transfer chunks of data of predefined length. The value in **DataTransferLength** must be an integral multiple of this predefined, minimum length that is specified by the device. If an underrun occurs, the miniport driver must update this member to the number of bytes actually transferred.

### `TimeOutValue`

Indicates the interval in seconds that the request can execute before the OS-specific port driver might consider it timed out.

### `DataBuffer`

Pointer to the data buffer.

### `SenseInfoOffset`

Contains an offset from the beginning of this structure to the request-sense buffer.

### `Cdb`

Specifies the SCSI command descriptor block to be sent to the target device.

## Remarks

The SCSI_PASS_THROUGH_DIRECT structure is used with [IOCTL_SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct). With this request, the system locks down the buffer in user memory and the device accesses this memory directly. For a double-buffered equivalent of this device control request see [IOCTL_SCSI_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through) and [SCSI_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through).

The members of SCSI_PASS_THROUGH_DIRECT correspond roughly to the members of a [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) structure. The values of the **DataIn** member correspond to the SCSI_IOCTL_DATA_IN, SCSI_IOCTL_DATA_OUT, and SCSI_IOCTL_DATA_UNSPECIFIED flags assigned to **SrbFlags** member of SCSI_REQUEST_BLOCK.

## See also

[IOCTL_SCSI_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through)

[IOCTL_SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct)

[SCSI_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through)

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)