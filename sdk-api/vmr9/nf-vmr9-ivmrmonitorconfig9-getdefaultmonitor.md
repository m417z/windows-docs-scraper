# IVMRMonitorConfig9::GetDefaultMonitor

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDefaultMonitor` method retrieves the default monitor that all future instances of the VMR will use for video playback.

## Parameters

### `puDev` [out]

Pointer that receives an index that identifies the default monitor on the system.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | The method succeeded. |
| **VFW_E_WRONG_STATE** | The allocator-presenter has not been loaded. |

## Remarks

Use this method on a multi-monitor system to determine which is the default Direct3D device the overlay mixer filter will use when connecting to an upstream filter.

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRMonitorConfig9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrmonitorconfig9)

[IVMRMonitorConfig9::SetDefaultMonitor](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrmonitorconfig9-setdefaultmonitor)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)