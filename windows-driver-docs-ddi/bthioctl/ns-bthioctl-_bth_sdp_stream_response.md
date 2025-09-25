# _BTH_SDP_STREAM_RESPONSE structure

## Description

The BTH_SDP_STREAM_RESPONSE structure contains information about an SDP record.

## Members

### `requiredSize`

The size, in bytes, of the entire SDP record. This value can be useful if the output buffer is too
small to hold the entire record.

### `responseSize`

The size, in bytes, of the raw SDP record stream that follows this structure.

### `response`

The first byte of the SDP record stream.

## Remarks

This structure is returned with a raw stream to the output buffer of the
[IOCTL_BTH_SDP_ATTRIBUTE_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_attribute_search) and
[IOCTL_BTH_SDP_SERVICE_ATTRIBUTE_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_service_attribute_search) IOCTLs.

The
**requiredSize** and
**responseSize** members are included in this structure because the raw SDP record stream does not
contain these fields.

## See also

[IOCTL_BTH_SDP_ATTRIBUTE_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_attribute_search)

[IOCTL_BTH_SDP_SERVICE_ATTRIBUTE_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_service_attribute_search)