# PFND3D12DDI_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_0053 callback function

## Description

Takes a standard resource buffer as input and resolves it to the API specified format.

## Parameters

### `hDrvCommandList`

A handle to the driver command list.

### `pOutputArguments`

Pointer to a [D3D12DDI_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_OUTPUT_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_resolve_video_motion_vector_heap_output_0053) structure containing output arguments.

### `pInputArguments`

Pointer to a [D3D12DDI_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_INPUT_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_resolve_video_motion_vector_heap_input_0053) structure containing input arguments.

## Prototype

```cpp
//Declaration

PFND3D12DDI_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_0053 Pfnd3d12ddiResolveVideoMotionVectorHeap0053;

// Definition

VOID Pfnd3d12ddiResolveVideoMotionVectorHeap0053
(
	D3D12DDI_HCOMMANDLIST hDrvCommandList
	CONST D3D12DDI_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_OUTPUT_0053 *pOutputArguments
	CONST D3D12DDI_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_INPUT_0053 *pInputArguments
)
{...}

```

## Remarks

The resolve operation is expected to be a light-weight translation of hardware dependent output to the API specified format.

## See also