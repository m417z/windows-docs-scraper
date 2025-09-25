# eAVDDSurroundMode enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies whether the audio is encoded in Dolby Surround. This enumeration is used with the [AVDDSurroundMode](https://learn.microsoft.com/windows/desktop/DirectShow/avddsurroundmode-property) property.

## Constants

### `eAVDDSurroundMode_NotIndicated:0`

The bit stream does not indicate whether the audio is encoded in Dolby Surround.

### `eAVDDSurroundMode_No:1`

The bit stream is not encoded in Dolby Surround.

### `eAVDDSurroundMode_Yes:2`

The bit stream is encoded in Dolby Surround.

## Remarks

If the audio stream is Dolby AC-3, this property reflects the value of the dsurmod field in the bit stream.

| Bit field | Value |
| --- | --- |
| 00 | eAVDDSurroundMode_NotIndicated |
| 01 | eAVDDSurroundMode_No |
| 10 | eAVDDSurroundMode_Yes |

If the audio stream is any other format, the value is eAVDDSurroundMode_No.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)