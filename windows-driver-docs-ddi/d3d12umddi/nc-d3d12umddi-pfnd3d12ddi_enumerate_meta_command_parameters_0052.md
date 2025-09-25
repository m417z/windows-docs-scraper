# PFND3D12DDI_ENUMERATE_META_COMMAND_PARAMETERS_0052 callback function

## Description

Enumerates meta-command parameters.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `CommandId`

The command id.

### `Stage`

A [D3D12DDI_META_COMMAND_PARAMETER_STAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_meta_command_parameter_stage).

### `pParameterCount`

The number of meta-command parameters.

### `pParameterDescs`

Pointer to an meta-command descriptions.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_ENUMERATE_META_COMMAND_PARAMETERS_0052 Pfnd3d12ddiEnumerateMetaCommandParameters0052;

// Definition

HRESULT Pfnd3d12ddiEnumerateMetaCommandParameters0052
(
	D3D12DDI_HDEVICE Arg1
	GUID CommandId
	D3D12DDI_META_COMMAND_PARAMETER_STAGE Stage
	UINT *pParameterCount
	D3D12DDIARG_META_COMMAND_PARAMETER_DESC *pParameterDescs
)
{...}

```

## Remarks

## See also