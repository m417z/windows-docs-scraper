# IDesktopWallpaper::GetMonitorDevicePathCount

## Description

Retrieves the number of monitors that are associated with the system.

## Parameters

### `count` [out]

A pointer to a value that, when this method returns successfully, receives the number of monitors.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code, including the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A **NULL** pointer was provided in *monitorID*. |

## Remarks

The count retrieved through this method includes monitors that are currently detached but that have an image assigned to them. Call [GetMonitorRECT](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getmonitorrect) to distinguish between attached and detached monitors.

## See also

[IDesktopWallpaper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)

[IDesktopWallpaper::GetMonitorDevicePathAt](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idesktopwallpaper-getmonitordevicepathat)