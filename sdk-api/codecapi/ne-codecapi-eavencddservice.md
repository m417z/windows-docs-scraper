# eAVEncDDService enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the audio service contained in a Dolby Digital audio stream. This enumeration is used with the [AVEncDDService](https://learn.microsoft.com/windows/desktop/DirectShow/avencddservice-property) property.

## Constants

### `eAVEncDDService_CM:0`

Complete main audio service.

### `eAVEncDDService_ME:1`

Main service: music and effects. (The main audio service minus the dialog channel.)

### `eAVEncDDService_VI:2`

Associated service: visually impaired.

### `eAVEncDDService_HI:3`

Associated service: hard of hearing.

### `eAVEncDDService_D:4`

Associated service: dialog.

### `eAVEncDDService_C:5`

Associated service: commentary.

### `eAVEncDDService_E:6`

Associated service: emergency.

### `eAVEncDDService_VO:7`

Associated service: voice over.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)