# _UCMTCPCI_PORT_CONTROLLER_SET_COMMAND_IN_PARAMS structure

## Description

 Stores the specified command registers. This structure is used in the [IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_set_command) request.

## Members

### `PortControllerObject`

Handle to the port controller object that the client driver received in the previous call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate).

### `Command`

A **UCMTCPCI_PORT_CONTROLLER_COMMAND**-value that
indicates the type of control register. This enumeration is declared in UcmTcpciSpec.h.

## See also

[IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_set_command)