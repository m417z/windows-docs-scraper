# IAMDevMemoryAllocator::CheckMemory

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IAMDevMemoryAllocator** interface is deprecated.

Tests whether the specific instance (device) of the allocator allocated a memory pointer.

## Parameters

### `pBuffer` [in]

Pointer to the allocated memory buffer's address.

## Return value

Returns S_OK if the on-board allocator allocated the memory, or S_FALSE if not. Memory that is on the particular device but not allocated will also return S_FALSE.

## Remarks

The hardware filter typically uses this method to test whether the pointer actually points to on-board memory.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMDevMemoryAllocator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdevmemoryallocator)