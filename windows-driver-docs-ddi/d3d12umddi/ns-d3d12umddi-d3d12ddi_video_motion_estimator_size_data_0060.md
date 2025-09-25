# D3D12DDI_VIDEO_MOTION_ESTIMATOR_SIZE_DATA_0060 structure

## Description

This capability determines the residency size for the motion estimator and the hardware dependent output buffer when called with the same creation parameters.

## Members

### `NodeMask`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `InputFormat`

The DXGI_FORMAT of the input frame and reference frame. Currently, only DXGI_FORMAT_NV12 is allowed.

### `BlockSize`

The block size to use with the motion estimator. See [D3D12DDI_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_motion_estimator_search_block_size_0053).

### `Precision`

The precision to use with the motion estimator. See [D3D12DDI_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_motion_estimator_vector_precision_0053).

### `SizeRange`

The size range allowed with the Motion Estimator. This may be a subset of the size range supported by the driver to optimize memory usage. See [D3D12DDI_VIDEO_SIZE_RANGE_0032](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_size_range_0032).

### `Protected`

TRUE if the motion estimator operates on protected resource input and produces protected output. The driver must also support protected resources for D3D12 to set TRUE. FALSE otherwise.

### `MotionEstimatorMemoryPoolL0Size`

Output memory pool size.

### `MotionEstimatorMemoryPoolL1Size`

Output memory pool size.

### `MotionVectorHeapMemoryPoolL0Size`

Output memory pool size.

### `MotionVectorHeapMemoryPoolL1Size`

Output memory pool size.

## Remarks

## See also