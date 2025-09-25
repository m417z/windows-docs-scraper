# UCX_CONTROLLER_CONFIG_SET_ACPI_INFO function

## Description

Initializes a [UCX_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ns-ucxcontroller-_ucx_controller_config) structure with the specified values for the controller with ACPI as the parent.

## Parameters

### `Config`

A pointer to a [UCX_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ns-ucxcontroller-_ucx_controller_config) structure to initialize.

### `VendorId`

A string that contains the vendor identifier for the device.

### `DeviceId`

A string that specifies the device identifier assigned by the manufacturer.

### `RevisionId`

A string that Specifies the revision level of the device described by the **DeviceID** member.

## See also

[UCX_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/ns-ucxcontroller-_ucx_controller_config)

[UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85))