# PFND3D12DDI_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_0060 callback function

## Description

Takes a standard resource buffer as input and resolves it to the API specified format.

## Parameters

### `hDrvCommandList`

A handle to the driver command list.

### `pOutputArguments`

Pointer to a [D3D12DDI_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_OUTPUT_0060](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_resolve_video_motion_vector_heap_output_0060) structure containing output arguments.

### `pInputArguments`

Pointer to a [D3D12DDI_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_INPUT_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_resolve_video_motion_vector_heap_input_0053) structure containing input arguments.

## Prototype

```
//Declaration

PFND3D12DDI_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_0060 Pfnd3d12ddiResolveVideoMotionVectorHeap0060;

// Definition

VOID Pfnd3d12ddiResolveVideoMotionVectorHeap0060
(
	D3D12DDI_HCOMMANDLIST hDrvCommandList
	 const D3D12DDI_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_OUTPUT_0060 *pOutputArguments
	 const D3D12DDI_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_INPUT_0053 *pInputArguments
)
{...}

```

## Remarks

The resolve operation is expected to be a light-weight translation of hardware dependent output to the API specified format.

## See also