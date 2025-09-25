# AMVP_MODE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the various modes for video ports.

## Constants

### `AMVP_MODE_WEAVE`

Weave.

### `AMVP_MODE_BOBINTERLEAVED`

Interleaved bob. Bob mode in which resources are allocated to switch to weave mode, for example, on the next frame.

### `AMVP_MODE_BOBNONINTERLEAVED`

### `AMVP_MODE_SKIPEVEN`

Skip even fields.

### `AMVP_MODE_SKIPODD`

Skip odd fields.

#### - MODE_BOBNONINTERLEAVED

Noninterleaved bob. Bob mode in which resources are not allocated to switch to weave mode.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)