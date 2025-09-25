# IDesktopWallpaper::GetMonitorDevicePathAt

## Description

Retrieves the unique ID of one of the system's monitors.

## Parameters

### `monitorIndex` [in]

The number of the monitor. Call [GetMonitorDevicePathCount](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getmonitordevicepathcount) to determine the total number of monitors.

### `monitorID` [out]

A pointer to the address of a buffer that, when this method returns successfully, receives the monitor's ID.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code, including the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A **NULL** pointer was provided in *monitorID*. |

## Remarks

This method can be called on monitors that are currently detached but that have an image assigned to them. Call [GetMonitorRECT](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getmonitorrect) to distinguish between attached and detached monitors.

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)

[IDesktopWallpaper::GetMonitorDevicePathCount](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getmonitordevicepathcount)