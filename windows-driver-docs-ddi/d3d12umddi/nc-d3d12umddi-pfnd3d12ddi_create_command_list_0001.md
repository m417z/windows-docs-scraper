# PFND3D12DDI_CREATE_COMMAND_LIST_0001 callback function

## Description

Creates a command list.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_COMMAND_LIST_0001 structure.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_COMMAND_LIST_0001 Pfnd3d12ddiCreateCommandList0001;

// Definition

HRESULT Pfnd3d12ddiCreateCommandList0001
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_COMMAND_LIST_0001 *
)
{...}

PFND3D12DDI_CREATE_COMMAND_LIST_0001

```