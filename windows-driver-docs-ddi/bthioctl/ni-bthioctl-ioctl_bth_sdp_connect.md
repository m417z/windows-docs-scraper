# IOCTL_BTH_SDP_CONNECT IOCTL

## Description

The IOCTL_BTH_SDP_CONNECT request creates a connection to the SDP service on a remote Bluetooth
device.

## Parameters

### Major code

### Input buffer

The
**AssociatedIrp.SystemBuffer** member contains a
[BTH_SDP_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_connect) structure that specifies
the address of the remote SDP server, the request's timeout setting, and other information specific to
the connection.

### Input buffer length

Length of a [BTH_SDP_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_connect) structure.

### Output buffer

The
**AssociatedIrp.SystemBuffer** member contains a BTH_SDP_CONNECT structure that holds the SDP
connection handle to the remote server.

### Output buffer length

Length of a [BTH_SDP_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_connect) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the
**Information** member of the STATUS_BLOCK structure is set to the size, in bytes, of the output
buffer. Otherwise, the
**Information** member is set to zero.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |
| STATUS_DEVICE_BUSY | The HCI layer is currently unable to accept requests. |
| STATUS_DEVICE_NOT_CONNECTED | If a cached connection was specified, there are no cached records available. Otherwise, the connection was canceled before it completed. |
| STATUS_INSUFFICIENT_RESOURCES | There was not enough memory available to process the request. |
| STATUS_INVALID_PARAMETER | A portion of the structure found in the input buffer was incorrect. |
| STATUS_PENDING | The system cannot currently respond, but will attempt to shortly. |

## Remarks

The IOCTL_BTH_SDP_CONNECT request allows a profile driver to obtain an SDP connection handle to a
remote device. After the SDP connection handle is obtained, the profile driver can pass it to other SDP
IOCTL interfaces to gather information about the remote device's SDP server. When the SDP queries are
completed, the profile driver must close the SDP connection with
[IOCTL_BTH_SDP_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_disconnect).

## See also

[BTH_SDP_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_sdp_connect)

[IOCTL_BTH_SDP_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_disconnect)