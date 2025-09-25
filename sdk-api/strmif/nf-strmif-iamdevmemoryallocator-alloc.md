# IAMDevMemoryAllocator::Alloc

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IAMDevMemoryAllocator** interface is deprecated.

Allocates a memory buffer.

## Parameters

### `ppBuffer` [out]

Pointer that will receive the address of the allocated memory buffer.

### `pdwcbBuffer` [in, out]

Pointer to a **DWORD** whose input value is the number of bytes to allocate and whose output value is the actual number of bytes allocated.

## Return value

Returns S_OK if the desired quantity of memory was allocated, S_FALSE if memory was unavailable.

## Remarks

Call this method to allocate a block of memory from the available pool.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMDevMemoryAllocator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdevmemoryallocator)

[IAMDevMemoryAllocator::Free](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamdevmemoryallocator-free)