# _UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_HPD_STATUS_CHANGED_IN_PARAMS structure

## Description

Stores information about hot plug detect status of the DisplayPort connection. This structure is used in the
[IOCTL_UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_HPD_STATUS_CHANGED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_displayport_hpd_status_changed) request.

## Members

### `PortControllerObject`

Handle to the port controller object that the client driver received in the previous call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate).

### `HPDStatus`

A [UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_HPD_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ne-ucmtcpciportcontrollerrequests-_ucmtcpci_port_controller_displayport_hpd_status)-type value that indicates status.

## See also

[IOCTL_UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_HPD_STATUS_CHANGED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_displayport_hpd_status_changed)