# IMemAllocator::ReleaseBuffer

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ReleaseBuffer` method releases a media sample.

## Parameters

### `pBuffer` [in]

Pointer to the media sample's [IMediaSample](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample) interface.

## Return value

Returns S_OK if successful, or an **HRESULT** value indicating the cause of the error.

## Remarks

When a media sample's reference count reaches zero, it calls this method with itself as the *pBuffer* parameter. This method releases the sample back to the allocator's list of available samples.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMemAllocator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imemallocator)