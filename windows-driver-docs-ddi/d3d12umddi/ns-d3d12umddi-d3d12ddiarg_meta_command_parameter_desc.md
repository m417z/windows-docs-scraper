# D3D12DDIARG_META_COMMAND_PARAMETER_DESC structure

## Description

**D3D12DDIARG_META_COMMAND_PARAMETER_DESC** contains the meta-command parameter descriptions.

## Members

### `Name`

The name of the meta-command parameter.

### `Type`

A [**D3D12DDI_META_COMMAND_PARAMETER_TYPE**] value that indicates the type of meta-command parameter.

### `Flags`

A [**D3D12DDI_META_COMMAND_PARAMETER_FLAGS**] value that indicate whether the resource is used for input or output.

### `RequiredResourceState`

A [**D3D12DDI_RESOURCE_STATES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_states) value that indicates the expected state of the resource. This is specified for each resource in the meta-command definition.

## Remarks

The debug layer validates the type and state to ensure the parameters supplied during creation are set up correctly.

The driver reports the list of parameters and their type and the runtime calculates a 4-byte aligned offset in a structure that the user developer passes these parameters in.

## See also

[**PFND3D12DDI_ENUMERATE_META_COMMAND_PARAMETERS_0052**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_enumerate_meta_command_parameters_0052)