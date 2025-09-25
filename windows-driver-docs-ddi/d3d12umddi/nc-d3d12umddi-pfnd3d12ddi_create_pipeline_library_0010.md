# PFND3D12DDI_CREATE_PIPELINE_LIBRARY_0010 callback function

## Description

Create a pipeline library.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_PIPELINE_LIBRARY_0010 structure.

### `unnamedParam3`

A handle to a pipeline library.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_PIPELINE_LIBRARY_0010 Pfnd3d12ddiCreatePipelineLibrary0010;

// Definition

HRESULT Pfnd3d12ddiCreatePipelineLibrary0010
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_PIPELINE_LIBRARY_0010 *
	 D3D12DDI_HPIPELINELIBRARY
)
{...}

PFND3D12DDI_CREATE_PIPELINE_LIBRARY_0010

```