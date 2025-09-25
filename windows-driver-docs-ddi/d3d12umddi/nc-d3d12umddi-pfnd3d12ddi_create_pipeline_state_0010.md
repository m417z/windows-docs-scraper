# PFND3D12DDI_CREATE_PIPELINE_STATE_0010 callback function

## Description

The pfnCreatePipelineState callback function creates a pipeline state.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A value used to create a pipeline state.

### `unnamedParam3`

The handle of the pipeline state for the driver to use when it calls back into the runtime.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_PIPELINE_STATE_0010 Pfnd3d12ddiCreatePipelineState0010;

// Definition

HRESULT Pfnd3d12ddiCreatePipelineState0010
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_PIPELINE_STATE_0010 *
	 D3D12DDI_HPIPELINESTATE
)
{...}

PFND3D12DDI_CREATE_PIPELINE_STATE_0010

```