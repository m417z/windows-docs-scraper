# IMultiMediaStream::GetEndOfStreamEventHandle

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `GetEndOfStreamEventHandle` method retrieves an event that is signaled when the multimedia stream completes playback.

## Parameters

### `phEOS` [out]

Pointer to a variable that receives a handle to the event. The event is signaled when all of the streams in the multimedia stream object complete playback.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **MS_E_BUSY** | The multimedia stream is not stopped. |
| **S_OK** | Success. |

## See also

[IMultiMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imultimediastream)