# IMediaBuffer::SetLength

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetLength` method specifies the length of the data currently in the buffer.

## Parameters

### `cbLength`

Size of the data, in bytes. The value must not exceed the buffer's maximum size. Call the [IMediaBuffer::GetMaxLength](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediabuffer-getmaxlength) method to obtain the maximum size.

## Return value

Returns S_OK if successful. Otherwise, returns an **HRESULT** value indicating the cause of the error.

## Remarks

This method sets the size of the valid data currently in the buffer, not the buffer's allocated size.

## See also

[IMediaBuffer Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediabuffer)

[Implementing IMediaBuffer](https://learn.microsoft.com/windows/desktop/DirectShow/implementing-imediabuffer)