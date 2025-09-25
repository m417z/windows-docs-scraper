# eAVEncMPAEmphasisType enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the type of de-emphasis filter that should be used when decoding. This enumeration is used with the [AVEncMPAEmphasisType](https://learn.microsoft.com/windows/desktop/DirectShow/avencmpaemphasistype-property) property.

## Constants

### `eAVEncMPAEmphasisType_None:0`

None.

### `eAVEncMPAEmphasisType_50_15:1`

50/15 Î¼s.

### `eAVEncMPAEmphasisType_Reserved:2`

Reserved.

### `eAVEncMPAEmphasisType_CCITT_J17:3`

CCITT J.17.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)