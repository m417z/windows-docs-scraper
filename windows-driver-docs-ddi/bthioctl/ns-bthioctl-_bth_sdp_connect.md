# _BTH_SDP_CONNECT structure

## Description

The BTH_SDP_CONNECT structure contains input and output information about a connection between the local Bluetooth system and a remote SDP server. This structure is passed as the input buffer and output buffer of [IOCTL_BTH_SDP_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_connect).

## Members

### `bthAddress`

The address of the remote SDP server that the local system connects to. This address cannot be to the local radio.

### `fSdpConnect`

A flag or combination of flags that determines how to handle the connection request. Valid flag values are listed in the following table.

| Flag | Description |
|-----------------------|-----------------------------------------------------------------|
| SDP_CONNECT_ALLOW_PIN | If requested, perform a pin exchange with the remote device. |
| SDP_CONNECT_CACHE | Requests are serviced out of the local cache of the SDP record. |

### `HANDLE_SDP_FIELD_NAME`

When the connect request returns, this specifies the handle to the SDP connection to the remote server.

### `requestTimeout`

Timeout, in seconds, for the requests on this SDP channel. If the request times out, the SDP connection represented by the HANDLE_SDP must be closed. The values for this field are bound by SDP_REQUEST_TO_MIN and SDP_REQUEST_MAX. If SDP_REQUEST_TO_DEFAULT is specified, the timeout is 30 seconds.

## See also

- [IOCTL_BTH_SDP_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_connect)