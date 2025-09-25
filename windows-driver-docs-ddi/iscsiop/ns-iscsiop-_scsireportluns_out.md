# _ScsiReportLuns_OUT structure (iscsiop.h)

## Description

The ScsiReportLuns_OUT structure holds the output data for the [ScsiReportLuns](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireportluns6) method.

## Members

### `Status`

The status of the **ScsiReportLuns** method. This member will contain 0 if the REPORT LUNS operation succeeds and ISDSC_SCSI_REQUEST_FAILED if the operation fails. If the REPORT LUNS operation fails, **ScsiStatus** will contain the SCSI status of the SCSI command. SCSI status qualifiers are documented in the *SCSI Primary Commands* specification. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

### `ResponseBufferSize`

The size, in bytes, of the buffer at **ResponseBuffer***.*

### `ScsiStatus`

The status of the SCSI REPORT LUNS command.

### `SenseBuffer`

A buffer that holds the SCSI sense data that the SCSI REPORT LUNS command received.

### `ResponseBuffer`

A buffer that holds the response data that the SCSI REPORT LUNS command received.

## Remarks

You must implement this method.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[ScsiReportLuns](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireportluns6)

[ScsiReportLuns_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsireportluns_in)