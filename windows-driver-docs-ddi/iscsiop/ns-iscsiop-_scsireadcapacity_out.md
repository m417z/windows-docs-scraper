# _ScsiReadCapacity_OUT structure (iscsiop.h)

## Description

The ScsiReadCapacity_OUT structure holds the output data for the [ScsiReadCapacity](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireadcapacity6) method.

## Members

### `Status`

The status of the **ScsiReadCapacity** method. This member will contain 0 if the READ CAPACITY operation succeeds and ISDSC_SCSI_REQUEST_FAILED if the operation fails. If the READ CAPACITY operation fails, **ScsiStatus** will contain the SCSI status of the SCSI command. SCSI status qualifiers are documented in the *SCSI Primary Commands* specification. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

### `ResponseBufferSize`

The size, in bytes, of the buffer at **ResponseBuffer***.*

### `ScsiStatus`

The status of the SCSI READ CAPACITY command.

### `SenseBuffer`

A buffer that holds the SCSI sense data that the SCSI READ CAPACITY command received.

### `ResponseBuffer`

A buffer that holds the response data that the SCSI READ CAPACITY command received.

## Remarks

You must implement this method.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[ScsiReadCapacity](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireadcapacity6)

[ScsiReadCapacity_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsireadcapacity_in)