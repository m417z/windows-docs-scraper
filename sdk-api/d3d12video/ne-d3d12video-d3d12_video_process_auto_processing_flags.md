# D3D12_VIDEO_PROCESS_AUTO_PROCESSING_FLAGS enumeration

## Description

Specifies the automatic processing features that a video processor can support.

## Constants

### `D3D12_VIDEO_PROCESS_AUTO_PROCESSING_FLAG_NONE`

No automatic processing features are supported.

### `D3D12_VIDEO_PROCESS_AUTO_PROCESSING_FLAG_DENOISE`

Denoise is supported.

### `D3D12_VIDEO_PROCESS_AUTO_PROCESSING_FLAG_DERINGING`

Deringing is supported.

### `D3D12_VIDEO_PROCESS_AUTO_PROCESSING_FLAG_EDGE_ENHANCEMENT`

Edge enhancement is supported.

### `D3D12_VIDEO_PROCESS_AUTO_PROCESSING_FLAG_COLOR_CORRECTION`

Color correction is supported.

### `D3D12_VIDEO_PROCESS_AUTO_PROCESSING_FLAG_FLESH_TONE_MAPPING`

Flesh tone mapping is supported.

### `D3D12_VIDEO_PROCESS_AUTO_PROCESSING_FLAG_IMAGE_STABILIZATION`

Image stabilization is supported.

### `D3D12_VIDEO_PROCESS_AUTO_PROCESSING_FLAG_SUPER_RESOLUTION`

Enhanced image resolution is supported.

### `D3D12_VIDEO_PROCESS_AUTO_PROCESSING_FLAG_ANAMORPHIC_SCALING`

Anamorphic scaling is supported.

### `D3D12_VIDEO_PROCESS_AUTO_PROCESSING_FLAG_CUSTOM`

Additional processing features, not described by the other flags, are available.

## Remarks

This enumeration is used by the [D3D12\_FEATURE\_DATA\_VIDEO\_PROCESS\_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_process_support) structure.

## See also