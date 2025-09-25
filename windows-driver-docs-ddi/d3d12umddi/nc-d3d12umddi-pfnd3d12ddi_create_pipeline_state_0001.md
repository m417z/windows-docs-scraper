# PFND3D12DDI_CREATE_PIPELINE_STATE_0001 callback function

## Description

The pfnCreatePipelineState callback function creates a pipeline state.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A value used to create a pipeline state.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_PIPELINE_STATE_0001 Pfnd3d12ddiCreatePipelineState0001;

// Definition

HRESULT Pfnd3d12ddiCreatePipelineState0001
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_PIPELINE_STATE_0001 *
)
{...}

PFND3D12DDI_CREATE_PIPELINE_STATE_0001

```