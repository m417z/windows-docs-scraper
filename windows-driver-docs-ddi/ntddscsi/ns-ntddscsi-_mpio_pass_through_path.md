# MPIO_PASS_THROUGH_PATH structure

## Description

The **MPIO_PASS_THROUGH_PATH** structure is used together with an [**IOCTL_MPIO_PASS_THROUGH_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_mpio_pass_through_path) request to instruct the port driver to send an embedded SCSI command to the target device.

## Members

### `PassThrough`

Contains a [**SCSI_PASS_THROUGH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through) structure that is set up in the same way as it is for an [**IOCTL_SCSI_PASS_THROUGH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through) request.

### `Version`

Set to zero.

### `Length`

The size of the **MPIO_PASS_THROUGH_PATH** structure, in bytes.

### `Flags`

Can be a mask of the following values:

* MPIO_IOCTL_FLAG_USE_SCSIADDRESS OR MPIO_IOCTL_FLAG_USE_PATHID
* MPIO_IOCTL_FLAG_INVOLVE_DSM

### `PortNumber`

The port number if MPIO_IOCTL_FLAG_USE_SCSIADDRESS is set. Otherwise, this member is zero. If MPIO_IOCTL_FLAG_USE_SCSIADDRESS is set, the **PathId** and **TargetId** values are taken from the embedded [**SCSI_PASS_THROUGH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through) structure.

### `MpioPathId`

The **PathId** for the real LUN. This value can be obtained by using a WMI request for the PDO_INFORMATION that is associated with the real LUN. This value is set only if MPIO_IOCTL_FLAG_USE_PATHID is set.

## Remarks

The **MPIO_PASS_THROUGH_PATH** structure is used for a double-buffered device control request. To bypass buffering in system memory, callers should use [**IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_mpio_pass_through_path_direct). When the system handles an **IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT** request, it locks down the buffer in user memory, and the device accesses this memory directly.

## See also

[**IOCTL_MPIO_PASS_THROUGH_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_mpio_pass_through_path)

[**IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_mpio_pass_through_path_direct)

[**IOCTL_SCSI_PASS_THROUGH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through)

[**IOCTL_SCSI_PASS_THROUGH_DIRECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct)

[**SCSI_PASS_THROUGH_DIRECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct)

[**SCSI_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)