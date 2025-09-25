# PFND3D12DDI_ENUMERATE_META_COMMANDS_0052 callback function

## Description

The **PFND3D12DDI_ENUMERATE_META_COMMANDS_0052** callback function enumerates meta-commands.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `pNumMetaCommands`

Pointer to a value in which the number of enumerated meta-commands is written.

### `pDescs`

Pointer to an array of [**D3D12DDIARG_META_COMMAND_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_meta_command_desc) structures containing the meta-command descriptions.

## Return value

Returns HRESULT.

## See also

[**PFND3D12DDI_CREATE_META_COMMAND_0052**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_meta_command_0052)