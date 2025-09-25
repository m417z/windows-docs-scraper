# _ScsiInquiry_OUT structure (iscsiop.h)

## Description

The ScsiInquiry_OUT structure holds the output data for the [ScsiInquiry](https://learn.microsoft.com/windows-hardware/drivers/storage/scsiinquiry) method.

## Members

### `Status`

The status of the **ScsiInquiry** operation. This member will contain 0 if the INQUIRY operation succeeds and ISDSC_SCSI_REQUEST_FAILED if the operation fails. If the INQUIRY operation fails, **ScsiStatus** will contain the SCSI status of the SCSI command. SCSI status qualifiers are documented in the *SCSI Primary Commands* specification. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

### `ResponseBufferSize`

The response buffer size, in bytes*.*

### `ScsiStatus`

The status of the SCSI INQUIRY command.

### `SenseBuffer`

A buffer that holds the SCSI sense data that the SCSI INQUIRY command received.

### `ResponseBuffer`

A buffer that holds the response data that the SCSI INQUIRY command received.

## Remarks

You must implement this method.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[ScsiInquiry](https://learn.microsoft.com/windows-hardware/drivers/storage/scsiinquiry)

[ScsiInquiry_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_scsiinquiry_in)