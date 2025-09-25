## Description

Describes the allocation size of a video motion estimator heap.

## Members

### `NodeIndex`

In multi-adapter operation, identifies the physical adapter of the device this operation applies to.

### `InputFormat`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) structure specifying the format of the input and reference resources.

### `BlockSize`

A value from the [D3D12_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_motion_estimator_search_block_size) specifying the search block size for motion estimation.

### `Precision`

A value from the [D3D12_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_motion_estimator_vector_precision) specifying the search block size for motion estimation.

### `SizeRange`

A [D3D12_VIDEO_SIZE_RANGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_size_range) structure representing the minimum and maximum input and reference frame size, in pixels, used by the motion estimator.

### `Protected`

TRUE if the motion estimator operates on protected resource input and produces protected output; otherwise, FALSE.

### `MotionVectorHeapMemoryPoolL0Size`

The allocation size of the motion vector heap in the L0 memory pool. L0 is the physical system memory pool. When the adapter is discrete/NUMA, this pool has greater bandwidth for the CPU and less bandwidth for the GPU. When the adapter is UMA, this pool is the only one which is valid. For more information, see [Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency).

### `MotionVectorHeapMemoryPoolL1Size`

The allocation size of the motion vector heap in the L1 memory pool. L1 is typically known as the physical video memory pool. L1 is only available when the adapter is discrete/NUMA, and has greater bandwidth for the GPU and cannot even be accessed by the CPU. When the adapter is UMA, this pool is not available. For more information, see [Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency).

### `MotionEstimatorMemoryPoolL0Size`

The allocation size of the motion estimator heap in the L0 memory pool. L0 is the physical system memory pool. When the adapter is discrete/NUMA, this pool has greater bandwidth for the CPU and less bandwidth for the GPU. When the adapter is UMA, this pool is the only one which is valid. For more information, see [Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency).

### `MotionEstimatorMemoryPoolL1Size`

The allocation size of the motion estimator heap in the L1 memory pool. L1 is typically known as the physical video memory pool. L1 is only available when the adapter is discrete/NUMA, and has greater bandwidth for the GPU and cannot even be accessed by the CPU. When the adapter is UMA, this pool is not available. For more information, see [Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency).

## Remarks

## See also