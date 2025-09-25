# _BTH_SDP_DISCONNECT structure

## Description

The BTH_SDP_DISCONNECT structure contains input information about a connection handle to the remote SDP connection to terminate. This structure is passed as the input buffer of [IOCTL_BTH_SDP_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_disconnect).

## Members

### `HANDLE_SDP_FIELD_NAME`

When the connect request returns, this specifies the handle to the SDP connection to the remote server.

## See also

- [BTH_SDP_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_connect)
- [IOCTL_BTH_SDP_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_connect)
- [IOCTL_BTH_SDP_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_disconnect)