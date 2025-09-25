# AM_MPEG2Level enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates an MPEG-2 video level as specified in the MPEG-2 video standard (ISO13818-2).

## Constants

### `AM_MPEG2Level_Low:1`

Low level.

### `AM_MPEG2Level_Main:2`

Main level.

### `AM_MPEG2Level_High1440:3`

High 1440 level.

### `AM_MPEG2Level_High:4`

High level.

## Remarks

DVD MPEG-2 video decoders should support AM_MPEG2Level_Low or AM_MPEG2Level_Main.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)