# D3D12_META_COMMAND_PARAMETER_DESC structure

## Description

Describes a parameter to a meta command.

## Members

### `Name`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The parameter name.

### `Type`

Type: **[D3D12_META_COMMAND_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_meta_command_parameter_type)**

A [D3D12_META_COMMAND_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_meta_command_parameter_type) specifying the parameter type.

### `Flags`

Type: **[D3D12_META_COMMAND_PARAMETER_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_meta_command_parameter_flags)**

A [D3D12_META_COMMAND_PARAMETER_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_meta_command_parameter_flags) specifying the parameter flags.

### `RequiredResourceState`

Type: **[D3D12_RESOURCE_STATES](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states)**

A [D3D12_RESOURCE_STATES](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states) specifying the expected state of a resource parameter.

### `StructureOffset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The 4-byte aligned offset for this parameter, within the structure containing the parameter values, which you pass when creating/initializing/executing the meta command, as appropriate.