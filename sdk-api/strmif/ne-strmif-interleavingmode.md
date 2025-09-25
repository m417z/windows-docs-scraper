# InterleavingMode enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies how video frames and audio samples will be written to disk.

## Constants

### `INTERLEAVE_NONE:0`

Noninterleaved. Frames are written in the order they arrive. Files must be interleaved for playback at a later time. In this mode, the AVI Mux filter attempts to use unbuffered, overlapped write operations, to increase throughput.

### `INTERLEAVE_CAPTURE`

Approximate interleaving with less overhead than **INTERLEAVE_FULL**. This mode is suitable for video capture. The AVI Mux attempts to use unbuffered, overlapped write operations. Unless the interleaving parameters are configured properly, however, frames may be dropped if one stream blocks while it waits for data from another stream. In particular, audio buffers should be less than .5 second, or else the video stream will block for excessive periods of time.

### `INTERLEAVE_FULL`

Full, precise interleaving of audio samples and video frames. Streams will block indefinitely, waiting for equal amounts of data before interleaving. This mode is suitable for authoring and playback.

### `INTERLEAVE_NONE_BUFFERED`

Noninterleaved. This mode is equivalent to **INTERLEAVE_NONE** but uses less file space and system overhead.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)