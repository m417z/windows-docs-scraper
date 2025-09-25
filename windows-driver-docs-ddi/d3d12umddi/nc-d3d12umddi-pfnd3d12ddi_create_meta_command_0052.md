# PFND3D12DDI_CREATE_META_COMMAND_0052 callback function

## Description

Creates a meta-command.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `CommandId`

The command id.

### `NodeMask`

The node mask of the command list.

### `pCreationParameters`

The creation parameters.

### `CreationParametersDataSizeInBytes`

The size of the creation parameters.

### `unnamedParam6`

Handle to a meta-command.

### `unnamedParam7`

A meta-command.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_META_COMMAND_0052 Pfnd3d12ddiCreateMetaCommand0052;

// Definition

HRESULT Pfnd3d12ddiCreateMetaCommand0052
(
	D3D12DDI_HDEVICE Arg1
	GUID CommandId
	UINT NodeMask
	CONST void *pCreationParameters
	SIZE_T CreationParametersDataSizeInBytes
	D3D12DDI_HMETACOMMAND_0052 Arg2
	D3D12DDI_HRTMETACOMMAND_0052 Arg3
)
{...}

```

## Remarks

The runtime will validate the meta-command guid via an approved list. This check can only be bypassed in developer mode. Without this only predefined meta-commands are allowed. All predefined meta-commands have a defined spec and HLK tests to validate their functionality.

## See also

[**PFND3D12DDI_DESTROY_META_COMMAND_0052**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_destroy_meta_command_0052)

[**PFND3D12DDI_EXECUTE_META_COMMAND_0052**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_execute_meta_command_0052)

[**PFND3D12DDI_INITIALIZE_META_COMMAND_0052**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_initialize_meta_command_0052)