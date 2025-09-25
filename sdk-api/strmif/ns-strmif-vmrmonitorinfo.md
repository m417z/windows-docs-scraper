# VMRMONITORINFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `VMRMONITORINFO` structure is used in the [IVMRMonitorConfig::GetAvailableMonitors](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrmonitorconfig-getavailablemonitors) method to set and retrieve information about monitors on the system (VMR-7 only).

## Members

### `guid`

A [VMRGUID](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmrguid) structure that specifies the monitor.

### `rcMonitor`

The monitor rectangle.

### `hMon`

A handle to the monitor.

### `dwFlags`

Flags as defined for the [MONITORINFOEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfoexa) structure. Currently the only valid flag is **MONITORINFOF_PRIMARY**, which indicates the primary display monitor.

### `szDevice`

Null-terminated string containing the device name.

### `szDescription`

Null-terminated string containing the device description.

### `liDriverVersion`

### `dwVendorId`

### `dwDeviceId`

### `dwSubSysId`

### `dwRevision`

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)