# TIMECODE structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **TIMECODE** structure contains basic timecode frame count information.

## Members

### `wFrameRate`

Number of frames per second. Specify with one of the following values:

| Value | Meaning |
| --- | --- |
| **ED_FORMAT_SMPTE_30** | 30 frames per second. |
| **ED_FORMAT_SMPTE_30DROP** | 30 frames per second drop frame (actual rate 29.97 fps). |
| **ED_FORMAT_SMPTE_25** | 25 frames per second. |
| **ED_FORMAT_SMPTE_24** | 24 frames per second. |

### `wFrameFract`

Fractional frame. Full scale is 0x1000.

### `dwFrames`

Timecode value as a binary framecount.

## Remarks

Fractional frame can be used to indicate temporal offset into frame when timecode was actually read from an external device; for example, wFrameFract=0x7ff means the timecode value was read from the device at the end of the first video field.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)