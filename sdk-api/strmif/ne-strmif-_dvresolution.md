# _DVRESOLUTION enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates the digital video (DV) decoding resolution.

## Constants

### `DVRESOLUTION_FULL:1000`

Decode at full size.

### `DVRESOLUTION_HALF:1001`

Decode at half size.

### `DVRESOLUTION_QUARTER:1002`

Decode at quarter size.

### `DVRESOLUTION_DC:1003`

Decode at one-eighth size.

## Remarks

The decoding resolution depends on whether the current format is NTSC or PAL:

| Enumeration | NTSC | PAL |
| --- | --- | --- |
| DVRESOLUTION_FULL | 720 x 480 | 720 x 576 |
| DVRESOLUTION_HALF | 360 x 240 | 360 x 288 |
| DVRESOLUTION_QUARTER | 180 x 120 | 180 x 144 |
| DVRESOLUTION_DC | 88 x 60 | 88 x 72 |

The following enumeration defined in strmif.h is equivalent to the **_DVRESOLUTION** enumeration. It is included for compatibility with existing applications.

``` syntax
enum _DVDECODERRESOLUTION {
    DVDECODERRESOLUTION_720x480     =   1000,
    DVDECODERRESOLUTION_360x240     =   1001,
    DVDECODERRESOLUTION_180x120     =   1002,
    DVDECODERRESOLUTION_88x60       =   1003
};
```

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IIPDVDec Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iipdvdec)