# _UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_IN_PARAMS structure

## Description

Stores the values of TRANSMIT Register. This structure is used in the [IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_set_transmit) request.

## Members

### `PortControllerObject`

Handle to the port controller object that the client driver received in the previous call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate).

### `Transmit`

A pointer to the **UCMTCPCI_PORT_CONTROLLER_TRANSMIT** structure that contains the value to set in the TRANSMIT register defined as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.

## See also

[IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_set_transmit)