# D3D11_VIDEO_PROCESSOR_FILTER_CAPS enumeration

## Description

Defines image filter capabilities for a Microsoft Direct3D 11 video processor.

## Constants

### `D3D11_VIDEO_PROCESSOR_FILTER_CAPS_BRIGHTNESS:0x1`

The video processor can adjust the brightness level.

### `D3D11_VIDEO_PROCESSOR_FILTER_CAPS_CONTRAST:0x2`

The video processor can adjust the contrast level.

### `D3D11_VIDEO_PROCESSOR_FILTER_CAPS_HUE:0x4`

The video processor can adjust hue.

### `D3D11_VIDEO_PROCESSOR_FILTER_CAPS_SATURATION:0x8`

The video processor can adjust the saturation level.

### `D3D11_VIDEO_PROCESSOR_FILTER_CAPS_NOISE_REDUCTION:0x10`

The video processor can perform noise reduction.

### `D3D11_VIDEO_PROCESSOR_FILTER_CAPS_EDGE_ENHANCEMENT:0x20`

The video processor can perform edge enhancement.

### `D3D11_VIDEO_PROCESSOR_FILTER_CAPS_ANAMORPHIC_SCALING:0x40`

The video processor can perform anamorphic scaling. Anamorphic scaling can be used to stretch 4:3 content to a widescreen 16:9 aspect ratio.

### `D3D11_VIDEO_PROCESSOR_FILTER_CAPS_STEREO_ADJUSTMENT:0x80`

For stereo 3D video, the video processor can adjust the offset between the left and right views, allowing the user to reduce potential eye strain.

## Remarks

These capability flags indicate support for the image filters defined by the [D3D11_VIDEO_PROCESSOR_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_filter) enumeration. To apply a particular filter, call the [ID3D11VideoContext::VideoProcessorSetStreamFilter](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetstreamfilter) method.

## See also

[D3D11_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_caps)

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)