# IVMRSurfaceAllocatorNotify9::AdviseSurfaceAllocator

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AdviseSurfaceAllocator` method is called by an application to instruct the VMR-9 to use a custom allocator-presenter.

## Parameters

### `dwUserID` [in]

Application-defined value that identifies this instance of the VMR-9.

### `lpIVRMSurfaceAllocator` [in]

Pointer to the [IVMRSurfaceAllocator9](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrsurfaceallocator9) interface on the custom surface allocator object.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method can be called only once in the lifetime of the VMR. The VMR continues to use the allocator-presenter until the VMR is itself deleted. When the VMR is finally released, it releases its reference count on the custom allocator-presenter object, which allows that object to be freed.

The custom allocator-presenter must also support the [IVMRImagePresenter9](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrimagepresenter9) interface.

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRSurfaceAllocatorNotify9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrsurfaceallocatornotify9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)