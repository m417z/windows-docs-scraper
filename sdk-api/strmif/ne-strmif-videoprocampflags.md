# VideoProcAmpFlags enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VideoProcAmpFlags** enumeration indicates whether a particular video property is controlled manually or automatically.

## Constants

### `VideoProcAmp_Flags_Auto:0x1`

The setting is controlled automatically.

### `VideoProcAmp_Flags_Manual:0x2`

The setting is controlled manually.

## Remarks

The following flags defined in KsMedia.h are equivalent to the values in **VideoProcAmpFlags**:

``` syntax
#define KSPROPERTY_VIDEOPROCAMP_FLAGS_AUTO        0X0001L
#define KSPROPERTY_VIDEOPROCAMP_FLAGS_MANUAL      0X0002L
```

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMVideoProcAmp Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideoprocamp)