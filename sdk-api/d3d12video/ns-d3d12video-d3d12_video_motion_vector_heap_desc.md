## Description

Describes a [ID3D12VideoMotionEstimatorHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videomotionvectorheap). Pass this structure into [ID3D12VideoDevice1::CreateVideoMotionVectorHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice1-createvideomotionvectorheap) to create an instance of **ID3D12VideoMotionEstimatorHeap**.

## Members

### `NodeMask`

The node mask specifying the physical adapter on which the video processor will be used. For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node, i.e. the device's physical adapter, to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `InputFormat`

A value from the [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration specifying the format of the input and reference frames.

### `BlockSize`

A value from the [D3D12_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_motion_estimator_search_block_size) enumeration specifying the search block size the video motion estimator will use.

### `Precision`

A value from the [D3D12_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_motion_estimator_vector_precision) enumeration specifying the vector precision the video motion estimator will use.

### `SizeRange`

A [D3D12_VIDEO_SIZE_RANGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_size_range) structure representing the minimum and maximum input and reference frame size, in pixels, that the motion estimator will accept.

## Remarks

Call [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) and specify [D3D12_FEATURE_VIDEO_MOTION_ESTIMATOR](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video) as the feature to determine supported values.

## See also