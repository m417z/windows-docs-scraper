# IOCTL_BTH_SDP_SERVICE_SEARCH IOCTL

## Description

The IOCTL_BTH_SDP_SERVICE_SEARCH request contacts a remote device with an SDP request for handles to
SDP records of a particular service class or classes.

## Parameters

### Major code

### Input buffer

The
**AssociatedIrp.SystemBuffer** member contains a
[BTH_SDP_SERVICE_SEARCH_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_service_search_request) structure that specifies the connection handle to the remote SDP
server and an array of GUIDs to search for.

### Input buffer length

The length of a
[BTH_SDP_SERVICE_SEARCH_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_service_search_request) structure/

### Output buffer

The
**AssociatedIrp.SystemBuffer** member points to a buffer that contains a variable length array of
unsigned long integer values. Each value represents a remote SDP service record.

### Output buffer length

Callers can determine
the length of this array by dividing the
**Information** member of the STATUS_BLOCK structure by
`sizeof(ULONG)`.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the
**Information** member of the STATUS_BLOCK structure is set to the size, in bytes, of the output
buffer. Otherwise, the
**Information** member is set to zero.

The
**Status** member is set to one of values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |
| STATUS_DEVICE_NOT_CONNECTED | The device on which the SDP service resides was not connected. |
| STATUS_INSUFFICIENT_RESOURCES | There was not enough memory to complete this operation. |
| STATUS_INVALID_BUFFER_SIZE | The output buffer was sized incorrectly. |
| STATUS_INVALID_PARAMETER | One of the values in the input buffer was not valid. |
| STATUS_REQUEST_NOT_ACCEPTED | The SDP service rejected the request. |
| STATUS_TOO_MANY_GUIDS_REQUESTED | The SDP service could not process the number of GUIDs passed in the input buffer. |

## See also

[BTH_SDP_SERVICE_SEARCH_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_service_search_request)