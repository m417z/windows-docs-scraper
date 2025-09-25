# IOCTL_BTH_GET_RADIO_INFO IOCTL

## Description

The IOCTL_BTH_GET_RADIO_INFO request obtains information about the specified remote radio.

## Parameters

### Major code

### Input buffer

The
**AssociatedIrp.SystemBuffer** member specifies the Bluetooth address of the remote radio to
query.

### Input buffer length

The length of the buffer.

### Output buffer

The
**AssociatedIrp.SystemBuffer** member points to a buffer that holds a
[BTH_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_radio_info) structure. This structure
contains information about the remote radio's feature support for the Link Management Protocol (LMP),
the radio's manufacturer ID, and its LMP version.

### Output buffer length

The length of a
[BTH_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_radio_info) structure.

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
| STATUS_DEVICE_NOT_CONNECTED | The device object for the specified device was not connected. |

## Remarks

The IOCTL_BTH_GET_RADIO_INFO IOCTL returns similar information as the IOCTL_BTH_GET_LOCAL_INFO IOCTL,
but for a remote Bluetooth radio.

## See also

[BTH_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_radio_info)