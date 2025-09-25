# D3D11_VIDEO_PROCESSOR_FILTER enumeration

## Description

Identifies a video processor filter.

## Constants

### `D3D11_VIDEO_PROCESSOR_FILTER_BRIGHTNESS:0`

Brightness filter.

### `D3D11_VIDEO_PROCESSOR_FILTER_CONTRAST:1`

Contrast filter.

### `D3D11_VIDEO_PROCESSOR_FILTER_HUE:2`

Hue filter.

### `D3D11_VIDEO_PROCESSOR_FILTER_SATURATION:3`

Saturation filter.

### `D3D11_VIDEO_PROCESSOR_FILTER_NOISE_REDUCTION:4`

Noise reduction filter.

### `D3D11_VIDEO_PROCESSOR_FILTER_EDGE_ENHANCEMENT:5`

Edge enhancement filter.

### `D3D11_VIDEO_PROCESSOR_FILTER_ANAMORPHIC_SCALING:6`

Anamorphic scaling filter.

### `D3D11_VIDEO_PROCESSOR_FILTER_STEREO_ADJUSTMENT:7`

Stereo adjustment filter. When stereo 3D video is enabled, this filter adjusts the offset between the left and right views, allowing the user to reduce potential eye strain.

The filter value indicates the amount by which the left and right views are adjusted. A positive value shifts the images away from each other: the left image toward the left, and the right image toward the right. A negative value shifts the images in the opposite directions, closer to each other.

## See also

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)

[ID3D11VideoContext::VideoProcessorSetStreamFilter](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetstreamfilter)