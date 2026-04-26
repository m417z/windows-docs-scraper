## Description

Extends the existing resolution support limits to include per-resolution support for QPMap, dirty regions, and motion search features. Used as output per-resolution in [D3D12_FEATURE_DATA_VIDEO_ENCODER_SUPPORT2](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_support2).

## Members

### `MaxSubregionsNumber`

The maximum number of subregions per frame for the associated resolution.

### `MaxIntraRefreshFrameDuration`

The maximum number of frames for an intra-refresh cycle.

### `SubregionBlockPixelsSize`

The size in pixels of the subregion block.

### `QPMapRegionPixelsSize`

The size in pixels of the QPMap region block.

### `QPMap`

A [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_QPMAP](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resolution_support_qpmap) output parameter with QPMap support details.

### `DirtyRegions`

A [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_DIRTY_REGIONS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resolution_support_dirty_regions) output parameter. Only reported when dirty regions are enabled and supported. Zeroed memory otherwise.

### `MotionSearch`

A [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_MOTION_SEARCH](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resolution_support_motion_search) output parameter. Only reported when motion search is enabled and supported. Zeroed memory otherwise.

## Remarks

## See also