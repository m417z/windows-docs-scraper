# IVMRSurfaceAllocator::AdviseNotify

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AdviseNotify` method provides the allocator-presenter with the VMR-7 filter's interface for notification callbacks. If you are using a custom allocator-presenter, the application must call this method on the allocator-presenter, with a pointer to the VMR's **IVMRSurfaceAllocatorNotify** interface. The allocator-presenter uses this interface to communicate with the VMR.

If you are not using a custom allocator-presenter, the application does not have to call this method.

## Parameters

### `lpIVMRSurfAllocNotify` [in]

Specifies the [IVMRSurfaceAllocatorNotify](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrsurfaceallocatornotify) interface pointer that the allocator-presenter will use to pass notifications back to the VMR.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRSurfaceAllocator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrsurfaceallocator)

[Supplying a Custom Allocator-Presenter for VMR-7](https://learn.microsoft.com/windows/desktop/DirectShow/supplying-a-custom-allocator-presenter-for-vmr-7)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)

[VMR Renderless Playback Mode (Custom Allocator-Presenters)](https://learn.microsoft.com/windows/desktop/DirectShow/vmr-renderless-playback-mode--custom-allocator-presenters)