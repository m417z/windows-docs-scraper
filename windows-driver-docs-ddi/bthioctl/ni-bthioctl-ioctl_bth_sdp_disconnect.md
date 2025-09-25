# IOCTL_BTH_SDP_DISCONNECT IOCTL

## Description

The IOCTL_BTH_SDP_DISCONNECT request closes a connection to a remote SDP server.

## Parameters

### Major code

### Input buffer

The
**AssociatedIrp.SystemBuffer** member contains an
[BTH_SDP_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_disconnect) structure that
specifies the connection handle to the remote SDP connection to terminate.

### Input buffer length

Length of an
[BTH_SDP_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_disconnect) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The
**Information** member of the STATUS_BLOCK structure is set to zero.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |
| STATUS_DEVICE_NOT_CONNECTED | The specified SDP server has already been disconnected. |
| STATUS_INVALID_PARAMETER | The connection handle passed in the input buffer is invalid. |

## Remarks

Callers of
[IOCTL_BTH_SDP_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_connect) must issue an
IOCTL_BTH_SDP_DISCONNECT IOCTL when the SDP connection is no longer needed. After
IOCTL_BTH_SDP_DISCONNECT is called, the specified SDP handle is no longer valid.

## See also

[BTH_SDP_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_disconnect)

[IOCTL_BTH_SDP_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_connect)