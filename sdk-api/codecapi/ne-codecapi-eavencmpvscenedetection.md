# eAVEncMPVSceneDetection enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies how the encoder behaves when it detects a new scene. This enumeration is used with the [AVEncMPVSceneDetection](https://learn.microsoft.com/windows/desktop/DirectShow/avencmpvscenedetection-property) property.

## Constants

### `eAVEncMPVSceneDetection_None:0`

No special behavior.

### `eAVEncMPVSceneDetection_InsertIPicture:1`

Insert an I frame.

### `eAVEncMPVSceneDetection_StartNewGOP:2`

Start a new group of pictures (GOP).

### `eAVEncMPVSceneDetection_StartNewLocatableGOP:3`

Start a new GOP in which the first consecutive B frames do not reference the previous GOP.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)