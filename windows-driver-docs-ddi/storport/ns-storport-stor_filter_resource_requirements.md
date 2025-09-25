## Description

**STOR_FILTER_RESOURCE_REQUIREMENTS** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine is called with a **ControlType** of **ScsiAdapterFilterResourceRequirements**.

## Members

### `Version`

The version of the filter. This is currently set to STOR_FILTER_RESOURCE_REQUIREMENTS_V1.

### `Size`

The size of this structure, in bytes. Set to ```sizeof(STOR_FILTER_RESOURCE_REQUIREMENTS)```.

### `IoResourceRequirementsList`

Pointer to an [**IO_RESOURCE_REQUIREMENTS_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_requirements_list) structure that describes the set of resource configurations that can be used by a device.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)