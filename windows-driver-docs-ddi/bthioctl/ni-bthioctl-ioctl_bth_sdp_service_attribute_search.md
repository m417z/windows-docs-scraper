# IOCTL_BTH_SDP_SERVICE_ATTRIBUTE_SEARCH IOCTL

## Description

The IOCTL_BTH_SDP_SERVICE_ATTRIBUTE_SEARCH request combines an SDP service and attribute search into
a single operation. This allows a caller to directly obtain SDP records from a remote device.

## Parameters

### Major code

### Input buffer

The
**AssociatedIrp.SystemBuffer** member contains an
**IOCTL_BTH_SDP_SERVICE_ATTRIBUTE_SEARCH** structure that specifies the connection handle to the
remote SDP server, an array of GUIDs, and the range of attribute values to search for.

### Input buffer length

The length of an
**IOCTL_BTH_SDP_SERVICE_ATTRIBUTE_SEARCH** structure.

### Output buffer

The
**AssociatedIrp.SystemBuffer** member points to a buffer that holds a
[BTH_SDP_STREAM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_stream_response) structure
followed by a raw SDP record stream.

### Output buffer length

The length of a
[BTH_SDP_STREAM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_stream_response) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the
**Information** member of the STATUS_BLOCK structure is set to the size, in bytes, of the SDP
response stream or the size of the output buffer, whichever is smaller. Otherwise, the
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

After a profile driver obtains an SDP record, it can use SDP functions to parse them. Pointers to
these functions are provided by the
[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface) interface.

## See also

[BTHDDI_SDP_PARSE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthsdpddi/ns-bthsdpddi-_bthddi_sdp_parse_interface)

[BTH_SDP_STREAM_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_stream_response)

[IOCTL_BTH_SDP_SERVICE_ATTRIBUTE_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_service_attribute_search)