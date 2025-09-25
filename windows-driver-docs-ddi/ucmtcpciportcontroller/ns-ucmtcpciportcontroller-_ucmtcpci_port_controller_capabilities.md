# _UCMTCPCI_PORT_CONTROLLER_CAPABILITIES structure

## Description

Contains information about the capabilities of the port controller.
This client driver must specify that information in the call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate) during initialization.
Call [UCMTCPCI_PORT_CONTROLLER_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpci_port_controller_capabilities_init) to initialize this structure.

## Members

### `Size`

 The size of this structure.

### `IsPowerDeliveryCapable`

 Indicates whether the port controller supports [USB Power Delivery](https://go.microsoft.com/fwlink/p/?LinkID=623310).

### `DeviceCapabilities1`

 A
**UCMTCPCI_PORT_CONTROLLER_DEVICE_CAPABILITIES_1** structure that describes the DEVICE_CAPABILITIES_1 Register as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.

### `DeviceCapabilities2`

 A
**UCMTCPCI_PORT_CONTROLLER_DEVICE_CAPABILITIES_2** structure that describes the DEVICE_CAPABILITIES_2 Register as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.

### `StandardInputCapabilities`

 A
**UCMTCPCI_PORT_CONTROLLER_STANDARD_INPUT_CAPABILITIES** structure that describes the STANDARD_INPUT_CAPABILITIES Register as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.

### `StandardOutputCapabilities`

 A
**UCMTCPCI_PORT_CONTROLLER_STANDARD_OUTPUT_CAPABILITIES** structure that describes the STANDARD_OUTPUT_CAPABILITIES Register as per the Universal Serial Bus Type-C Port Controller Interface Specification. This structure is declared in UcmTcpciSpec.h.

## See also

[UCMTCPCI_PORT_CONTROLLER_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpci_port_controller_capabilities_init)

[UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate)