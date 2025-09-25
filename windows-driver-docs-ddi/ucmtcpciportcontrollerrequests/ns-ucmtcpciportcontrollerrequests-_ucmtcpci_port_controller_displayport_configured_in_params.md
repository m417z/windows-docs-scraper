# _UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_CONFIGURED_IN_PARAMS structure

## Description

Stores information about the pin assignment of the DisplayPort alternate mode that was configured. This structure is used in the
[IOCTL_UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_CONFIGURED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_displayport_configured) request.

## Members

### `PortControllerObject`

Handle to the port controller object that the client driver received in the previous call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate).

### `PinAssignment`

A [UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_PIN_ASSIGNMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ne-ucmtcpciportcontrollerrequests-_ucmtcpci_port_controller_displayport_pin_assignment)-type value that indicates the pin that was configured.

## See also

[IOCTL_UCMTCPCI_PORT_CONTROLLER_DISPLAYPORT_CONFIGURED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_displayport_configured)