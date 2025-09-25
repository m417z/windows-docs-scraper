# IAMDevMemoryAllocator::Free

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IAMDevMemoryAllocator** interface is deprecated.

Frees the previously allocated memory.

## Parameters

### `pBuffer` [in]

Pointer to the allocated memory.

## Return value

Returns E_INVALIDARG if the specified allocator didn't allocate the memory (that is, [CheckMemory](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamdevmemoryallocator-checkmemory) fails).

## Remarks

This method frees a block of memory from the pool.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMDevMemoryAllocator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdevmemoryallocator)