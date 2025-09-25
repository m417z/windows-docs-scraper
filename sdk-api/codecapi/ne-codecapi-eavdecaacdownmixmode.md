# eAVDecAACDownmixMode enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies whether an AAC decoder uses standard MPEG-2/MPEG-4 stereo downmix equations. This enumeration is used with the [AVDecAACDownmixMode](https://learn.microsoft.com/windows/desktop/DirectShow/avdecaacdownmixmode-property) property.

## Constants

### `eAVDecAACUseISODownmix:0`

Use the standard ISO MPEG-2/MPEG-4 downmix equations.

### `eAVDecAACUseARIBDownmix:1`

Use the downmix equations defined by ARIB document STD-B21.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)