# UCMTCPCI_PORT_CONTROLLER_CONFIG_INIT function

## Description

 Initializes the [UCMTCPCI_PORT_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/ns-ucmtcpciportcontroller-_ucmtcpci_port_controller_config) structure.

## Parameters

### `Config` [out]

A pointer to the driver-allocated [UCMTCPCI_PORT_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/ns-ucmtcpciportcontroller-_ucmtcpci_port_controller_config) structure.

### `Identification` [in]

A pointer to the [UCMTCPCI_PORT_CONTROLLER_IDENTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/ns-ucmtcpciportcontroller-_ucmtcpci_port_controller_identification) structure.

### `Capabilities` [in]

 A pointer to the
[UCMTCPCI_PORT_CONTROLLER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/ns-ucmtcpciportcontroller-_ucmtcpci_port_controller_capabilities) structure.

## See also

[UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate)