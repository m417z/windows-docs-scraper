# _UCMTCPCI_PORT_CONTROLLER_GET_STATUS_OUT_PARAMS structure

## Description

 Stores the values of all status registers of the port controller. This structure is used in the
[IOCTL_UCMTCPCI_PORT_CONTROLLER_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_get_status) request.

## Members

### `CCStatus`

 A
**UCMTCPCI_PORT_CONTROLLER_CC_STATUS** structure that describes the CC_STATUS Register defined as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.

### `PowerStatus`

 A
**UCMTCPCI_PORT_CONTROLLER_POWER_STATUS** structure that describes the POWER_STATUS Register defined as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.

### `FaultStatus`

 A
**UCMTCPCI_PORT_CONTROLLER_FAULT_STATUS** structure that describes the FAULT_STATUS Register defined as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.

## See also

[IOCTL_UCMTCPCI_PORT_CONTROLLER_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontrollerrequests/ni-ucmtcpciportcontrollerrequests-ioctl_ucmtcpci_port_controller_get_status)