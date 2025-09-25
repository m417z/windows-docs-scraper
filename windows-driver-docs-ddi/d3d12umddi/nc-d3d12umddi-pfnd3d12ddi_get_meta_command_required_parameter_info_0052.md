# PFND3D12DDI_GET_META_COMMAND_REQUIRED_PARAMETER_INFO_0052 callback function

## Description

**PFND3D12DDI_GET_META_COMMAND_REQUIRED_PARAMETER_INFO_0052** gets required information for a meta-command.

## Parameters

### `unnamedParam1`

A handle to a meta-command.

### `Stage`

A pointer to a [**D3D12DDI_META_COMMAND_PARAMETER_STAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_meta_command_parameter_stage).

### `ParameterIndex`

The index of the parameter.

### `unnamedParam4`

A pointer to a [**D3D12DDIARG_META_COMMAND_REQUIRED_PARAMETER_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_meta_command_required_parameter_info) structure in which the meta-command's required parameter info is written.

## See also

[D3D12DDI_META_COMMAND_PARAMETER_STAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_meta_command_parameter_stage)

[D3D12DDIARG_META_COMMAND_REQUIRED_PARAMETER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_meta_command_required_parameter_info)