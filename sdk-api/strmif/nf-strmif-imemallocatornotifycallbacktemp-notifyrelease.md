# IMemAllocatorNotifyCallbackTemp::NotifyRelease

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `NotifyRelease` method is called whenever the allocator's [IMemAllocator::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imemallocator-releasebuffer) method is called. The **ReleaseBuffer** method returns a media sample to the allocator's free list. Samples call this method when their reference counts reach zero.

## Return value

Return S_OK or an error code.

## Remarks

In general, this call can occur on any thread, and the caller may be holding critical sections. Therefore, this method should not do anything that could cause a deadlock. Instead, the method should set an event or post a message to another thread, and the other thread should take any required actions.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMemAllocatorNotifyCallbackTemp Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imemallocatornotifycallbacktemp)