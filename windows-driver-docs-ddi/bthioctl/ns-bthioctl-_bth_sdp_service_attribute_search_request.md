# _BTH_SDP_SERVICE_ATTRIBUTE_SEARCH_REQUEST structure

## Description

The BTH_SDP_SERVICE_ATTRIBUTE_SEARCH_REQUEST structure contains information pertinent to a combined SDP service and attribute search. This structure is passed as the input buffer to the [IOCTL_BTH_SDP_SERVICE_ATTRIBUTE_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_service_attribute_search) IOCTL.

## Members

### `HANDLE_SDP_FIELD_NAME`

Handle returned by the connect request or HANDLE_SDP_LOCAL.

### `searchFlags`

A combination of SDP_SEARCH_Xxx flags.

### `uuids`

An array of UUIDs that represent the services for which to query. Each entry can be a 2-byte, 4-byte, or 16-byte type, and there can be a maximum of 12 entries. The array can be terminated before all 12 entries are used if a UUID entry contains all zeros.

### `range`

A variable-length array of [SdpAttributeRange](https://learn.microsoft.com/windows/win32/api/bthsdpdef/ns-bthsdpdef-sdpattributerange) structures that contains the range of SDP attributes for which to search.

## Remarks

The Bluetooth driver stack determines the number of array items in the **range** member by examining the length of IOCTL_BTH_SDP_SERVICE_ATTRIBUTE_SEARCH input buffer. Because of this, the **Parameters.DeviceIoControl.InputBufferLength** member passed when the IOCTL is called must be calculated exactly.

## See also

- [IOCTL_BTH_SDP_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_connect)
- [IOCTL_BTH_SDP_SERVICE_ATTRIBUTE_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_service_attribute_search)
- [SdpAttributeRange](https://learn.microsoft.com/windows/win32/api/bthsdpdef/ns-bthsdpdef-sdpattributerange)