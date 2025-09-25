# MPIO_PASS_THROUGH_PATH_DIRECT_EX structure

## Description

The **MPIO_PASS_THROUGH_PATH_DIRECT_EX** structure is used together with an [**IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_mpio_pass_through_path_direct_ex) request to instruct the port driver to send an embedded SCSI command to the target device.

## Members

### `PassThroughOffset`

The offset from the beginning of this structure to a [**SCSI_PASS_THROUGH_DIRECT_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct_ex) structure that is configured in the same manner as it is for an [**IOCTL_SCSI_PASS_THROUGH_DIRECT_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct_ex) request.

### `Version`

Set to zero.

### `Length`

The size of the **MPIO_PASS_THROUGH_PATH_DIRECT_EX** structure, in bytes.

### `Flags`

Can be a mask of the following values:

* MPIO_IOCTL_FLAG_USE_SCSIADDRESS OR MPIO_IOCTL_FLAG_USE_PATHID
* MPIO_IOCTL_FLAG_INVOLVE_DSM

### `PortNumber`

The port number if MPIO_IOCTL_FLAG_USE_SCSIADDRESS is set. Otherwise, this member is zero. If MPIO_IOCTL_FLAG_USE_SCSIADDRESS is set, the **PathId** and **TargetId** values are taken from the embedded [**SCSI_PASS_THROUGH_DIRECT_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct_ex) structure.

### `MpioPathId`

The **PathId** for the real LUN. This value can be obtained by using a WMI request for the PDO_INFORMATION that is associated with the real LUN. This value is set only if MPIO_IOCTL_FLAG_USE_PATHID is set.

## Remarks

> [!NOTE]
> All 32-bit processes running on a 64-bit version of Windows must use the **MPIO_PASS_THROUGH_PATH_DIRECT32_EX** structure when issuing an [**IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_mpio_pass_through_path_direct_ex) request.

## See also

[**IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_mpio_pass_through_path_direct_ex)

[**IOCTL_SCSI_PASS_THROUGH_DIRECT_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_pass_through_direct_ex)

[**SCSI_PASS_THROUGH_DIRECT_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_scsi_pass_through_direct_ex)

[**STORAGE_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)