# AMExtendedSeekingCapabilities enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AMExtendedSeekingCapabilities** enumeration contains flags that describe the extended seeking capabilities of a filter.

## Constants

### `AM_EXSEEK_CANSEEK:1`

Indicates that the stream is seekable.

### `AM_EXSEEK_CANSCAN:2`

Indicates that the filter supports rates other than 1.0.

### `AM_EXSEEK_MARKERSEEK:4`

Indicates that the stream contains markers.

### `AM_EXSEEK_SCANWITHOUTCLOCK:8`

Indicates that the filter can play back at rates other than 1.0.

### `AM_EXSEEK_NOSTANDARDREPAINT:16`

Indicates that the filter can seek to a new frame without displaying the new frame when it finds it.

### `AM_EXSEEK_BUFFERING:32`

Indicates that the filter can seek while the stream is buffering.

### `AM_EXSEEK_SENDS_VIDEOFRAMEREADY:64`

Indicates that the filter's video pin has been created.

## Remarks

See [IAMExtendedSeeking::get_ExSeekCapabilities](https://learn.microsoft.com/windows/desktop/api/qnetwork/nf-qnetwork-iamextendedseeking-get_exseekcapabilities) for descriptions of how the [Windows Media Source](https://learn.microsoft.com/windows/desktop/DirectShow/windows-media-source-filter) filter sets these flags.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)