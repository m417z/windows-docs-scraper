# D3D12DDI_VIDEO_MOTION_ESTIMATOR_DATA_0060 structure

## Description

The video capability check for motion estimation.

## Members

### `NodeIndex`

In multi-adapter operation, this value indicates which physical adapter of the device this operation applies to.

### `InputFormat`

The DXGI_FORMAT of the input frame and reference frame. Currently only DXGI_FORMAT_NV12 is allowed.

### `BlockSizeFlags`

The block sizes supported by driver. At least one bit must be set to support the motion estimation operation. Set this value to NONE if not supported. See [D3D12DDI_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE_FLAGS_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_motion_estimator_search_block_size_flags_0053).

### `PrecisionFlags`

The precision supported by driver. At least one bit must be set to support the motion estimation operation. Set this value to NONE if not supported. See [D3D12DDI_VIDEO_MOTION_ESTIMATOR_VECTOR_PRECISION_FLAGS_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_motion_estimator_vector_precision_flags_0053).

### `SizeRange`

Sets the minimum and maximum input and reference size in Pixels supported by driver. Set this value to zeros when motion estimation is not supported.

## Remarks

## See also