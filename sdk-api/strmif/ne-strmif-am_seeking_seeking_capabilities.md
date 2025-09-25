# AM_SEEKING_SEEKING_CAPABILITIES enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the seeking capabilities of a media stream.

## Constants

### `AM_SEEKING_CanSeekAbsolute:0x1`

The stream can seek to an absolute position.

### `AM_SEEKING_CanSeekForwards:0x2`

The stream can seek forward.

### `AM_SEEKING_CanSeekBackwards:0x4`

The stream can seek backward.

### `AM_SEEKING_CanGetCurrentPos:0x8`

The stream can report its current position. See Remarks.

### `AM_SEEKING_CanGetStopPos:0x10`

The stream can report its stop position.

### `AM_SEEKING_CanGetDuration:0x20`

The stream can report its duration.

### `AM_SEEKING_CanPlayBackwards:0x40`

The stream can play backward.

### `AM_SEEKING_CanDoSegments:0x80`

The stream can do seamless looping (see [IMediaSeeking::SetPositions](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-setpositions)).

### `AM_SEEKING_Source:0x100`

Reserved.

## Remarks

Most DirectShow filters do not report the **AM_SEEKING_CanGetCurrentPos** capability flag. However, the Filter Graph Manager's implementation of [IMediaSeeking::GetCurrentPosition](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-getcurrentposition) is based on the reference clock, so you can call this method even if the capabilities flags do not include **AM_SEEKING_CanGetCurrentPos**.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IMediaSeeking::CheckCapabilities](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-checkcapabilities)

[IMediaSeeking::GetCapabilities](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-getcapabilities)