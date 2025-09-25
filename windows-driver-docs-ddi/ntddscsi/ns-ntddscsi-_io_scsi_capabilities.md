# _IO_SCSI_CAPABILITIES structure

## Description

The IO_SCSI_CAPABILITIES structure is used in conjunction with the [IOCTL_SCSI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_get_capabilities) request to retrieve the capabilities and limitations of the underlying SCSI host adapter.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver-overview) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Length`

Contains the length in bytes of this structure.

### `MaximumTransferLength`

Contains the maximum size, in bytes, of a single SCSI request block (SRB).

### `MaximumPhysicalPages`

Contains the maximum number of physical pages per data buffer.

### `SupportedAsynchronousEvents`

When **TRUE**, indicates that the host adapter supports SCSI asynchronous receive-event operations.

### `AlignmentMask`

Contains the alignment mask for data transfers. The host adapter requires that data to be transferred must be aligned on an address that is an integer multiple of the value in this field.

### `TaggedQueuing`

When **TRUE**, indicates that the host adapter supports tagged queuing.

### `AdapterScansDown`

When **TRUE**, indicates that the host adapter scans down for BIOS devices.

### `AdapterUsesPio`

When **TRUE**, indicates that the host adapter uses programmed I/O.

## See also

[IOCTL_SCSI_GET_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_get_capabilities)