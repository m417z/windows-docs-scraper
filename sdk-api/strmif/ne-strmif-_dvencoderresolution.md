# _DVENCODERRESOLUTION enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates the digital video (DV) encoding resolution.

## Constants

### `DVENCODERRESOLUTION_720x480:2012`

See Remarks.

### `DVENCODERRESOLUTION_360x240:2013`

See Remarks.

### `DVENCODERRESOLUTION_180x120:2014`

See Remarks.

### `DVENCODERRESOLUTION_88x60:2015`

See Remarks.

## Remarks

The meaning of the enumeration elements depends on whether the current format is NTSC or PAL:

| Element | NTSC | PAL |
| --- | --- | --- |
| DVENCODERRESOLUTION_720x480 | 720 x 480 | 720 x 576 |
| DVENCODERRESOLUTION_360x240 | 360 x 240 | 360 x 288 |
| DVENCODERRESOLUTION_180x120 | 180 x 120 | 180 x 144 |
| DVENCODERRESOLUTION_88x60 | 88 x 60 | 88 x 72 |

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDVEnc Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvenc)