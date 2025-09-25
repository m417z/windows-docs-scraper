# IDesktopWallpaper::GetMonitorRECT

## Description

Retrieves the display rectangle of the specified monitor.

## Parameters

### `monitorID` [in]

The ID of the monitor to query. You can get this value through [GetMonitorDevicePathAt](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getmonitordevicepathat).

### `displayRect` [out]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that, when this method returns successfully, receives the display rectangle of the monitor specified by *monitorID*, in screen coordinates.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code, including the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The monitor specified by *monitorID* is not currently attached to the system. |
| **E_POINTER** | A **NULL** pointer was provided in *displayRect*. |
| **E_INVALIDARG** | The ID supplied in *monitorID* cannot be found. |

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)