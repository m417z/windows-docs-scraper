# IDirectDrawMediaStream::SetDirectDraw

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Sets the current media stream's DirectDraw object.

## Parameters

### `pDirectDraw` [in]

Pointer to an **IDirectDraw** interface that contains the media stream's new DirectDraw object.

## Return value

Returns S_OK if successful or E_POINTER if the pointer is invalid.

## Remarks

This method fails if the current stream already has allocated samples and its DirectDraw object differs from the specified one. It will always succeed if the specified DirectDraw object matches the stream's current object.

If this stream has no allocated samples, you can set *pDirectDraw* to **NULL**. This forces the stream to release its reference to the current DirectDraw object.

## See also

[IDirectDrawMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/ddstream/nn-ddstream-idirectdrawmediastream)