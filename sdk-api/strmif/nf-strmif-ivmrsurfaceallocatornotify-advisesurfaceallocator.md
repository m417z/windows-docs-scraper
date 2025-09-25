# IVMRSurfaceAllocatorNotify::AdviseSurfaceAllocator

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AdviseSurfaceAllocator` method is called by an application to instruct the VMR to use a custom allocator-presenter.

## Parameters

### `dwUserID` [in]

An application-defined DWORD_PTR that uniquely identifies this instance of the VMR in scenarios when multiple instances of the VMR are being used with a single instance of an allocator-presenter.

### `lpIVRMSurfaceAllocator` [in]

Specifies the [IVMRSurfaceAllocator](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrsurfaceallocator) interface on the new allocator-presenter. If this value is **NULL**, then the VMR will release the client allocator-presenter and restore its default allocator-presenter.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The method will cause the default allocator-presenter to be uninstalled and destroyed, and replaced with the specified new component. The new component must also support the [IVMRImagePresenter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrimagepresenter) interface.

This method can be called only once in the lifetime of the VMR. The VMR continues to use the allocator-presenter until the VMR is itself deleted. When the VMR is finally released, it releases its reference count on the custom allocator-presenter object, which allows that object to be freed.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRSurfaceAllocatorNotify Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrsurfaceallocatornotify)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)