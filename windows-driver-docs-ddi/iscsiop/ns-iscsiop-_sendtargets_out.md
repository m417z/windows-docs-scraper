# _SendTargets_OUT structure

## Description

The SendTargets_OUT structure holds the output data for the [SendTargets](https://learn.microsoft.com/windows-hardware/drivers/storage/sendtargets) method.

## Members

### `Status`

The status of the **SendTargets** method. This member will contain 0 if the SEND TARGETS operation succeeds and ISDSC_SCSI_REQUEST_FAILED if the operation fails. If the SEND TARGETS operation fails, **ScsiStatus** will contain the SCSI status of the SCSI command. SCSI status qualifiers are documented in the *SCSI Primary Commands* specification. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

### `ResponseSize`

The size, in bytes, of the buffer at Response.

### `Response`

A buffer that holds the response data that the target returns. Response to SendTargets in UTF8 characters. NOTE: This field is a variable length array.

## Remarks

You must implement this method.

## See also

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[SendTargets](https://learn.microsoft.com/windows-hardware/drivers/storage/sendtargets)

[SendTargets_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_sendtargets_in)