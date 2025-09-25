# IOCTL_BTH_SDP_SUBMIT_RECORD_WITH_INFO IOCTL

## Description

The IOCTL_BTH_SDP_SUBMIT_RECORD_WITH_INFO request adds an SDP record to the local SDP server along with attributes that are not part of the SDP record itself. After this call completes successfully, the profile driver can advertise that a service is available on the local computer. The profile driver calls [IOCTL_BTH_SDP_REMOVE_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_remove_record) to stop advertising the service on the local SDP server.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member contains a [BTH_SDP_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_record) structure that specifies the SDP record to add, its size, the required security for the record, and publication options for the record. The structure is followed by the raw SDP record.

### Input buffer length

The length of a [BTH_SDP_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_record) structure.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a buffer that holds a handle to the SDP record. This handle can only be used by IOCTL_BTH_SDP_REMOVE_RECORD to remove the record submitted by IOCTL_BTH_SDP_SUBMIT_RECORD_WITH_INFO.

### Output buffer length

The length of the handle to the SDP record.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the **Information** member of the STATUS_BLOCK structure is set to the size, in bytes, of the handle that the IOCTL returns. Otherwise, the **Information** member is set to zero.

The **Status** member is set to one of the values in the following table:

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |
| STATUS_INSUFFICIENT_RESOURCES | Not enough memory was allocated to process this request. |
| STATUS_INVALID_BUFFER_SIZE | The output buffer was sized incorrectly. |
| STATUS_INVALID_PARAMETER | A member of the structure passed to the input buffer, or the stream passed to the input buffer, was invalid. |

## See also

[BTH_SDP_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_record)

[IOCTL_BTH_SDP_SUBMIT_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_submit_record)