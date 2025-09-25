# IMediaBuffer::GetMaxLength

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetMaxLength` method retrieves the maximum number of bytes this buffer can hold.

## Parameters

### `pcbMaxLength` [out]

Pointer to a variable that receives the buffer's maximum size, in bytes.

## Return value

Returns S_OK if successful. Otherwise, returns an **HRESULT** value indicating the cause of the error.

## See also

[IMediaBuffer Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediabuffer)

[Implementing IMediaBuffer](https://learn.microsoft.com/windows/desktop/DirectShow/implementing-imediabuffer)