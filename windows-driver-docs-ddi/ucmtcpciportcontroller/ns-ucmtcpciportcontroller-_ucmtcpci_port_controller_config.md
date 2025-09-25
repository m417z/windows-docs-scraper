# _UCMTCPCI_PORT_CONTROLLER_CONFIG structure

## Description

 Contains configuration options for the port controller object, passed by the client driver in the call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate). Call [UCMTCPCI_PORT_CONTROLLER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpci_port_controller_config_init) to initialize this structure.

## Members

### `Size`

 Size of this structure.

### `Identification`

A pointer to the [UCMTCPCI_PORT_CONTROLLER_IDENTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/ns-ucmtcpciportcontroller-_ucmtcpci_port_controller_identification) structure.

### `Capabilities`

 A pointer to the
[UCMTCPCI_PORT_CONTROLLER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/ns-ucmtcpciportcontroller-_ucmtcpci_port_controller_capabilities) structure.

## See also

[UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate)