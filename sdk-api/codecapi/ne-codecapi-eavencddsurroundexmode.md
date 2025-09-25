# eAVEncDDSurroundExMode enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies whether a Dolby Digital audio stream is encoded in Dolby Digital Surround EX. This enumeration is used with the [AVEncDDSurroundExMode](https://learn.microsoft.com/windows/desktop/DirectShow/avencddsurroundexmode-property) property.

## Constants

### `eAVEncDDSurroundExMode_NotIndicated:0`

The Surround EX mode is not indicated.

### `eAVEncDDSurroundExMode_No:1`

The audio is not encoded in Surround EX.

### `eAVEncDDSurroundExMode_Yes:2`

The audio is encoded in Surround EX.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)