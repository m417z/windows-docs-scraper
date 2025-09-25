# _UCMTCPCI_PORT_CONTROLLER_SET_CONTROL_IN_PARAMS structure

## Description

 Stores the values of all control registers. This structure is used in the [IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_set_control) request.

## Members

### `PortControllerObject`

Handle to the port controller object that the client driver received in the previous call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate).

### `ControlType`

 A **UCMTCPCI_PORT_CONTROLLER_CONTROL_TYPE**-value that
indicates the type of control register. This enumeration is declared in UcmTcpciSpec.h.

### `TCPCControl`

 A
**UCMTCPCI_PORT_CONTROLLER_TCPC_CONTROL** structure that describes the TCPC_CONTROL Register defined as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.

### `RoleControl`

 A
**UCMTCPCI_PORT_CONTROLLER_ROLE_CONTROL** structure that describes the ROLE_CONTROL Register defined as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.

### `FaultControl`

 A
**UCMTCPCI_PORT_CONTROLLER_FAULT_CONTROL** structure that describes the FAULT_CONTROL Register defined as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.

### `PowerControl`

 A
**UCMTCPCI_PORT_CONTROLLER_POWER_CONTROL** structure that describes the FAULT_POWER Register defined as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.

## See also

[IOCTL_UCMTCPCI_PORT_CONTROLLER_SET_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_set_control)