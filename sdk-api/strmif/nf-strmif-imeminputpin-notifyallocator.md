# IMemInputPin::NotifyAllocator

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `NotifyAllocator` method specifies an allocator for the connection.

## Parameters

### `pAllocator` [in]

Pointer to the allocator's [IMemAllocator](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imemallocator) interface.

### `bReadOnly` [out]

Flag that specifies whether samples from this allocator are read-only. If **TRUE**, samples are read-only.

## Return value

Returns S_OK if successful, or an **HRESULT** value indicating the cause of the error.

## Remarks

During the pin connection, the output pin chooses an allocator and calls this method to notify the input pin. The output pin might use the allocator that the input pin proposed in the [IMemInputPin::GetAllocator](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imeminputpin-getallocator) method, or it might provide its own allocator.

If the *bReadOnly* parameter is **TRUE**, all samples in the allocator are read-only. The filter must copy them to modify the data.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMemInputPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imeminputpin)