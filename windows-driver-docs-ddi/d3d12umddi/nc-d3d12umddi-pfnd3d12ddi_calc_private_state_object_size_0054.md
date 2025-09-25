# PFND3D12DDI_CALC_PRIVATE_STATE_OBJECT_SIZE_0054 callback function

## Description

Calculates the private state object size.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a [D3D12DDIARG_CREATE_STATE_OBJECT_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_state_object_0054) structure that contains the arguments for a state object.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALC_PRIVATE_STATE_OBJECT_SIZE_0054 Pfnd3d12ddiCalcPrivateStateObjectSize0054;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateStateObjectSize0054
(
	D3D12DDI_HDEVICE Arg1
	CONST D3D12DDIARG_CREATE_STATE_OBJECT_0054 *
)
{...}

```

## Remarks

## See also