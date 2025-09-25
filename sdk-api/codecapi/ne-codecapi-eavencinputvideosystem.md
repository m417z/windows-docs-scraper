# eAVEncInputVideoSystem enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the nominal range for a video source. This enumeration is used with the [AVEncInputVideoSystem](https://learn.microsoft.com/windows/desktop/DirectShow/avencinputvideosystem-property) property.

## Constants

### `eAVEncInputVideoSystem_Unspecified:0`

The video system is not specified.

### `eAVEncInputVideoSystem_PAL:1`

PAL television.

### `eAVEncInputVideoSystem_NTSC:2`

NTSC television.

### `eAVEncInputVideoSystem_SECAM:3`

SECAM television.

### `eAVEncInputVideoSystem_MAC:4`

Not documented for this release.

### `eAVEncInputVideoSystem_HDV:5`

High-definition (HD) video.

### `eAVEncInputVideoSystem_Component:6`

Component video.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)