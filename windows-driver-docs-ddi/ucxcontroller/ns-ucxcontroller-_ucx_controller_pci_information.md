# _UCX_CONTROLLER_PCI_INFORMATION structure

## Description

This structure provides information about a PCI USB controller.

## Members

### `VendorId`

The vendor ID for the PCI USB controller.

### `DeviceId`

The device ID for the PCI USB controller.

### `RevisionId`

The revision ID for the PCI USB controller.

### `BusNumber`

Specifies the bus number that identifies the bus instance that a device instance is attached to.

### `DeviceNumber`

Specifies the device number that is assigned to the logical PCI slot.

### `FunctionNumber`

Specifies the specific function on the device that is located in the logical PCI slot.

## See also

[UCX_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ns-ucxcontroller-_ucx_controller_config)

[UCX_CONTROLLER_CONFIG_SET_PCI_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucx_controller_config_set_pci_info)

[UCX_CONTROLLER_PARENT_BUS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ne-ucxcontroller-_ucx_controller_parent_bus_type)