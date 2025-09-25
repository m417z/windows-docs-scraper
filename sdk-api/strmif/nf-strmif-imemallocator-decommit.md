# IMemAllocator::Decommit

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Decommit` method releases the buffer memory.

## Return value

Returns S_OK if successful, or an **HRESULT** value indicating the cause of the error.

## Remarks

Any threads waiting in the [IMemAllocator::GetBuffer](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imemallocator-getbuffer) method return with an error. Further calls to **GetBuffer** fail, until the [IMemAllocator::Commit](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imemallocator-commit) method is called.

The purpose of the `Decommit` method is to prevent filters from getting any more samples from the allocator. Filters that already hold a reference count on a sample are not affected. After a filter releases a sample and the reference count goes to zero, however, the sample is no longer available.

The allocator may free the memory belonging to any sample with a reference count of zero. Thus, the `Decommit` method "releases" the memory in the sense that filters stop having access to it. Whether the memory actually returns to the heap depends on the implementation of the allocator. Some allocators wait until their own destructor method. However, an allocator must not leave any allocated memory behind when it deletes itself. Therefore, an allocator's destructor must wait until all of its samples are released.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMemAllocator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imemallocator)