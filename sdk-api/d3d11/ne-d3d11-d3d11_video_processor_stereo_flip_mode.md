# D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE enumeration

## Description

For stereo 3D video, specifies whether the data in frame 0 or frame 1 is flipped, either horizontally or vertically.

## Constants

### `D3D11_VIDEO_PROCESSOR_STEREO_FLIP_NONE:0`

Neither frame is flipped.

### `D3D11_VIDEO_PROCESSOR_STEREO_FLIP_FRAME0:1`

The data in frame 0 is flipped.

### `D3D11_VIDEO_PROCESSOR_STEREO_FLIP_FRAME1:2`

The data in frame 1 is flipped.

## See also

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)

[ID3D11VideoContext::VideoProcessorSetStreamStereoFormat](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetstreamstereoformat)