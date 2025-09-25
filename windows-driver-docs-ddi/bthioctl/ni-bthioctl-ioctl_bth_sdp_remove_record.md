# IOCTL_BTH_SDP_REMOVE_RECORD IOCTL

## Description

The IOCTL_BTH_SDP_REMOVE_RECORD request removes a local SDP record that the profile driver previously
submitted. The local server will no longer offer this record to remote devices.

## Parameters

### Major code

### Input buffer

The
**AssociatedIrp.SystemBuffer** member contains an SDP connection handle from which to remove the SDP
record. This must be a handle returned from a call to
[IOCTL_BTH_SDP_SUBMIT_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_submit_record) or
[IOCTL_BTH_SDP_SUBMIT_RECORD_WITH_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_submit_record_with_info). Handles from other sources are invalid in this
context.

### Input buffer length

The length of the buffer.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The
**Information** member of the STATUS_BLOCK structure is set to zero.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |
| STATUS_DEVICE_NOT_CONNECTED | The remote SDP server is disconnected. |
| STATUS_INVALID_PARAMETER | The SDP connection handle passed in the input buffer is invalid. |
| STATUS_NOT_FOUND | The SDP connection handle passed in the input buffer was not found. |

## Remarks

If the record to be removed was published using IOCTL_BTH_SDP_SUBMIT_RECORD_WITH_INFO, this indicates
that class of device (CoD) bits were set. In this case, calling IOCTL_BTH_SDP_REMOVE_RECORD might cause
the CoD bits to be cleared. The bits will remain set if another client has set them but has not called
this IOCTL.

## See also

[IOCTL_BTH_SDP_SUBMIT_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_submit_record)

[IOCTL_BTH_SDP_SUBMIT_RECORD_WITH_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_submit_record_with_info)