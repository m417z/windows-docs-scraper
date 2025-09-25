# D3DWDDM2_0DDI_VIDEO_PROCESSOR_BEHAVIOR_HINTS enumeration

## Description

Describes operations that the video processor can perform more efficiently than [VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt).

## Constants

### `D3DWDDM2_0DDI_VIDEO_PROCESSOR_BEHAVIOR_HINT_MULTIPLANE_OVERLAY_ROTATION`

Indicates that multi-plane overlay hardware can perform the rotation operation more efficiently than [VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt).

### `D3DWDDM2_0DDI_VIDEO_PROCESSOR_BEHAVIOR_HINT_MULTIPLANE_OVERLAY_RESIZE`

Indicates that the multi-plane overlay hardware can perform the scaling operation more efficiently than [VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt).

### `D3DWDDM2_0DDI_VIDEO_PROCESSOR_BEHAVIOR_HINT_MULTIPLANE_OVERLAY_COLOR_SPACE_CONVERSION`

Indicates that the multi-plane overlay hardware can perform the color space conversion operation more efficiently than [VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt).

## See also

[VideoProcessorBlt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt)