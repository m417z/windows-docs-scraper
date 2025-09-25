# eAVEncVideoChromaResolution enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies chroma resolution. This enumeration is used with the [AVEncVideoInputChromaResolution](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideoinputchromaresolution-property) and [AVEncVideoOutputChromaResolution](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideooutputchromaresolution-property) properties.

## Constants

### `eAVEncVideoChromaResolution_SameAsSource:0`

Use the same chroma resolution as the input video. This flag applies to the **AVEncVideoOutputChromaResolution** property only.

### `eAVEncVideoChromaResolution_444:1`

4:4:4 (no downsampling).

### `eAVEncVideoChromaResolution_422:2`

4:2:2 (2:1 horizontal downsampling, with no vertical downsampling).

### `eAVEncVideoChromaResolution_420:3`

4:2:0 (2:1 horizontal downsampling, with 2:1 vertical downsampling).

### `eAVEncVideoChromaResolution_411:4`

4:1:1 (4:1 horizontal downsampling, with no vertical downsampling).

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)