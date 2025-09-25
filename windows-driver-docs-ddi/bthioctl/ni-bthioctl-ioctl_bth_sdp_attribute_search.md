# IOCTL_BTH_SDP_ATTRIBUTE_SEARCH IOCTL

## Description

The IOCTL_BTH_SDP_ATTRIBUTE_SEARCH request obtains attributes for the specified SDP record.

## Parameters

### Major code

### Input buffer

The
**AssociatedIrp.SystemBuffer** member contains a
[BTH_SDP_ATTRIBUTE_SEARCH_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_attribute_search_request) structure that specifies the remote computer range of attributes
to search plus other key members.

### Input buffer length

The length of a
[BTH_SDP_ATTRIBUTE_SEARCH_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_attribute_search_request) structure.

### Output buffer

The
**AssociatedIrp.SystemBuffer** member points to a buffer that contains a
[BTH_SDP_STREAM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_stream_response) structure
that is followed by a variable-length raw SDP stream.

### Output buffer length

The length of a
[BTH_SDP_STREAM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_stream_response) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the
**Information** member of the STATUS_BLOCK structure is set to the size, in bytes, of the
[BTH_SDP_STREAM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_stream_response) or the size
of the output buffer, whichever is smaller. Otherwise, the
**Information** member is set to zero.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |
| STATUS_DEVICE_NOT_CONNECTED | The device on which the SDP service resides was not connected. |
| STATUS_INSUFFICIENT_RESOURCES | There was not enough memory to complete this operation. |
| STATUS_INVALID_BUFFER_SIZE | The output buffer was sized incorrectly. |
| STATUS_INVALID_PARAMETER | One of the values in the input buffer was not valid. |
| STATUS_REQUEST_NOT_ACCEPTED | The SDP service rejected the request. |
| STATUS_TOO_MANY_GUIDS_REQUESTED | The SDP service could not process the number of GUIDs passed in the input buffer. |

## Remarks

In most circumstances, profile drivers can combine SDP service and attribute searches by calling the
[IOCTL_BTH_SDP_SERVICE_ATTRIBUTE_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_service_attribute_search) IOCTL. If a profile driver must reduce the amount of SDP
traffic that is transmitted over the Bluetooth link, or extract information from the SDP server by using
a small number of message transfer units (MTUs), the profile driver should call the
[IOCTL_BTH_SDP_SERVICE_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_service_search) IOCTL to perform a service search. The profile driver should then call
the IOCTL_BTH_SDP_ATTRIBUTE_SEARCH IOCTL to perform an attribute search.

The BTH_SDP_STREAM_RESPONSE structure returned in the output buffer contains information about the
size of the entire SDP record, the size, in bytes, of the raw SDP record stream that follows the
BTH_SDP_STREAM_RESPONSE structure, and the first byte of that stream. The variable-length stream is the
SDP record attributes returned by the search.

## See also

[BTH_SDP_ATTRIBUTE_SEARCH_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_attribute_search_request)

[BTH_SDP_STREAM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_stream_response)

[IOCTL_BTH_SDP_SERVICE_ATTRIBUTE_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_service_attribute_search)

[IOCTL_BTH_SDP_SERVICE_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_service_search)