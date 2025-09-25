# _SCSI_PASS_THROUGH structure

## Description

The SCSI_PASS_THROUGH structure is used in conjunction with an [IOCTL_SCSI_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through) request to instruct the port driver to send an embedded SCSI command to the target device.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Length`

Contains the value of **sizeof**(SCSI_PASS_THROUGH).

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

##### This field must have one of three values:

#######

### `DataTransferLength`

Indicates the size in bytes of the data buffer. Many devices transfer chunks of data of predefined length. The value in **DataTransferLength** must be an integral multiple of this predefined, minimum length that is specified by the device. If an underrun occurs, the miniport driver must update this member to the number of bytes actually transferred.

### `TimeOutValue`

Indicates the interval in seconds that the request can execute before the port driver considers it timed out.

### `DataBufferOffset`

Contains an offset from the beginning of this structure to the data buffer. The offset must respect the data alignment requirements of the device.

### `SenseInfoOffset`

Offset from the beginning of this structure to the request-sense buffer.

### `Cdb`

Specifies the SCSI command descriptor block to be sent to the target device.

## Remarks

The SCSI_PASS_THROUGH structure is used with [IOCTL_SCSI_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through), which is a buffered device control request. To bypass buffering in system memory, callers should use [IOCTL_SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct). When handling an IOCTL_SCSI_PASS_THROUGH_DIRECT request, the system locks down the buffer in user memory and the device accesses this memory directly.

The members of SCSI_PASS_THROUGH correspond roughly to the members of a [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) structure. The values of the **DataIn** member correspond to the SCSI_IOCTL_DATA_IN, SCSI_IOCTL_DATA_OUT, and SCSI_IOCTL_DATA_UNSPECIFIED flags assigned to **SrbFlags** member of SCSI_REQUEST_BLOCK.

## See also

[IOCTL_SCSI_PASS_THROUGH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through)

[IOCTL_SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct)

[SCSI_PASS_THROUGH_DIRECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct)

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)