## Description

Contains the input map data along with the input type indicator for [ID3D12VideoEncodeCommandList4::ResolveInputParamLayout](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-resolveinputparamlayout). Contains a union that is selected based on the MapType field.

## Members

### `MapType`

A [D3D12_VIDEO_ENCODER_INPUT_MAP_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_input_map_type) specifying the type of input map.

### `Quantization`

A [D3D12_VIDEO_ENCODER_INPUT_MAP_DATA_QUANTIZATION_MATRIX](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_input_map_data_quantization_matrix) used when MapType is D3D12_VIDEO_ENCODER_INPUT_MAP_TYPE_QUANTIZATION_MATRIX.

### `DirtyRegions`

A [D3D12_VIDEO_ENCODER_INPUT_MAP_DATA_DIRTY_REGIONS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_input_map_data_dirty_regions) used when MapType is D3D12_VIDEO_ENCODER_INPUT_MAP_TYPE_DIRTY_REGIONS.

### `MotionVectors`

A [D3D12_VIDEO_ENCODER_INPUT_MAP_DATA_MOTION_VECTORS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_input_map_data_motion_vectors) used when MapType is D3D12_VIDEO_ENCODER_INPUT_MAP_TYPE_MOTION_VECTORS.

## Remarks

## See also