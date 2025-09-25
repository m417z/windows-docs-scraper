# PFND3D12DDI_CREATEVIDEOMOTIONVECTORHEAP_0053 callback function

## Description

Creates a video motion vector heap.

## Parameters

### `hDrvDevice`

A handle to the display device (graphics context) that the Direct3D runtime uses.

### `pArgs`

Pointer to a [D3D12DDIARG_CREATE_VIDEO_MOTION_VECTOR_HEAP_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_motion_vector_heap_0053) structure.

### `hDrvMotionEstimator`

A handle to the user mode driver motion vector heap type.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATEVIDEOMOTIONVECTORHEAP_0053 Pfnd3d12ddiCreatevideomotionvectorheap0053;

// Definition

HRESULT Pfnd3d12ddiCreatevideomotionvectorheap0053
(
	D3D12DDI_HDEVICE hDrvDevice
	CONST D3D12DDIARG_CREATE_VIDEO_MOTION_VECTOR_HEAP_0053 *pArgs
	D3D12DDI_HVIDEOMOTIONVECTORHEAP_0053 hDrvMotionEstimator
)
{...}

```

## Remarks

At the API, the Motion Vector Heap object is created to store motion vector output. Motion vector output is opaque at the API.

At the DDI, the runtime will create a standard Resource Buffer. This buffer contains hardware dependent layout. A resolve operation on a compute/3D queue will take this buffer as input and resolve it to the API specified format. The size of this buffer is driver controlled and determined by **D3D12DDICAPS_TYPE_VIDEO_0053_MOTION_ESTIMATOR_SIZE** capability check of the [D3D12DDICAPS_TYPE_VIDEO_0020](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020) enumeration. The buffer may later be used to serialize and deserialize the object for tooling scenarios.

## See also