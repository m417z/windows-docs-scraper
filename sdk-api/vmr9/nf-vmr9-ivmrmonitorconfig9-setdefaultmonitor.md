# IVMRMonitorConfig9::SetDefaultMonitor

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDefaultMonitor` method specifies the default monitor that all future instances of the VMR should use for video playback.

## Parameters

### `uDev` [in]

Index that specifies the default monitor.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Could not set the specified monitor as the default. |
| **E_INVALIDARG** | Invalid argument; *uDev* does not correspond to a valid monitor. |
| **S_OK** | The method succeeded. |
| **VFW_E_WRONG_STATE** | The allocator-presenter has not been loaded. |

## Remarks

Use this method on a multi-monitor system to specify to the VMR the default Direct3D device to use when connecting to an upstream filter. The default Direct3D device can be overridden for a particular connection by the [SetMonitor](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrmonitorconfig9-setmonitor) method.

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRMonitorConfig9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrmonitorconfig9)

[IVMRMonitorConfig9::GetDefaultMonitor](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrmonitorconfig9-getdefaultmonitor)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)