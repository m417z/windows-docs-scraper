# IVMRSurfaceAllocator9::AdviseNotify

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AdviseNotify** method provides the allocator-presenter with the VMR-9 filter's interface for notification callbacks. If you are using a custom allocator-presenter, the application must call this method on the allocator-presenter, with a pointer to the VMR's [IVMRSurfaceAllocatorNotify9](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrsurfaceallocatornotify9) interface. The allocator-presenter uses this interface to communicate with the VMR.

If you are not using a custom allocator-presenter, the application does not have to call this method.

## Parameters

### `lpIVMRSurfAllocNotify` [in]

Specifies the [IVMRSurfaceAllocatorNotify9](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrsurfaceallocatornotify9) interface that the allocator-presenter will use to pass notifications back to the VMR.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRSurfaceAllocator9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrsurfaceallocator9)

[Supplying a Custom Allocator-Presenter for VMR-7](https://learn.microsoft.com/windows/desktop/DirectShow/supplying-a-custom-allocator-presenter-for-vmr-7)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)

[VMR Renderless Playback Mode (Custom Allocator-Presenters)](https://learn.microsoft.com/windows/desktop/DirectShow/vmr-renderless-playback-mode--custom-allocator-presenters)