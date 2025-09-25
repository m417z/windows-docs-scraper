# IVMRMonitorConfig::GetDefaultMonitor

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDefaultMonitor` method retrieves the default monitor that all future instances of the VMR will use for video playback.

## Parameters

### `pGUID` [out]

Pointer to a [VMRGUID](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmrguid) structure that identifies the default monitor on the system.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |
| **VFW_E_WRONG_STATE** | The allocator-presenter has not been loaded. |

## Remarks

Use this method on a multi-monitor system to determine which is the default DirectDraw device the VMR will use when connecting to an upstream filter.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRMonitorConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrmonitorconfig)

[IVMRMonitorConfig::SetDefaultMonitor](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrmonitorconfig-setdefaultmonitor)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)