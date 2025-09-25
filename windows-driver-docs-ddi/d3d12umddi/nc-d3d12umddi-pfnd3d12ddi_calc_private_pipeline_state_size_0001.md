# PFND3D12DDI_CALC_PRIVATE_PIPELINE_STATE_SIZE_0001 callback function

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

PFND3D12DDI_CALC_PRIVATE_PIPELINE_STATE_SIZE_0001 Pfnd3d12ddiCalcPrivatePipelineStateSize0001;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivatePipelineStateSize0001
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_PIPELINE_STATE_0001 *
)
{...}

PFND3D12DDI_CALC_PRIVATE_PIPELINE_STATE_SIZE_0001

```