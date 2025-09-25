# IVMRMonitorConfig9::GetAvailableMonitors

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetAvailableMonitors` method retrieves information about the monitors currently available on the system.

## Parameters

### `pInfo` [out]

Pointer to an array of [VMR9MonitorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9monitorinfo) structures that contain information about each monitor on the system.

### `dwMaxInfoArraySize` [in]

Specifies the maximum number of members in the array.

### `pdwNumDevices` [out]

If *pInfo* is **NULL**, this parameter receives the required array size. Otherwise, it receives the actual number of devices retrieved.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument; *dwMaxInfoArraySize* must be greater than zero. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | The method succeeded. |

## Remarks

Use this method to get a list of Direct Draw device identifiers and their associated monitor information that the mixer can use when connecting to an upstream decoder filter.

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRMonitorConfig9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrmonitorconfig9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)