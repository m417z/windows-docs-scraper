# _UCMTCPCI_PORT_CONTROLLER_IDENTIFICATION structure

## Description

Contains identification information and USB specification version information (in BCD format) about the port controller.
This client driver must specify that information in the call to [UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate) during initialization.
Call [UCMTCPCI_PORT_CONTROLLER_IDENTIFICATION_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpci_port_controller_identification_init) to initialize this structure.

## Members

### `Size`

Size of this structure.

### `VendorId`

Specifies the vendor identifier assigned by the USB specification committee.

### `ProductId`

 Specifies the product identifier. This value is assigned by the manufacturer.

### `DeviceId`

 The device ID for the USB Type-C port controller.

### `TypeCRevisionInBcd`

 The revision ID for the USB Type-C port controller.

### `PDRevisionAndVersionInBcd`

The revision and version for the USB Type-C port controller that supports PD.

### `PDInterfaceRevisionAndVersionInBcd`

The interface revision and version for the USB Type-C port controller that supports PD.

## See also

[UcmTcpciPortControllerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/nf-ucmtcpciportcontroller-ucmtcpciportcontrollercreate)