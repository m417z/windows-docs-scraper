# D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS enumeration

## Description

Defines features that a Microsoft Direct3D 11 video processor can support.

## Constants

### `D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_FILL:0x1`

The video processor can set alpha values on the output pixels. For more information, see [**VideoProcessorSetOutputAlphaFillMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputalphafillmode).

### `D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_CONSTRICTION:0x2`

The video processor can downsample the video output. For more information, see [**VideoProcessorSetOutputConstriction**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputconstriction).

### `D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_LUMA_KEY:0x4`

The video processor can perform luma keying. For more information, see [**VideoProcessorSetStreamLumaKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamlumakey).

### `D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_PALETTE:0x8`

The video processor can apply alpha values from color palette entries.

### `D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_LEGACY:0x10`

The driver does not support the DXVA-HDDDI. If this capability flag is set, the video processor has the following limitations:

* A maximum of two streams are supported:
  * The first stream must be either NV12 or YUY2.
  * The second stream must be AYUV, AI44, or IA44.
* Image adjustment (proc amp) controls are applied to the entire video processing blit, rather than per stream.
* Support for per-stream planar alpha is not reliable. (Per-pixel alpha is supported, however.)

### `D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_STEREO:0x20`

The video processor can support 3-D stereo video. For more information, see [**VideoProcessorSetStreamStereoFormat**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamstereoformat).

### `D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_ROTATION:0x40`

The video processor is capable of rotating the input stream by 90, 180, or 270 degrees (clockwise).

### `D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_STREAM:0x80`

The video processor supports blending input streams using a per-stream alpha value.

### `D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_PIXEL_ASPECT_RATIO:0x100`

The video processor supports explicit aspect ratios for the source and destination.

### `D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_MIRROR:0x200`

Indicates that the driver supports [**VideoProcessorSetStreamMirror**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videoprocessorsetstreammirror).

Supported starting with Windows 10.

### `D3D11_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_SHADER_USAGE:0x400`

Indicates that the hardware can benefit from a hint as to whether a shader might be used to read the output of [**VideoProcessorBlt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt). This should only be set by hardware that support multi-plane overlays.

### `D3DWDDM2_1DDI_VIDEO_PROCESSOR_FEATURE_CAPS_METADATA_HDR10:0x800`

Indicates that the driver will properly convert the video data based on the specified HDR10 metadata. Supported starting in Windows 10.

## See also

[**VideoProcessorBlt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorblt)

[**VideoProcessorSetOutputAlphaFillMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputalphafillmode)

[**VideoProcessorSetOutputConstriction**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetoutputconstriction)

[**VideoProcessorSetStreamLumaKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamlumakey)

[**VideoProcessorSetStreamMirror**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videoprocessorsetstreammirror)

[**VideoProcessorSetStreamStereoFormat**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videoprocessorsetstreamstereoformat)