# _UCMTCPCI_PORT_CONTROLLER_ALERT_DATA structure

## Description

Contains information about hardware alerts received on the port controller object. This structure is used in the [UcmTcpciPortControllerAlert](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrolleralert) call. Call [UCMTCPCI_PORT_CONTROLLER_ALERT_DATA_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpci_port_controller_alert_data_init) to initialize this structure.

## Members

### `Size`

Size of this structure.

### `AlertType`

A [UCMTCPCI_PORT_CONTROLLER_ALERT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/ne-ucmtcpciportcontroller-_ucmtcpci_port_controller_alert_type) value that indicates the type of hardware alert.

### `CCStatus`

A **UCMTCPCI_PORT_CONTROLLER_CC_STATUS** structure that contains status information about the CC lines of the port controller. This structure is defined in UcmTcpciSpec.h.

### `PowerStatus`

A **UCMTCPCI_PORT_CONTROLLER_POWER_STATUS** structure that contains the power status of the port controller. This structure is defined in UcmTcpciSpec.h.

### `FaultStatus`

A **UCMTCPCI_PORT_CONTROLLER_FAULT_STATUS** structure that contains the fault status of the port controller. This structure is defined in UcmTcpciSpec.h.

### `ReceiveBuffer`

A pointer to a **UCMTCPCI_PORT_CONTROLLER_RECEIVE_BUFFER** structure that represents the buffer for receiving the alert from the port controller. This structure is defined in UcmTcpciSpec.h.

## See also

[UcmTcpciPortControllerAlert](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrolleralert)