# eAVEncVideoColorLighting enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the intended lighting conditions for viewing a video source. This enumeration is used with the [AVEncVideoInputColorLighting](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideoinputcolorlighting-property) and [AVEncVideoOutputColorLighting](https://learn.microsoft.com/windows/desktop/DirectShow/avencvideooutputcolorlighting-property) properties.

## Constants

### `eAVEncVideoColorLighting_SameAsSource:0`

Use the same lighting as the input video. This flag applies to the **AVEncVideoOutputColorLighting** property only.

### `eAVEncVideoColorLighting_Unknown:1`

The optimal lighting is unknown.

### `eAVEncVideoColorLighting_Bright:2`

Bright lighting; for example, outdoors.

### `eAVEncVideoColorLighting_Office:3`

Medium brightness; for example, normal office lighting.

### `eAVEncVideoColorLighting_Dim:4`

Dim; for example, a living room with a television and additional low lighting.

### `eAVEncVideoColorLighting_Dark:5`

Dark; for example, a movie theater.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)