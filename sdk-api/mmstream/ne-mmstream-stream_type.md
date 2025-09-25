# STREAM_TYPE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This API is deprecated. New applications should not use it.

Defines the direction of data flow for the stream.

## Constants

### `STREAMTYPE_READ:0`

Application can read the stream.

### `STREAMTYPE_WRITE:1`

Application can write to the stream.

### `STREAMTYPE_TRANSFORM:2`

Application reads and writes to the stream.

## Remarks

Transform streams are read/write where the sample is updated in place.

## See also

[Multimedia Streaming Enumeration Types](https://learn.microsoft.com/windows/desktop/DirectShow/multimedia-streaming-types)