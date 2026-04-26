## Description

Contains CPU-buffer dirty rectangle information for the dirty regions feature.

## Members

### `FullFrameIdentical`

Indicates the current frame is a repeat frame from the frame referenced by SourceDPBFrameReference. When TRUE, pDirtyRects must be NULL.

### `MapValuesType`

A [D3D12_VIDEO_ENCODER_DIRTY_REGIONS_MAP_VALUES_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_dirty_regions_map_values_mode) indicating the semantic of the values of pDirtyRects.

### `NumDirtyRects`

Number of elements in pDirtyRects.

### `pDirtyRects`

Pointer to an array of RECT structures. Each rect indicates pixels at those positions are different or identical to pixels in the same positions of the previous frame referenced by SourceDPBFrameReference.

### `SourceDPBFrameReference`

An index into the picture parameters DPB descriptor indicating which previous reference frame this dirty region refers to.

## Remarks

## See also