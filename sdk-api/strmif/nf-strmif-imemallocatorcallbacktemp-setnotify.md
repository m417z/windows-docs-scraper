# IMemAllocatorCallbackTemp::SetNotify

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetNotify` method sets or removes a callback on the allocator. The allocator calls the callback method whenever the allocator's [IMemAllocator::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imemallocator-releasebuffer) method is called.

## Parameters

### `pNotify`

Pointer to the [IMemAllocatorNotifyCallbackTemp](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imemallocatornotifycallbacktemp) interface that will be used for the callback. The caller must implement the interface. Use the value **NULL** to remove the callback.

## Return value

Returns S_OK if successful, or an error code otherwise.

## Remarks

Whenever the allocator's **ReleaseBuffer** method is called, the allocator calls the **NotifyRelease** method on the interface provided in *pNotify*. The **ReleaseBuffer** method returns a media sample to the allocator's free list. Samples call this method when their reference counts reach zero.

The allocator holds a reference count on the caller's **IMemAllocatorNotifyCallbackTemp** interface. This can create circular reference counts, thereby preventing objects in the graph from being released correctly. Therefore, when the caller no longer needs callback notifications, it should call this method again with the value **NULL**. An appropriate time to do this is when the graph stops, or else when the pins are disconnected.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMemAllocatorCallbackTemp Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imemallocatorcallbacktemp)