# IMultiMediaStream::Seek

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `Seek` method seeks all of the media streams to a new position.

## Parameters

### `SeekTime` [in]

[STREAM_TIME](https://learn.microsoft.com/windows/desktop/DirectShow/stream-time) value that specifies the new position.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The media streams do not support seeking. |
| **S_OK** | Success. |

## Remarks

To determine whether the media streams support seeking, call the [IMultiMediaStream::GetInformation](https://learn.microsoft.com/windows/desktop/api/mmstream/nf-mmstream-imultimediastream-getinformation) method.

## See also

[IMultiMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imultimediastream)