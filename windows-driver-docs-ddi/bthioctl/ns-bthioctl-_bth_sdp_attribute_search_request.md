# _BTH_SDP_ATTRIBUTE_SEARCH_REQUEST structure

## Description

The BTH_SDP_ATTRIBUTE_SEARCH_REQUEST structure contains information pertinent to an SDP attribute search.

## Members

### `HANDLE_SDP_FIELD_NAME`

Handle returned by the connect request or HANDLE_SDP_LOCAL.

### `searchFlags`

Combination of SDP_SEARCH_Xxx flags.

### `recordHandle`

The record handle that is returned by the remote SDP server from a previous call to the [IOCTL\_BTH\_SDP\_SERVICE\_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_service_search) IOCTL.

### `range`

A variable-length array of structures of type [SdpAttributeRange](https://learn.microsoft.com/windows/win32/api/bthsdpdef/ns-bthsdpdef-sdpattributerange) that contains the range of SDP attributes for which to search. The range array must be in ascending numeric order.

## Remarks

This structure is passed as the input buffer to the [IOCTL\_BTH\_SDP\_ATTRIBUTE\_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_attribute_search) IOCTL.

The Bluetooth driver stack determines the number of array items in the **range** member by examining the length of the IOCTL_BTH_SDP_ATTRIBUTE_SEARCH input buffer. Because of this, you must calculate the exact value of the **Parameters.DeviceIoControl.InputBufferLength** member that is passed when IOCTL_BTH_SDP_SERVICE_SEARCH is called.

## See also

- [IOCTL\_BTH\_SDP\_ATTRIBUTE\_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_attribute_search)
- [IOCTL\_BTH\_SDP\_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_connect)
- [IOCTL\_BTH\_SDP\_SERVICE\_SEARCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_service_search)
- [SdpAttributeRange](https://learn.microsoft.com/windows/win32/api/bthsdpdef/ns-bthsdpdef-sdpattributerange)