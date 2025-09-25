# D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT structure

## Description

Provides information about the input streams passed into the [ID3DVideoContext1::VideoProcessorGetBehaviorHints](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11videocontext1-videoprocessorgetbehaviorhints) method.

## Members

### `Enable`

A value indicating whether this input stream should be used to compute behavior hints. Set to true if the stream should be used to compute behavior hints; otherwise, set to false.

### `Width`

The width of the input stream.

### `Height`

The height of the input stream.

### `Format`

The format of the input stream.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)