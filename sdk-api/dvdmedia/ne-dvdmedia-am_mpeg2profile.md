# AM_MPEG2Profile enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates an MPEG-2 video profile as specified in the MPEG-2 video standard (ISO13818-2).

## Constants

### `AM_MPEG2Profile_Simple:1`

Simple profile.

### `AM_MPEG2Profile_Main:2`

Main profile.

### `AM_MPEG2Profile_SNRScalable:3`

Signal to Noise Ratio (SNR) scalable profile

### `AM_MPEG2Profile_SpatiallyScalable:4`

Spatially scalable profile.

### `AM_MPEG2Profile_High:5`

High profile.

## Remarks

DVD video decoders should support **AM_MPEG2Profile_Simple** or **AM_MPEG2Profile_Main**.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)