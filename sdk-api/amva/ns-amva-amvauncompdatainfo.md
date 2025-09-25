# AMVAUncompDataInfo structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AMVAUncompDataInfo** structure specifies the dimensions and pixel format of the uncompressed surfaces for DirectX Video Acceleration (DXVA) video decoding.

## Members

### `dwUncompWidth`

Width of the decoded, uncompressed data, in pixels.

### `dwUncompHeight`

Height of the decoded, uncompressed data, in pixels.

### `ddUncompPixelFormat`

A **DDPIXELFORMAT** structure that specifies the pixel format of the uncompressed data.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IAMVideoAccelerator::GetCompBufferInfo](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-getcompbufferinfo)