# _DMO_VIDEO_OUTPUT_STREAM_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DMO_VIDEO_OUTPUT_STREAM_FLAGS` enumeration defines flags that describe requested features, for video optimizations.

## Constants

### `DMO_VOSF_NEEDS_PREVIOUS_SAMPLE:0x1`

Requests that every output buffer passed to the DMO contain the previous data that was generated.

## See also

[DMO Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-enumerated-types)

[IDMOVideoOutputOptimizations](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-idmovideooutputoptimizations)