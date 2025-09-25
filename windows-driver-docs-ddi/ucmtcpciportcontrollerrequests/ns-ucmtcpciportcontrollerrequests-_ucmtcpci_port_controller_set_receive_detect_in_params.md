# _UCMTCPCI_PORT_CONTROLLER_SET_RECEIVE_DETECT_IN_PARAMS structure

## Description

 Stores the value of the RECEIVE_DETECT Register. This structure is used in the [IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_RECEIVE_DETECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_set_receive_detect) request.

## Members

### `PortControllerObject`

Handle to the port controller object that the client driver received in the previous call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate).

### `ReceiveDetect`

 A
**UCMTCPCI_PORT_CONTROLLER_RECEIVE_DETECT** structure that describes the RECEIVE_DETECT Register defined as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.