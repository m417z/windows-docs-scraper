# PFND3D12DDI_SET_PIPELINE_STACK_SIZE_0054 callback function

## Description

SetPipelineStackSize sets the current pipeline stack size.

## Parameters

### `unnamedParam1`

A handle to the state object.

### `unnamedParam2`

Stack size in bytes to use during pipeline execution for each shader thread (of which there can be many thousands in flight on the GPU).

## Prototype

```cpp
//Declaration

PFND3D12DDI_SET_PIPELINE_STACK_SIZE_0054 Pfnd3d12ddiSetPipelineStackSize0054;

// Definition

void Pfnd3d12ddiSetPipelineStackSize0054
(
	D3D12DDI_HSTATEOBJECT_0054 Arg1
	UINT Arg2
)
{...}

```

## Remarks

SetPipelineStackSize and [GetPipelineStackSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_get_pipeline_stack_size_0054) or any use of ray tracing pipeline state objects, such as [DispatchRays](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_dispatch_rays_0054) are not re-entrant. This means that if calling any of these functions from separate threads, the app must synchronize on its own. Any given DispatchRays call or GetPipelineStackSize call uses or returns the most recent stack size setting.

The runtime drops calls to state objects other than ray tracing pipelines (such as collections).

## See also