# _BTH_SDP_SERVICE_SEARCH_REQUEST structure

## Description

The BTH_SDP_SERVICE_SEARCH_REQUEST structure contains information pertinent to an SDP service search.

## Members

### `HANDLE_SDP_FIELD_NAME`

Handle returned by the connect request or HANDLE_SDP_LOCAL.

### `uuids`

An array of UUIDs that represent the services for which to query. Each entry can be a 2-byte, 4-byte, or 16-byte type, and there can be a maximum of 12 entries. The array can be terminated before all 12 entries are used if a UUID entry contains all zeros.

## Remarks

This structure is passed as the input buffer to the [IOCTL_BTH_SDP_SERVICE_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_service_search) IOCTL.

## See also

- [IOCTL_BTH_SDP_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_connect)
- [IOCTL_BTH_SDP_SERVICE_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_service_search)