## Description

Contains dirty regions input map data for the GPU texture input path of [ID3D12VideoEncodeCommandList4::ResolveInputParamLayout](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-resolveinputparamlayout).

## Members

### `FullFrameIdentical`

Indicates that the current frame is a repeat frame from the frame referenced by SourceDPBFrameReference. When TRUE, pDirtyRegionsMap must be NULL.

### `MapValuesType`

A [D3D12_VIDEO_ENCODER_DIRTY_REGIONS_MAP_VALUES_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_dirty_regions_map_values_mode) indicating the semantic of the values of pDirtyRegionsMap.

### `pDirtyRegionsMap`

Pointer to an ID3D12Resource texture with the same dimensions as the input frame and format DXGI_FORMAT_R8_UINT. Each (x, y) position indicates if the pixel at that position is different or identical to a pixel in the same position of the previous frame in the DPB used as reference.

### `SourceDPBFrameReference`

An index into the picture parameters DPB descriptor indicating which previous reference frame this dirty region refers to.

## Remarks

## See also