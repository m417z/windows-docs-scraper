# eAVEncVideoSourceScanType enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies whether the input frames for an encoder are progressive or interlaced. This enumeration is used with the [AVEncVideoForceSourceScanType](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideoforcesourcescantype-property) property.

## Constants

### `eAVEncVideoSourceScan_Automatic:0`

Use the media type on the encoder's input pin to determine whether the frames are progressive or interlaced.

### `eAVEncVideoSourceScan_Interlaced:1`

Input frames are interlaced.

### `eAVEncVideoSourceScan_Progressive:2`

Input frames are progressive.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)