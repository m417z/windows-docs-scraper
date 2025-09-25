# eAVDecHEAACDynamicRangeControl enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies whether an AAC decoder performs dynamic range control. This enumeration is used with the [AVDecHEAACDynamicRangeControl](https://learn.microsoft.com/windows/desktop/DirectShow/avdecheaacdynamicrangecontrol-property) property.

## Constants

### `eAVDecHEAACDynamicRangeControl_OFF:0`

The decoder does not apply dynamic range control.

### `eAVDecHEAACDynamicRangeControl_ON:1`

The decoder applies dynamic range control to any AAC stream that contains an extension payload of type EXT_DYNAMIC_RANGE, as defined in ISO/IEC 14496-3 (Table 4.105, "Values of the extension_type field").

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)