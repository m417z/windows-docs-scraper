# _UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_BUFFER_IN_PARAMS structure

## Description

 Stores the value of the TRANSMIT_BUFFER Register. This structure is used in the [IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_set_transmit_buffer) request.

## Members

### `PortControllerObject`

Handle to the port controller object that the client driver received in the previous call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate).

### `TransmitBuffer`

A pointer to the
**UCMTCPCI_PORT_CONTROLLER_TRANSMIT_BUFFER** structure that contains
the value to set in the TRANSMIT_BUFFER Register defined as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.

## See also

[IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_TRANSMIT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_set_transmit_buffer)