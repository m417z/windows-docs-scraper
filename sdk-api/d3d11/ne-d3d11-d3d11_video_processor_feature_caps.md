# D3D11_VIDEO_PROCESSOR_FEATURE_CAPS enumeration

## Description

Defines features that a Microsoft Direct3D 11 video processor can support.

## Constants

### `D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_FILL:0x1`

The video processor can set alpha values on the output pixels. For more information, see [ID3D11VideoContext::VideoProcessorSetOutputAlphaFillMode](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetoutputalphafillmode).

### `D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_CONSTRICTION:0x2`

The video processor can downsample the video output. For more information, see [ID3D11VideoContext::VideoProcessorSetOutputConstriction](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetoutputconstriction).

### `D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_LUMA_KEY:0x4`

The video processor can perform luma keying. For more information, see [ID3D11VideoContext::VideoProcessorSetStreamLumaKey](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetstreamlumakey).

### `D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_PALETTE:0x8`

The video processor can apply alpha values from color palette entries.

### `D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_LEGACY:0x10`

The driver does not support full video processing capabilities. If this capability flag is set, the video processor has the following limitations:

* A maximum of two streams are supported:
  + The first stream must be either NV12 or YUY2.
  + The second stream must be AYUV, AI44, or IA44.
* Image adjustment (proc amp) controls are applied to the entire video processing blit, rather than per stream.
* Support for per-stream planar alpha is not reliable. (Per-pixel alpha is supported, however.)

### `D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_STEREO:0x20`

The video processor can support 3D stereo video. For more information, see [ID3D11VideoContext::VideoProcessorSetStreamStereoFormat](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetstreamstereoformat).

All drivers setting this caps must support the following stereo formats: [D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_HORIZONTAL](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_stereo_format), **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_VERTICAL**, and **D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_SEPARATE**.

### `D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_ROTATION:0x40`

The driver can rotate the input data either 90, 180, or 270 degrees clockwise as part of the video processing operation.

### `D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_STREAM:0x80`

The driver supports the [VideoProcessorSetStreamAlpha](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetstreamalpha) call.

### `D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_PIXEL_ASPECT_RATIO:0x100`

The driver supports the [VideoProcessorSetStreamPixelAspectRatio](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetstreampixelaspectratio) call.

### `D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_MIRROR:0x200`

### `D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_SHADER_USAGE:0x400`

### `D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_METADATA_HDR10:0x800`

## See also

[D3D11_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_caps)

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)