# _UCMTCPCI_PORT_CONTROLLER_GET_CONTROL_OUT_PARAMS structure

## Description

 Stores the values of all control registers of the port controller retrieved by the
[IOCTL_UCMTCPCI_PORT_CONTROLLER_GET_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_get_control) request.

## Members

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

[IOCTL_UCMTCPCI_PORT_CONTROLLER_GET_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_get_control)