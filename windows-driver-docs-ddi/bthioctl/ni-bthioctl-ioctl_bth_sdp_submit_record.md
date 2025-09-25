# IOCTL_BTH_SDP_SUBMIT_RECORD IOCTL

## Description

The IOCTL_BTH_SDP_SUBMIT_RECORD request allows a profile driver to add an SDP record to the local SDP
server, allowing the client to advertise that a service is available on the local computer. The profile
driver calls
[IOCTL_BTH_SDP_REMOVE_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_remove_record) to
stop advertising the server on the local SDP server.

## Parameters

### Major code

### Input buffer

The
**AssociatedIrp.SystemBuffer** member specifies the raw SDP stream that contains the record to
advertise.

### Input buffer length

The length of the stream.

### Output buffer

The
**AssociatedIrp.SystemBuffer** member points to a buffer that holds a handle to the SDP record. This
handle can only be used by IOCTL_BTH_SDP_REMOVE_RECORD to remove the record submitted by
IOCTL_BTH_SDP_SUBMIT_RECORD.

### Output buffer length

The length of the buffer.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the
**Information** member of the STATUS_BLOCK structure is set to the size, in bytes, of the handle that
the IOCTL returns. Otherwise, the
**Information** member is set to zero.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |
| STATUS_INSUFFICIENT_RESOURCES | Not enough memory was allocated to process this request. |
| STATUS_INVALID_BUFFER_SIZE | The output buffer was sized incorrectly. |
| STATUS_INVALID_PARAMETER | The stream passed to the input buffer was invalid. |

## See also

[IOCTL_BTH_SDP_REMOVE_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_remove_record)