# _UCMTCPCI_PORT_CONTROLLER_ALTERNATE_MODE_ENTERED_IN_PARAMS structure

## Description

Stores information about the alternate mode that was detected. This structure is used in the
[IOCTL_UCMTCPCI_PORT_CONTROLLER_ALTERNATE_MODE_ENTERED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_alternate_mode_entered) request.

## Members

### `PortControllerObject`

Handle to the port controller object that the client driver received in the previous call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate).

### `SVID`

The Standard or Vendor ID (SVID) for the alternate mode that was entered. In Windows 10, version 1703, the supported value is DISPLAYPORT_SVID, indicating that the partner device has entered DisplayPort mode.

### `Mode`

The Standard or Vendor defined Mode value for the alternate mode that was entered.

## See also

[IOCTL_UCMTCPCI_PORT_CONTROLLER_ALTERNATE_MODE_ENTERED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_alternate_mode_entered)