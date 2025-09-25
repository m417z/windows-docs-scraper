# D3D12DDI_VIDEO_PROCESS_FILTER_FLAGS_0020 enumeration

## Description

Defines the image filter capabilities for a video processor.

## Constants

### `D3D12DDI_VIDEO_PROCESS_FILTER_FLAG_0020_NONE`

No flag set.

### `D3D12DDI_VIDEO_PROCESS_FILTER_FLAG_0020_BRIGHTNESS`

The video processor can adjust the brightness level.

### `D3D12DDI_VIDEO_PROCESS_FILTER_FLAG_0020_CONTRAST`

The video processor can adjust the contrast level.

### `D3D12DDI_VIDEO_PROCESS_FILTER_FLAG_0020_HUE`

The video processor can adjust hue.

### `D3D12DDI_VIDEO_PROCESS_FILTER_FLAG_0020_SATURATION`

The video processor can adjust the saturation level.

### `D3D12DDI_VIDEO_PROCESS_FILTER_FLAG_0020_NOISE_REDUCTION`

The video processor can perform noise reduction.

### `D3D12DDI_VIDEO_PROCESS_FILTER_FLAG_0020_EDGE_ENHANCEMENT`

The video processor can perform edge enhancement.

### `D3D12DDI_VIDEO_PROCESS_FILTER_FLAG_0020_ANAMORPHIC_SCALING`

The video processor can perform anamorphic scaling. Anamorphic scaling can be used to stretch content with a 4:3 aspect ratio, to a widescreen 16:9 aspect ratio.

### `D3D12DDI_VIDEO_PROCESS_FILTER_FLAG_0020_STEREO_ADJUSTMENT`

For stereo 3D video, the video processor can adjust the offset between the left and right views. This allows the user to reduce potential eye strain.

## Remarks

Note that brightness, hue, contrast and saturation support are always supported. These capability flags indicate support for the image filters defined by the [D3D12DDI_VIDEO_PROCESS_FILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_filter_0020) enumeration. To apply a particular filter, call the [SetInputStreamFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamfilter) method.

## See also

[D3D12DDI_VIDEO_PROCESS_FILTER enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_filter_0020)