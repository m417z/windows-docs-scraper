# PFND3D12DDI_ADD_PIPELINE_STATE_TO_LIBRARY_0010 callback function

## Description

Adds the input pipeline state to the corresponding library.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hLibrary`

The user mode driver handle type library.

### `hPipelineState`

A handle to the state of the pipeline.

### `PipelineIndex`

The pipeline index.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_ADD_PIPELINE_STATE_TO_LIBRARY_0010 Pfnd3d12ddiAddPipelineStateToLibrary0010;

// Definition

HRESULT Pfnd3d12ddiAddPipelineStateToLibrary0010
(
	D3D12DDI_HDEVICE hDevice
	D3D12DDI_HPIPELINELIBRARY hLibrary
	D3D12DDI_HPIPELINESTATE hPipelineState
	UINT PipelineIndex
)
{...}

PFND3D12DDI_ADD_PIPELINE_STATE_TO_LIBRARY_0010

```

## Remarks

## See also