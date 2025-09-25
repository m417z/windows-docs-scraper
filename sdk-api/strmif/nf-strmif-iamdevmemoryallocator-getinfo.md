# IAMDevMemoryAllocator::GetInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IAMDevMemoryAllocator** interface is deprecated.

Retrieves information about the memory capabilities.

## Parameters

### `pdwcbTotalFree` [out]

Pointer to the total free memory size.

### `pdwcbLargestFree` [out]

Pointer to the returned largest free memory size.

### `pdwcbTotalMemory` [out]

Pointer to the returned total memory size.

### `pdwcbMinimumChunk` [out]

Pointer to the returned minimum chunk size, giving granularity and alignment rules.

## Return value

Returns an **HRESULT** value.

## Remarks

Use this method to find out the total amount of memory available. This method returns values for the entire on-board memory that is available on that device. If multiple filters (devices) share the memory, it will return the amount available to that specific device, which might be a portion of the total amount of on-board memory. This amount will be implementation-specific. For example, the on-board memory manager on the codec might be able to access all 32 megabytes (MB) of memory on the card. However, individual pin implementations of [IAMDevMemoryAllocator](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdevmemoryallocator) only report a portion of this memory.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMDevMemoryAllocator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdevmemoryallocator)