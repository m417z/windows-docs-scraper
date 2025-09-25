# IVMRSurfaceAllocatorNotify9::NotifyEvent

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `NotifyEvent` method is called by the allocator-presenter to inform the VMR of any significant DirectShow events that it (the allocator presenter) generates during the allocation or presentation processes.

## Parameters

### `EventCode` [in]

Specifies the DirectShow event code.

### `Param1` [in]

Specifies the first event parameter. The meaning depends on the event code. See [Event Notification Codes](https://learn.microsoft.com/windows/desktop/DirectShow/event-notification-codes).

### `Param2` [in]

Specifies the second event parameter. The meaning depends on the event code.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The VMR provides the allocator-presenter with a pointer to this interface in a call to [IVMRSurfaceAllocator9::AdviseNotify](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrsurfaceallocator9-advisenotify). When the allocator-presenter calls this method and specifies some regular DirectShow event, such as EC_ERRORABORT or EC_VMR_RENDERDEVICE_SET, the VMR will pass the event to the filter graph manager.

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRSurfaceAllocatorNotify9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrsurfaceallocatornotify9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)