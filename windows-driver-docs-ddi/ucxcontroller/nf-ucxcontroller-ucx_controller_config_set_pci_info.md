# UCX_CONTROLLER_CONFIG_SET_PCI_INFO function

## Description

Initializes a [UCX_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ns-ucxcontroller-_ucx_controller_config) structure with the specified values for the controller with PCI as the parent bus type.

## Parameters

### `Config` [in]

A pointer to a [UCX_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ns-ucxcontroller-_ucx_controller_config) structure to initialize.

### `VendorId` [in]

Specifies the vendor identifier for the device as assigned by the PCI SIG.

### `DeviceId` [in]

Specifies the device identifier assigned by the manufacturer.

### `RevisionId` [in]

Specifies the revision level of the device described by the **DeviceID** member.

### `BusNumber` [in]

Specifies the bus number that identifies the bus instance that a device instance is attached to.

### `DeviceNumber` [in]

Specifies the device number that is assigned to the logical PCI slot.

### `FunctionNumber` [in]

Specifies the specific function on the device that is located in the logical PCI slot.

## See also

[UCX_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ns-ucxcontroller-_ucx_controller_config)

[UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85))