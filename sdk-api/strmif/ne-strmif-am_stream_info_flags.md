# AM_STREAM_INFO_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AM_STREAM_INFO_FLAGS** enumeration defines flags that indicate a pin's stream-control status.

## Constants

### `AM_STREAM_INFO_START_DEFINED:0x1`

Indicates that the pin's start time is set.

### `AM_STREAM_INFO_STOP_DEFINED:0x2`

Indicates that the pin's stop time is been set.

### `AM_STREAM_INFO_DISCARDING:0x4`

Indicates that the pin is currently discarding data.

### `AM_STREAM_INFO_STOP_SEND_EXTRA:0x10`

Indicates that the pin will send one extra sample after it reaches the stop time.

## See also

[AM_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_stream_info)

[IAMStreamControl::GetInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamcontrol-getinfo)