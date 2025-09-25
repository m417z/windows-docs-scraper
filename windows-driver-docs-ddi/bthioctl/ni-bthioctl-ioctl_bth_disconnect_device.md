# IOCTL_BTH_DISCONNECT_DEVICE IOCTL

## Description

Profile drivers use IOCTL_BTH_DISCONNECT_DEVICE to request the operating system to disconnect the
specified remote device.

## Parameters

### Major code

### Input buffer

The
**AssociatedIrp.SystemBuffer** member contains the address of the remote device to disconnect
from.

### Input buffer length

The length of the address in the buffer.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The
**Information** member of the STATUS_BLOCK structure is set to zero because the Bluetooth driver
stack returns no data with this IOCTL.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |
| STATUS_DEVICE_NOT_CONNECTED | The specified remote device is not connected. |

## Remarks

Calling IOCTL_BTH_DISCONNECT_DEVICE forces a disconnect from the remote device without regard to the
state of any L2CAP and SCO connections. All active SCO connections will be disconnected before the ACL
connection is disconnected. Pending data transfers might fail.