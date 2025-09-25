# PFND3D12DDI_ESTIMATE_MOTION_0053 callback function

## Description

Performs the motion estimation operation.

## Parameters

### `hDrvCommandList`

Driver handle for a video encode command list.

### `hDrvMotionEstimator`

Handle to the motion estimator context object.

### `pOutputArguments`

Pointer to a [D3D12DDI_VIDEO_MOTION_ESTIMATOR_OUTPUT_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_motion_estimator_output_0053) structure that contains the output arguments for the motion estimation operation.

### `pInputArguments`

Pointer to a [D3D12DDI_VIDEO_MOTION_ESTIMATOR_INPUT_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_motion_estimator_input_0053) structure that contains the input arguments for the motion estimation operation.

## Prototype

```cpp
//Declaration

PFND3D12DDI_ESTIMATE_MOTION_0053 Pfnd3d12ddiEstimateMotion0053;

// Definition

VOID Pfnd3d12ddiEstimateMotion0053
(
	D3D12DDI_HCOMMANDLIST hDrvCommandList
	D3D12DDI_HVIDEOMOTIONESTIMATOR_0053 hDrvMotionEstimator
	CONST D3D12DDI_VIDEO_MOTION_ESTIMATOR_OUTPUT_0053 *pOutputArguments
	CONST D3D12DDI_VIDEO_MOTION_ESTIMATOR_INPUT_0053 *pInputArguments
)
{...}

```

## Remarks

The motion estimation operation has a context object to associate the lifetime of internal allocations needed to perform the operation. All allocations associated with his object should be allocated when the object is created and deallocated when the object is de-allocated. This should include any buffers used as temporary/scratch storage.

Operations against this object may be recorded to command lists in a different order than execution. No two API queue instances may be executing command lists containing this object at the same time and expect valid results. The application is responsible for synchronizing access across multiple queue instances.

This object must support [PFND3D12DDI_MAKERESIDENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_makeresident_cb), [PFND3D12DDI_EVICT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_evict_cb), and [PFND3D12DDI_GET_DEBUG_ALLOCATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_get_debug_allocation_info_0012).

## See also