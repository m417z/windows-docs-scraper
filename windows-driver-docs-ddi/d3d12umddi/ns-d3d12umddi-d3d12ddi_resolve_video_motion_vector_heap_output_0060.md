# D3D12DDI_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_OUTPUT_0060 structure

## Description

Describes the output of the resolve operation.

## Members

### `hDrvMotionVectorTexture2D`

The output resource for resolved motion vectors. Motion vectors are resolved to a DXGI_FORMAT_R16G16_SINT 2D texture. The resolved data is expected to be a signed 16-byte integer with quarter pel unit,s with the X vector component stored in the R component and the Y vector component stored in the G component. Motion vectors are stored in a 2D layout that corresponds to the pixel layout of the original input textures.

### `MotionVectorCoordinate`

Specifies the output origin of the motion vectors. The remaining sub-region must be large enough to store all motion vectors per block specified by the input PixelWidth/PixelHeight and the [D3D12DDI_VIDEO_MOTION_ESTIMATOR_SEARCH_BLOCK_SIZE_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_motion_estimator_search_block_size_0053).

## Remarks

## See also