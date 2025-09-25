# PFND3D12DDI_CALC_PRIVATE_PIPELINE_STATE_SIZE_0010 callback function

## Description

Used to calculate the pipeline state size.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Used to create a pipeline state.

## Return value

The size in bytes of the state size.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALC_PRIVATE_PIPELINE_STATE_SIZE_0010 Pfnd3d12ddiCalcPrivatePipelineStateSize0010;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivatePipelineStateSize0010
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_PIPELINE_STATE_0010 *
)
{...}

PFND3D12DDI_CALC_PRIVATE_PIPELINE_STATE_SIZE_0010

```