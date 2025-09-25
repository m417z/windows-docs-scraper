# IVMRMonitorConfig::SetMonitor

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

On a multi-monitor system, the `SetMonitor` method specifies the monitor that this instance of the VMR should use for video playback.

## Parameters

### `pGUID` [in]

Pointer to a [VMRGUID](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmrguid) structure that identifies the monitor.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |
| **VFW_E_WRONG_STATE** | The allocator-presenter has not been loaded. |

## Remarks

Use this method on a multi-monitor system to specify to the VMR which DirectDraw driver should be used when connecting to an upstream decoder filter.

The **pGUID** member of the VMRGUID structure must be either **NULL**, indicating the default DirectDraw device, or equal to the address of the **GUID** member of the **VMRGUID** structure. Otherwise, the method returns E_INVALIDARG.

If the specified GUID does not correspond to any monitor, the method return E_INVALIDARG.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRMonitorConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrmonitorconfig)

[IVMRMonitorConfig::GetMonitor](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrmonitorconfig-getmonitor)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)